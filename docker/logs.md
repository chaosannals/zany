# docker logs

```bash
# mycontainer 容器名
# --since 开始时间 可选
# --tail 条数
docker logs --since "2016-06-01" --tail 10 mycontainer

# -f 命令行持续监听
# -t 显示时间错，如果日子自带了，可以不用。
docker logs mycontainer --tail 10 -f -t
```
