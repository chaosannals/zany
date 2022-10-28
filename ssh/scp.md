# scp

```bash
# 本地 /local/path/ 复制到 主机 hostip 的 /host/path/ 目录下
scp -r /local/path/ root@hostip:/host/path/ 

# 本地 /local/path/ 复制到 主机 hostip 的 /host/path/ 目录下
# -i 指定密钥
scp -i ~/yourkey -r /local/path/ root@hostip:/host/path/
```
