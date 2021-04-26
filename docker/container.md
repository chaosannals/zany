# 容器

```bash
#!/bin/bash

# 由镜像 image 创建容器 newcontainer 并运行
docker run -itd --name newcontainer image

# 执行命令，让容器（ID 为 hashnumber）打开一个 /bin/bash 的窗口
docker exec -it hashnumber /bin/bash

# 让容器后台运行
docker -d

# 指定环境变量
docker -e USERNAME=xxxxx

# 端口映射 宿主 5000 映射 容器 6000
docker -p 5000:6000

# 路径挂载
docker -v /host/path:/container/path

# 指定运行路径
docker -w /container/path

# 
docker --entrypoint 

# 设置重启为任何
docker --restart=always

# 启动容器
docker start hashorname

# 停止容器
docker stop hashorname

# 杀死容器
docker kill hashorname

# 重启容器
docker restart hashorname

# 限制内存
docker -m 200M
```
