# Cygwin

如果不是通过卸载的，比如重装系统后，安装文件夹的安全是多出用户的，导致无法删除。

管理员命令下：
```bat
@rem 管理员获取对该目录的权限 /f <path> 指定路径 /r 递归向下 /d 显示
takeown /f <path/install/dir> /r /d y

@rem 把该目录 /t 包括子目录  /grant 赋权给 everyone 完全权限 F 
icacls <path/install/dir> /t /grant everyone:F

@rem 删除
del <path/install/dir>
```