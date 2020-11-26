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

### Milvus

需要在官网下载配置文件。

```sh
docker run -p 19530:19530 -p 19121:19121 -p 9091:9091 -v /host/milvus/db:/var/lib/milvus/db -v /host/milvus/conf:/var/lib/milvus/conf -v /host/milvus/logs:/var/lib/milvus/logs -v /host/milvus/wal:/var/lib/milvus/wal --restart=always -d --name milvus milvusdb/milvus:cpu-latest
```

### PHP-FPM

```sh
docker run -v /host/www:/www -p 9000:9000 -d --restart=always --name php-fpm php:fpm
```

## Compose

```bash
# 以守护进程模式运行
docker-compose up -d

# 删除
docker-compose rm

# 启动
docker-compose start

# 关闭
docker-compose stop

# 重启
docker-compose restart
```

## stats

```bash
docker stats
```
