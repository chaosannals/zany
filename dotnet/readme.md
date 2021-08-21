# dotnet 命令

## 单文件打包

```bash
# Linux
dotnet publish -r linux-x64 /p:PublishSingleFile=true

# Windows
dotnet publish -r win-x64 --self-contained=false /p:PublishSingleFile=true
```
