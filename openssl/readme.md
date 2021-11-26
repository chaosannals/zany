# OpenSSL

```bash
# 生成 myssl.key myssl cert
openssl req -newkey rsa:2048 -nodes -keyout myssl.key -x509 -days 365 -out myssl.cer

# 生成 myssl.pfx
openssl pkcs12 -export -in myssl.cer -inkey myssl.key -out myssl.pfx
```

## Windows SignTool

[官网文档](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/signtool-exe)

```bash
# 必须在 VS 工具集命令行下才能找到
signtool sign /f myssl.pfx /v my.exe

# 带密码的 pfx
signtool sign /f myssl.pfx /p passwd /v my.exe
```