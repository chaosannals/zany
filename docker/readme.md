# Docker

## 设置

### daemon.json

#### 网易镜像

```json
{
  "registry-mirrors": [
     "http://hub-mirror.c.163.com"
   ],
  "insecure-registries": [],
  "debug": true,
  "experimental": false
}
```

#### 设置自建仓库去掉安全检测

```json
{
  "registry-mirrors": [],
  "insecure-registries": ["127.0.0.1:5000"],
  "debug": true,
  "experimental": false
}
```

## 容器

### MongoDB

```sh
docker run -p 27017:27017 -v /host/db:/data/db -v /host/configdb:/data/configdb -d --restart=always --name mongodb mongo
```

### Redis

```sh
docker run -p 6379:6379 -v /host/data:/data -d --restart=always --name redis redis
```

### MySQL

```sh
docker run -e MYSQL_ROOT_PASSWORD=password -p 3306:3306 -v /host/var/lib/mysql:/var/lib/mysql -d --restart=always --name mysql mysql
```
