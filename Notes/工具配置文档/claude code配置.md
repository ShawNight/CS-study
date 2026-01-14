**下文是Windows版本：**

## 📋 背景说明

Claude Code 原本需要付费使用，但通过 Claude Code Router (CCR) 配合星云研发大模型 Lite V7.0，我们可以实现免费的使用体验。

## 📦 安装步骤

### 安装 Claude Code 和 Claude Code Router（具体步骤自行上网搜索）

**要求：****安装 **[**Node.js**](https://zhida.zhihu.com/search?content_id=261036242&content_type=Article&match_order=1&q=Node.js&zd_token=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJ6aGlkYV9zZXJ2ZXIiLCJleHAiOjE3NTU4NTE5MDMsInEiOiJOb2RlLmpzIiwiemhpZGFfc291cmNlIjoiZW50aXR5IiwiY29udGVudF9pZCI6MjYxMDM2MjQyLCJjb250ZW50X3R5cGUiOiJBcnRpY2xlIiwibWF0Y2hfb3JkZXIiOjEsInpkX3Rva2VuIjpudWxsfQ.6aIWm5DN1iLr4pc6n7yDq67UEoi-aBApcgEWP5SBGP8&zhida_source=entity)**（≥18.0）**

# 安装 Claude Code

npm install -g @anthropic-ai/claude-code

# 安装 Claude Code Router

npm install -g @musistudio/claude-code-router

Claude Code Router参考链接：[https://github.com/musistudio/claude-code-router/blob/main/README\_zh.md](https://github.com/musistudio/claude-code-router/blob/main/README_zh.md)


配置文件在.claude下新增settings.json文件

```json
{
    "env": {
        "ANTHROPIC_AUTH_TOKEN": "c22046e557414b7dbbf9aa5be8973e12.5vhK1aM7vrSRNnlh",
        "ANTHROPIC_BASE_URL": "https://open.bigmodel.cn/api/anthropic",
        "API_TIMEOUT_MS": "3000000",
        "CLAUDE_CODE_DISABLE_NONESSENTIAL_TRAFFIC": "1",
        "HTTP_PROXY": "http://proxy.zte.com.cn:80",
        "HTTPS_PROXY": "http://proxy.zte.com.cn:80"
    }
}
```
