# SSHD 配置

## Win10 OpenSSH 设置公钥免密登录

修改C:\ProgramData\ssh\sshd_config

设置：

```ini
PubkeyAuthentication yes
AuthorizedKeysFile .ssh/authorized_keys
PasswordAuthentication no

# (这是默认值，所以要关闭要设置 yes)会禁止 root 不能使用密码 即使开启了 PasswordAuthentication yes
PermitRootLogin prohibit-password
# 改成 yes 就可以 root 用密码了
PermitRootLogin yes
```

注释：

```ini
#Match Group administrators
#       AuthorizedKeysFile __PROGRAMDATA__/ssh/administrators_authorized_keys
```

添加用户的公钥，C:\Users\用户名\.ssh\authorized_keys
重启sshd服务。
