# OpenSSL

```bash
# 生成 myssl.key myssl cert
openssl req -newkey rsa:2048 -nodes -keyout myssl.key -x509 -days 365 -out myssl.cer

# 生成 myssl.pfx
openssl pkcs12 -export -in myssl.cer -inkey myssl.key -out myssl.pfx
```
