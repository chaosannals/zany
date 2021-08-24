# dotnet 命令

## 单文件打包

```bash
# --self-contained 随应用程序一起发布 .NET 运行时，这样就不需要在目标计算机上安装运行时。

# Linux
dotnet publish -r linux-x64 --self-contained=true /p:PublishSingleFile=true

# 指定路径 -o <path>
dotnet publish -o ./publish -r linux-x64 --self-contained=true /p:PublishSingleFile=true

# Windows
dotnet publish -r win-x64 --self-contained=false /p:PublishSingleFile=true

## IncludeAllContentInSingleFile 将所有发布的文件（符号文件除外）打包到单文件中。
## IncludeNativeLibrariesInSingleFile 将依赖的本机二进制文件打包到单文件应用程序中。
## IncludeSymbolsInSingleFile 将 .pdb 文件打包到单个文件中。
dotnet publish -r win-x64 --self-contained=false /p:PublishSingleFile=true /p:IncludeNativeLibrariesInSingleFile=true /p:IncludeSymbolsInSingleFile=true /p:IncludeAllContentInSingleFile=true
```

## 在 csproj 文件里面以配置的形式设置。

评：这个基本没啥用，除非部署平台和开发平台一致，方便一点。不然命令定制更精确，而且交叉编译这个不能多设置，调来调去还麻烦。

```xml
<PropertyGroup>
  <TargetFramework>net5.0</TargetFramework>
  <RuntimeIdentifier>linux-x64</RuntimeIdentifier>
  <PublishSingleFile>true</PublishSingleFile>
  <IncludeNativeLibrariesInSingleFile>true</IncludeNativeLibrariesInSingleFile>
  <IncludeContentInSingleFile>true</IncludeContentInSingleFile>
</PropertyGroup>
```