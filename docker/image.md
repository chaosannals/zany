# 镜像

```bash
# 把容器 container 的内容提交成 author/image:tag 镜像
docker commit container author/image:tag

# 把 author/image:tag 推到 DockerHub（需登录）
docker push author/image:tag

# 在 . 路径下找到 dockerfile 并构建镜像 author/image:tag
docker build -t author/image:tag .

# 清除 <none> 的镜像
docker rmi $(docker images | grep "<none>" | awk '{print $3}')
```

```bash
# 把容器导出成 *.tar 文件。
docker save -o filename.tar image/one [image/two...]

# 把文件里得容器导出。
# --quiet, -q 精简输出信息
docker load -q -i filename.tar
```
