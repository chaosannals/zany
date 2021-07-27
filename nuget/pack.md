# 打包

```bash
# 创建描述文件，填写打包内容。
nuget spec

# 打包
nuget pack
```

```xml
<?xml version="1.0" encoding="utf-8"?>
<package >
  <metadata>
    ...
    <!-- 需要选定 files 里面的描述 -->
    <icon>Logo.png</icon>
    ...

    <!-- 查阅 https://docs.microsoft.com/zh-cn/nuget/reference/errors-and-warnings/nu5128 的解决方案 -->
    <!-- 目前测试无法解决警告 NU5128 -->
    <dependencies>
      <group targetFramework=".NETFramework3.5"/>
    </dependencies>
  </metadata>

  <!-- 图标文件需要在这里描述 -->
  <files>
    <file src="Logo.png" target="" />
  </files>
</package>
```

