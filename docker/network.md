# network 命令

```bash

# 创建网络
docker network create mynet

# 创建桥接网络
docker network create -d bridge mynet

# 指定网段（可能被占用）
docker network create --subnet=172.18.0.0/16 mynet

# 查看网络列表
docker network ls

# 查看网络信息
docker network inspect mynet

# 可以连接网络
docker network connect --alias networkalias mynet container

# 连接网络指定 IP (只能是用户定义的网络且指定了网段(subnet)才能指定 IP)
docker network connect --ip 172.18.0.4 mynet container

# 删除网络
docker network rm mynet

# 也可以在创建容器时，用 network 参数选中网络，network-alias 来定义域名，可以 ping networkname 通。
docker run --network mynet --network-alias networkalias
```

## 防火墙

如果无法访问外网，查看 Firewalld 目录，IP 转发。
开启 IP 转发后就可以访问外网。
