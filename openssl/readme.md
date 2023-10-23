# OpenSSL

```bash
# PKCS #8 Unencrypted Private Key
# -----BEGIN PRIVATE KEY-----

# PKCS #8 Encrypted Private Key
# -----BEGIN ENCRYPTED PRIVATE KEY-----

# PKCS #1 Private Key
# -----BEGIN RSA PRIVATE KEY-----

# PKCS #1 Public Key
# -----BEGIN RSA PUBLIC KEY-----

# 生成 myssl.key myssl cert
# .key 是 -----BEGIN PRIVATE KEY----- 
# .pem 是 -----BEGIN RSA PRIVATE KEY----- 
# .cer 是 -----BEGIN CERTIFICATE-----
openssl req -newkey rsa:2048 -nodes -keyout myssl.key -x509 -days 365 -out myssl.cer

# 生成 myssl.pfx 二进制
openssl pkcs12 -export -in myssl.cer -inkey myssl.key -out myssl.pfx

# 生成 myssl.pfx 不指定证书
openssl pkcs12 -export -nocerts -inkey myssl.key -out myssl.pfx

# x509rsa 转 pkcs8 二进制
# .pem 是 -----BEGIN RSA PRIVATE KEY----- 
openssl pkcs8 -topk8 -inform PEM -outform DER -in myssl.pem -out myssl.der -nocrypt

# 把 pkcs8 转成 文本形式
# 输出物 -----BEGIN PRIVATE KEY----- 
openssl pkcs8 -topk8 -inform DER -outform PEM -in myssl.der -out myssl.key --nocrypt
```

## OpenSSH

[转换工具 PuttyGen](https://www.puttygen.com/download-putty)

```bash
# 新版本 ssh-keygen 不指定类型生成 OPENSSH PRIVATE KEY
ssh-keygen

# 通过指定类型 RSA 得到老版本的 RSA PRIVATE KEY
ssh-keygen -m PEM -t rsa

# 转换 OPENSSH PRIVATE KEY 为 RSA PRIVATE KEY 这时候文件 myossh.pem 会被直接替换，如果要老文件需要自行保存。
ssh-keygen -p -f myossh.pem -m PEM
```

## Windows SignTool

[官网文档](https://docs.microsoft.com/zh-cn/dotnet/framework/tools/signtool-exe)

```bash
# 必须在 VS 工具集命令行下才能找到
signtool sign /f myssl.pfx /v my.exe

# 带密码的 pfx
signtool sign /f myssl.pfx /p passwd /v my.exe
```


## Linux 或 Windows (WSL) 转 PPK

```bash
# 安装工具 rpm
yum install putty
# 安装工具 dpkg
apt install putty-tools

# 转换
puttygen id_rsa -o id_rsa.ppk -O private
```


注：linux 的证书最好由 root 只读，不同用户通过向 root 运行的证书管理程序注册复制路径，由 root 的证书程序在证书创建和更新的时候把证书复制给使用证书的程序。
