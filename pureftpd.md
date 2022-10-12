# pureftpd

```bash
# 显示 help
pure-pw --help

# pure-pw 有些没有加到 PATH 里面，所以直接到安装路径下去执行。
# ftpuser 通过 cat /etc/passwd 对应
# pureftpd 通过查看配置 SyslogFacility 指定 /etc/passwd 里面的
# 添加用户 user1  
# 指定路径 -d /var/www/site1  系统的 user1 要有访问权限
pure-pw useradd user1 -u ftpuser -g ftpgroup -d /var/www/site1

# 修改密码
pure-pw passwd user1

# 刷新用户数据。
pure-pw mkdb

# 显示用户列表
pure-pw list

# 显示用户
pure-pw show
```