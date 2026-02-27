# MCP (Model Context Protocol) 使用文档

## 目录

1. [简介](#简介)
2. [环境准备](#环境准备)
3. [项目结构](#项目结构)
4. [快速开始](#快速开始)
5. [代码说明](#代码说明)
6. [自定义开发](#自定义开发)
7. [常见问题](#常见问题)

---

## 简介

MCP (Model Context Protocol) 是一个用于连接 AI 模型与外部工具和资源的协议。本项目展示了如何使用 FastMCP 框架构建 MCP 服务器和客户端。

### 主要特点

- **工具调用**: AI 模型可以调用外部工具完成特定任务
- **资源访问**: 提供对静态和动态资源的访问
- **标准化接口**: 使用 OpenAI 兼容的工具格式
- **异步支持**: 完全异步的实现，提高性能

---

## 环境准备

### 1. 安装 Python

确保已安装 Python 3.8 或更高版本：

```bash
python --version
```

### 2. 安装依赖

创建虚拟环境并安装所需依赖：

```bash
# 创建虚拟环境
python -m venv venv

# 激活虚拟环境
# Linux/Mac:
source venv/bin/activate
# Windows:
# venv\Scripts\activate

# 安装依赖
pip install fastmcp openai httpx
```

### 3. 配置 API Key

编辑 `client.py` 文件，替换以下配置：

```python
API_KEY = "your-api-key-here"  # 替换为你的智谱 AI API Key
BASE_URL = "https://open.bigmodel.cn/api/paas/v4/"
MODEL_NAME = "glm-4.7"
```

---

## 项目结构

```
MCP使用笔记/
├── server.py          # MCP 服务器实现
├── client.py          # MCP 客户端实现
├── app.py             # 原始合并版本（仅供参考）
└── MCP使用文档.md      # 本文档
```

---

## 快速开始

### 步骤 1: 启动 MCP 服务器

在一个终端窗口中运行：

```bash
python server.py
```

服务器将启动并等待客户端连接。

### 步骤 2: 启动 MCP 客户端

在另一个终端窗口中运行：

```bash
python client.py
```

### 步骤 3: 开始对话

客户端启动后，你可以输入问题，例如：

```
User: 南昌今天天气怎么样？
AI: 南昌当前天气情况：
- 温度: 30°C
- 天气: 阴天
- 湿度: 70%

User: 帮我计算 25 * 4
AI: 计算结果: 25 * 4 = 100

User: 北京现在几点了？
AI: 北京的当前时间是: 2025-01-15 14:30:25
```

输入 `quit` 或 `exit` 退出程序。

---

## 代码说明

### server.py - MCP 服务器

服务器端提供三个主要工具：

#### 1. get_weather - 获取天气信息

```python
@mcp.tool()
def get_weather(city: str, unit: str = "celsius") -> str:
    """
    获取指定城市的天气信息

    Args:
        city: 城市名称
        unit: 温度单位 (celsius/fahrenheit)
    """
    # 实现...
```

**使用示例**:
- "北京今天天气怎么样？"
- "上海的温度是多少华氏度？"

#### 2. get_time - 获取当前时间

```python
@mcp.tool()
def get_time(city: str) -> str:
    """获取指定城市的当前时间"""
    # 实现...
```

**使用示例**:
- "广州现在几点了？"

#### 3. calculate - 数学计算

```python
@mcp.tool()
def calculate(expression: str) -> str:
    """计算数学表达式"""
    # 实现...
```

**使用示例**:
- "帮我计算 100 除以 5"
- "算一下 25 乘以 4"

### client.py - MCP 客户端

客户端主要功能：

#### UserClient 类

```python
class UserClient:
    def __init__(self, script: str = "server.py"):
        # 初始化 MCP 客户端和 OpenAI 客户端
```

**主要方法**:

1. **prepare_tools()** - 从服务器获取工具列表
2. **chat(message)** - 与 AI 模型对话
3. **loop()** - 交互式对话循环

---

## 自定义开发

### 添加新工具

在 `server.py` 中添加新工具：

```python
@mcp.tool()
def my_new_tool(param1: str, param2: int = 10) -> str:
    """
    工具描述（AI 会看到这个描述）

    Args:
        param1: 参数1的说明
        param2: 参数2的说明
    """
    # 你的实现
    return f"结果: {param1} - {param2}"
```

### 添加资源

在 `server.py` 中添加资源：

```python
@mcp.resource("myapp://data/{id}")
def get_resource(id: str) -> str:
    """提供数据资源"""
    return f"Resource data for {id}"
```

### 自定义客户端

修改 `client.py` 以使用不同的模型或配置：

```python
# 使用其他 OpenAI 兼容的模型
API_KEY = "your-api-key"
BASE_URL = "https://api.openai.com/v1"
MODEL_NAME = "gpt-4"
```

---

## 常见问题

### Q1: 客户端连接失败怎么办？

**A**: 确保：
1. MCP 服务器已启动
2. `server.py` 路径正确
3. 防火墙未阻止本地连接

### Q2: 工具调用返回错误？

**A**: 检查：
1. 工具名称拼写正确
2. 参数类型匹配
3. 查看服务器端日志

### Q3: 如何调试工具调用？

**A**: 在服务器端添加日志：

```python
@mcp.tool()
def my_tool(param: str) -> str:
    print(f"[DEBUG] my_tool called with: {param}")
    # 实现...
```

### Q4: 支持哪些 AI 模型？

**A**: 支持所有 OpenAI 兼容的 API：
- 智谱 AI (GLM-4)
- OpenAI (GPT-4, GPT-3.5)
- Azure OpenAI
- 其他兼容接口

### Q5: 如何部署到生产环境？

**A**:
1. 使用环境变量存储敏感信息
2. 添加错误处理和日志记录
3. 使用进程管理器（如 supervisor）
4. 考虑使用 Docker 容器化部署

---

## 高级用法

### 1. 流式响应

修改客户端以支持流式响应：

```python
async def chat_stream(self, message: Dict):
    response = self.openai_client.chat.completions.create(
        model=MODEL_NAME,
        messages=self.messages,
        tools=self.tools,
        stream=True
    )
    async for chunk in response:
        if chunk.choices[0].delta.content:
            print(chunk.choices[0].delta.content, end="")
```

### 2. 并发工具调用

支持同时调用多个工具：

```python
# 并行执行所有工具调用
tasks = [
    self.mcp_client.call_tool(tc.function.name, json.loads(tc.function.arguments))
    for tc in tool_calls
]
results = await asyncio.gather(*tasks)
```

### 3. 工具链

实现工具之间的依赖关系：

```python
@mcp.tool()
def tool_a() -> str:
    return "data from tool a"

@mcp.tool()
def tool_b(input_data: str) -> str:
    return f"processed: {input_data}"
```

---

## 参考资料

- [FastMCP 官方文档](https://github.com/jlowin/fastmcp)
- [MCP 协议规范](https://modelcontextprotocol.io/)
- [OpenAI API 文档](https://platform.openai.com/docs/api-reference)
- [智谱 AI 开放平台](https://open.bigmodel.cn/)

---

## 许可证

本项目仅供学习和参考使用。

---

## 更新日志

### v1.0.0 (2025-01-15)
- 初始版本
- 实现基础的 MCP 服务器和客户端
- 提供天气、时间、计算三个示例工具
- 支持智谱 AI GLM-4 模型
