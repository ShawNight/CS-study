"""
MCP Client - 连接到 MCP 服务器并使用工具的客户端实现
"""
import asyncio
from openai import OpenAI
from fastmcp import Client
import httpx
from typing import List, Dict
import json

# 配置信息
API_KEY = "c22046e557414b7dbbf9aa5be8973e12.5vhK1aM7vrSRNnlh"  # 替换为你的 API Key
BASE_URL = "https://open.bigmodel.cn/api/paas/v4/"  # 智谱 AI API 地址
MODEL_NAME = "glm-4.7"  # 模型名称


class UserClient:
    """MCP 客户端类，用于连接 MCP 服务器并与 AI 模型交互"""

    def __init__(self, script: str = "server.py"):
        """
        初始化客户端

        Args:
            script: MCP 服务器脚本路径，默认为 "server.py"
        """
        self.mcp_client = Client(script)
        self.openai_client = OpenAI(
            api_key=API_KEY,
            base_url=BASE_URL,
            # http_client=httpx.Client(trust_env=False),
            http_client=httpx.Client(proxy="http://proxyhk.zte.com.cn:80", verify=False)
        )
        self.messages = [
            {
                "role": "system",
                "content": "你是一个智能、友好、有帮助的AI助手，你需要通过调用工具来完成任务。"
            }
        ]
        self.tools = []

    async def prepare_tools(self) -> List[Dict]:
        """
        准备工具列表，从 MCP 服务器获取可用工具并转换为 OpenAI 格式

        Returns:
            工具列表
        """
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

    async def chat(self, message: Dict) -> Dict:
        """
        与 AI 模型进行对话

        Args:
            message: 用户消息，格式为 {"role": "user", "content": "问题内容"}

        Returns:
            AI 响应消息
        """
        if not self.tools:
            print("[DEBUG] 正在准备工具列表...")
            self.tools = await self.prepare_tools()
            print(f"[DEBUG] 已加载 {len(self.tools)} 个工具")

        self.messages.append(message)
        print(f"[DEBUG] 发送消息到 AI 模型: {message['content']}")

        try:
            response = self.openai_client.chat.completions.create(
                model=MODEL_NAME,
                messages=self.messages,
                tools=self.tools,
            )
            print(f"[DEBUG] AI 响应完成原因: {response.choices[0].finish_reason}")
        except Exception as e:
            print(f"[ERROR] AI API 调用失败: {str(e)}")
            raise

        # 如果模型不需要调用工具，直接返回响应
        if response.choices[0].finish_reason != "tool_calls":
            return response.choices[0].message

        # 执行工具调用
        print(f"[DEBUG] 需要调用工具...")
        for tool_call in response.choices[0].message.tool_calls:
            print(f"[DEBUG] 调用工具: {tool_call.function.name}")
            print(f"[DEBUG] 工具参数: {tool_call.function.arguments}")

            try:
                # 调用 MCP 服务器的工具
                response = await self.mcp_client.call_tool(
                    tool_call.function.name,
                    json.loads(tool_call.function.arguments)
                )

                tool_result = response.content[0].text if response.content else "Tool executed"
                print(f"[DEBUG] 工具返回结果: {tool_result}")

                # 将工具调用结果添加到消息历史
                tool_message = {
                    "role": "tool",
                    "tool_call_id": tool_call.id,
                    "content": tool_result,
                }
                self.messages.append(tool_message)
            except Exception as e:
                print(f"[ERROR] 工具调用失败: {str(e)}")
                tool_message = {
                    "role": "tool",
                    "tool_call_id": tool_call.id,
                    "content": f"Error: {str(e)}",
                }
                self.messages.append(tool_message)

        # 递归调用，获取最终响应
        print(f"[DEBUG] 获取 AI 最终响应...")
        final_response = self.openai_client.chat.completions.create(
            model=MODEL_NAME,
            messages=self.messages,
            tools=self.tools,
        )

        return final_response.choices[0].message

    async def loop(self):
        """
        交互式对话循环
        """
        async with self.mcp_client:
            print("MCP 客户端已启动！输入 'quit' 或 'exit' 退出。")
            while True:
                try:
                    question = input("\nUser: ")
                    if question.lower() in ['quit', 'exit', '退出']:
                        print("再见！")
                        break

                    message = {
                        "role": "user",
                        "content": question
                    }
                    response = await self.chat(message)
                    print(f"\nAI: {response.content}")
                except KeyboardInterrupt:
                    print("\n\n再见！")
                    break
                except Exception as e:
                    print(f"\n错误: {str(e)}")


async def main():
    """主函数"""
    user_client = UserClient()
    await user_client.loop()


async def test_single_query():
    """
    测试单个查询
    """
    user_client = UserClient()
    async with user_client.mcp_client:
        response = await user_client.chat(
            {"role": "user", "content": "南昌今天天气怎么样？"}
        )
        print(response.content)


if __name__ == "__main__":
    # 运行交互式对话
    # asyncio.run(main())

    # 或者运行单个测试查询
    asyncio.run(test_single_query())
