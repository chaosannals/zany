# Firewalld 防火墙

```bash
# 启动
systemctl start firewalld

# 默认情况下firewalld会禁止转发流量。
# 查看转发，默认 no；开启 yes
firewall-cmd --query-masquerade

# 永久开启 IP 地址转发
firewall-cmd --add-masquerade --permanent

# 重启防火墙
firewall-cmd --reload
```
