# wsl2

## 迁移 docker-desktop-data 位置

```sh
# 查看 子系统 确保 docker-desktop 和 docker-desktop-data 必须停止 stoped 状态。
wsl --list -v

# 必须有 D:\Docker 目录
# 导出 docker-desktop-data
wsl --export docker-desktop-data "D:\Docker\docker-desktop-data.tar"

# 注销旧的 docker-desktop-data
wsl --unregister docker-desktop-data

# 重新导入 docker-desktop-data 并指定新路径
# 新路径目录 D:\Docker\data 必须存在。
wsl --import docker-desktop-data "D:\Docker\data" "D:\Docker\docker-desktop-data.tar" --version 2

# 之后启动 docker-desktop 即可。
```
