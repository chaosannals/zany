# dotnet 命令

## 单文件打包

```bash
# Linux
dotnet publish -r linux-x64 /p:PublishSingleFile=true

# Windows
dotnet publish -r win-x64 --self-contained=false /p:PublishSingleFile=true

## IncludeAllContentInSingleFile 将所有发布的文件（符号文件除外）打包到单文件中。
## IncludeNativeLibrariesInSingleFile 将依赖的本机二进制文件打包到单文件应用程序中。
## IncludeSymbolsInSingleFile 将 .pdb 文件打包到单个文件中。
dotnet publish -r win-x64 --self-contained=false /p:PublishSingleFile=true /p:IncludeNativeLibrariesInSingleFile=true /p:IncludeSymbolsInSingleFile=true /p:IncludeAllContentInSingleFile=true
```
