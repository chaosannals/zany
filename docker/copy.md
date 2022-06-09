# 复制

```bash
# 路径可以是文件夹

# 从容器复制文件下来
# docker cp <container_id>:<container_path> <host_path>
docker cp nginx_server:/nginx/conf ./conf

# 复制文件到容器上
# docker cp <host_path> <container_id>:<container_path>
docker cp ./conf nginx_server:/nginx/conf
```