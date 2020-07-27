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
docker run -p 6379:6379 -v /host/redis/data:/data -v /host/redis/config:/etc/redis -v /host/redis/module:/mod -d --restart=always --name redis redis redis-server /etc/redis/redis.conf
```

### MySQL

还可以挂载配置文件路径，需要自己预先弄。

```sh
docker run -e MYSQL_ROOT_PASSWORD=password -p 3306:3306 -v /host/var/lib/mysql:/var/lib/mysql -d --restart=always --name mysql mysql
```

### ElasticSearch

```sh
docker run -p 9200:9200 -p 9300:9300 -v /host/elasticsearch:/usr/share/elasticsearch/data -e "discovery.type=single-node" -d --restart=always --name elasticsearch elasticsearch
```

### Milvus

需要在官网下载配置文件。

```sh
docker run -p 19530:19530 -p 19121:19121 -p 9091:9091 -v /host/milvus/db:/var/lib/milvus/db -v /host/milvus/conf:/var/lib/milvus/conf -v /host/milvus/logs:/var/lib/milvus/logs -v /host/milvus/wal:/var/lib/milvus/wal --restart=always --name milvus milvusdb/milvus:cpu-latest
```

### PHP-FPM

```sh
docker run -v /host/www:/www -p 9000:9000 -d --restart=always --name php-fpm php:fpm
```

