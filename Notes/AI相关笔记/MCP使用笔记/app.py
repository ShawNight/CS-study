import asyncio
from openai import OpenAI
from fastmcp import Client
import httpx
from typing import List, Dict
import json

api_key = "c22046e557414b7dbbf9aa5be8973e12.5vhK1aM7vrSRNnlh"
base_url = "https://open.bigmodel.cn/api/paas/v4/"
model_name = "glm-4.7"



class UserClient:

    def __init__(self, script = "server.py"):
        self.mcp_client = Client(script)
        self.openai_client = OpenAI(
            api_key=api_key,
            base_url=base_url,
            http_client=httpx.Client(proxy="http://proxyhk.zte.com.cn:80", verify=False)
        )
        self.messages = [
            {
                "role": "system",
                "content": "你是一个智能、友好、有帮助的AI助手，你需要通过调用工具来完成任务。"
            }
        ]
        self.tools = []

    async def prepare_tools(self):
        tools = await self.mcp_client.list_tools()
        tools = [
            {
                "type": "function",
                "function": {
                    "name": tool.name,
                    "description": tool.description,
                    "input_schema": tool.inputSchema,
                }
            }
            for tool in tools
        ]
        return tools

    async def chat(self, message: Dict):
        if not self.tools:
            self.tools = await self.prepare_tools()
        self.messages.append(message)
        response = self.openai_client.chat.completions.create(
            model=model_name,
            messages=self.messages,
            tools=self.tools,
        )
        if response.choices[0].finish_reason != "tool_calls":
            return response.choices[0].message
        #执行工具
        for tool_call in response.choices[0].message.tool_calls:
            response = await self.mcp_client.call_tool(
                tool_call.function.name, 
                json.loads(tool_call.function.arguments)
            )
            message ={
                "role": "tool",
                "content": response.content[0].text,
            }
            return await self.chat(message)

    async def loop(self):
        async with self.mcp_client:
            while True:
                question = input("User: ")
                message = {
                    "role": "user",
                    "content": question
                }
                response = await self.chat(message)
                print("AI:", response.content)

async def main():
    user_client = UserClient()
    # response = await user_client.chat(
    #     {"role": "user", "content": "南昌今天天气怎么样？"}
    # )
    # print(response.content)
    await user_client.loop()

if __name__ == "__main__":
    asyncio.run(main())