# Gradle

[官网](https://gradle.org) 下载 Gradle 完整版并解压。

注：确保安装了兼容版本的 Java 运行时。

## 配置

设置环境变量

GRADLE_HOME=【解压后的文件夹路径】

例如：

GRADLE_HOME=D:\gradle-7.2

添加 PATH 路径

【解压后的文件夹路径】\bin

PATH = %PATH%;%GRADLE_HOME%\bin

## Gradle 基本命令

```bash
# 执行后根据提示选择创建项目。
gradle init

# 打印全部依赖关系
./gradlew :app:dependencies > log.txt

# 指定依赖查找参数
./gradlew :app:dependencyInsight --dependency fastjson --configuration compile
```
