"""
MCP Server - 提供工具服务的服务器端实现
"""
from fastmcp import FastMCP
from typing import Optional
import httpx
import json

# 创建 MCP 服务器实例
mcp = FastMCP("WeatherServer")


@mcp.tool()
def get_weather(city: str, unit: str = "celsius") -> str:
    """
    获取指定城市的天气信息

    Args:
        city: 城市名称，例如"北京"、"上海"、"南昌"
        unit: 温度单位，可选"celsius"(摄氏度)或"fahrenheit"(华氏度)，默认为celsius

    Returns:
        包含城市天气信息的字符串
    """
    # 这里可以接入真实的天气 API
    # 目前返回模拟数据
    weather_data = {
        "北京": {"temp": 25, "condition": "晴朗", "humidity": 45},
        "上海": {"temp": 28, "condition": "多云", "humidity": 65},
        "南昌": {"temp": 30, "condition": "阴天", "humidity": 70},
        "广州": {"temp": 32, "condition": "雷阵雨", "humidity": 80},
        "深圳": {"temp": 31, "condition": "多云", "humidity": 75},
    }

    if city not in weather_data:
        return f"抱歉，没有找到{city}的天气信息。"

    data = weather_data[city]

    # 温度单位转换
    temp = data["temp"]
    if unit.lower() == "fahrenheit":
        temp = temp * 9/5 + 32
        temp_unit = "°F"
    else:
        temp_unit = "°C"

    return f"""
{city}当前天气情况：
- 温度: {temp}{temp_unit}
- 天气: {data['condition']}
- 湿度: {data['humidity']}%
"""


@mcp.tool()
def get_time(city: str) -> str:
    """
    获取指定城市的当前时间

    Args:
        city: 城市名称

    Returns:
        包含城市时间信息的字符串
    """
    from datetime import datetime
    now = datetime.now()
    return f"{city}的当前时间是: {now.strftime('%Y-%m-%d %H:%M:%S')}"


@mcp.tool()
def calculate(expression: str) -> str:
    """
    计算数学表达式

    Args:
        expression: 数学表达式，例如"2+2"、"10*5"、"100/4"

    Returns:
        计算结果
    """
    try:
        # 注意：eval 有安全风险，生产环境应该使用更安全的方式
        result = eval(expression)
        return f"计算结果: {expression} = {result}"
    except Exception as e:
        return f"计算错误: {str(e)}"


@mcp.resource("weather://forecast/{city}")
def get_weather_forecast(city: str) -> str:
    """
    获取城市的天气预报资源

    Args:
        city: 城市名称

    Returns:
        天气预报信息
    """
    return f"""
{city}未来三天天气预报：
- 明天: 多云，温度 20-28°C
- 后天: 晴朗，温度 22-30°C
- 大后天: 小雨，温度 18-25°C
"""


if __name__ == "__main__":
    # 运行 MCP 服务器
    mcp.run()
