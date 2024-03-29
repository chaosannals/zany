# Docker 仓库

```bash
#!/bin/bash

docker pull registry

######### ① START 配置文件在宿主机，【与②选一】

# 如果宿主没有 htpasswd 看下一条。
htpasswd -Bb -c /host/pass/path user pass

# 如果宿主没有 htpasswd 可以通过下面的命令由容器执行。用完记得删除临时生成的容器。
docker run --entrypoint htpasswd registry:latest -Bbn user pass >/host/pass/path

# 使用 docker 参数传入环境变量信息。
docker run -d -e "REGISTRY_AUTH=htpasswd" -e "REGISTRY_AUTH_HTPASSWD_REALM=Registry Realm" -e "REGISTRY_AUTH_HTPASSWD_PATH=/pass/path" -v /host/pass/path:/pass/path -p 5000:5000 --restart=always --name registry registry:latest

######### ① END

######### ② START 这一步配置文件在容器里。【与①选一】
docker run -d -p 5000:5000 --restart=always --name registry registry:latest

# 创建用户密码
docker exec container htpasswd -Bb -c /pass/path user pass

# 修改容器 profile 添加环境变量
# export REGISTRY_AUTH=htpasswd
# export REGISTRY_AUTH_HTPASSWD_REALM="Registry Realm"
# export REGISTRY_AUTH_HTPASSWD_PATH=/pass/path

######### ② END

# 登录到私有仓库
docker login 127.0.0.1:5000

# 给项目打个标签
docker tag imghash 127.0.0.1:5000/anthor/name:tag

# 推送
docker push 127.0.0.1:5000/anthor/name:tag

# 拉取
docker pull 127.0.0.1:5000/anthor/name:tag
```
