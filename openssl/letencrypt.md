# Let Encrypt

## Nginx 自动证书

```bash
# 安装 nginx
apt install nginx

# 安装证书机器人程序
apt install certbot

# 安装 certbox nginx python3 插件
apt install python3-certbot-nginx
# 早些系统版本是 python2 的使用这个
apt install python-certbot-nginx

# 测试 nginx 配置 后 重启 nginx
nginx -t && nginx -s reload

# 生成证书
certbot --nginx -d example.com -d www.example.com

# 打开 certbot 配置
certbot -e

# 上面的命令会通过编辑器打开 配置文件
# 输入以下内容配置 certbot 定期 renew 证书
0 12 * * * /usr/bin/certbot renew --quiet
```
