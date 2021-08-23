# SSHD 配置

## Win10 OpenSSH 设置公钥免密登录

修改C:\ProgramData\ssh\sshd_config

设置：

```ini
PubkeyAuthentication yes
AuthorizedKeysFile .ssh/authorized_keys
PasswordAuthentication no
```

注释：

```ini
#Match Group administrators
#       AuthorizedKeysFile __PROGRAMDATA__/ssh/administrators_authorized_keys
```

添加用户的公钥，C:\Users\用户名\.ssh\authorized_keys
重启sshd服务。
