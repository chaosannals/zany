# docker compose

```bash
# 启动 compose 脚本
# -d 加入这个参数让脚本执行后进入守护进程，不然会阻塞，终止命令容器删除。
docker compose up -d

# 逆 compose up，去掉容器
docker compose down 

# 逆 compose up, 同时把自定义 dockerfile 镜像删除
docker compose down --rmi local

# 逆 compose up, 同时把所有镜像删除
docker compose down --rmi all
```