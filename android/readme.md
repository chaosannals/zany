# 安卓

## 生成密钥

```sh
# 需要 Java JDK
# [alias] 为别名
# [test] 为文件名
keytool -genkey -alias [alias] -keyalg RSA -keysize 2048 -validity 36500 -keystore [test].keystore
```
