# Hysteria

```bash
# useradd -s /usr/sbin/nologin -u 4444 hysteria 或生成用户
useradd -s /bin/false -u 4444 hysteria

# server 目录放到 /hysteria 目录下可执行
chmod u+x /hysteria/hysteria

#服务文件 hysteria.service 丢到 /etc/systemd/system/ 目录下
# hysteria.service 应该是 LF 换行，不能是 CRLF 的。
systemctl enable hysteria

# 重启
systemctl restart hysteria

```

注：自行下载 hysteria 二进制文件

注：需要证书，cert 和 key 必填或者配置 acme

注：可以通过配置 acme 在 root 下执行的方式获取证书，在 /root/.local/cert.. 里面不然 hysteria 要给添加 443 80 的权限用来使用 acme 注册证书。

注：证书也可以通过 certbot 自动注册的，fullchain.pem 和 privkey.pem 文件。

注：不适用 root 的服务无法读取证书，需要复制文件。需要证书分发复制的程序。使用 root 做服务的用户简单但不安全。


## 问题排查

```bash
# 查看日志大小
journalctl --disk-usage

# 日志落盘，不然清理可能清理不到
journalctl --rotate


# 清掉一小时前的日志
journalctl --vacuum-time=1h -u hysteria

# 清掉一秒前日志
journalctl --vacuum-time=1s -u hysteria

# 重启日志服务
systemctl restart systemd-journald

# 看日志
journalctl -u hysteria
```
