# 内网穿透

```bash

# 正向代理

# 把本地端口转发到主机端口。
# -N 不登陆
# localport 本地端口
# hostip 线上绑定的IP 比如 127.0.0.1
# hostport 线上端口
# -i keypass 密钥
ssh -N -L localport:hostip:hostport root@host.com -i keypass



# 反向代理

# 主机端口接收转发到本地端口。
# -N 不登陆
# localport 本地端口
# hostip 线上绑定的IP 比如 127.0.0.1
# hostport 线上端口
# -i keypass 密钥
ssh -N -R hostport:hostip:localport root@host.com -i keypass


# socks5
# 启动 socks5 代理
ssh -N -D :1080 root@host.com -i keypass
```