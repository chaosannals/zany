# Crontab

计划任务

- crond 是 crontab 的服务，每次修改都要重启该服务。

```bash
# 编辑计划任务
crontab -e

# 查看计划任务
crontab -l

# 用 systemctl 重启
systemctl restart crond

# 用 service 重启
service crond restart
```

## Crontab 定时任务格式

```bash
# * 代表所有可能值。
# , 列举可能值之间不能有空格，例：1,2,23,56。
# - 范围值，例：2-6 等价于 2,3,4,5,6
# / 可以用来表示值间隔，例如：0-8/2 代表 0 到 23 间隔是 2,等价于 0,2,4,8
# 例 * 分别是 (0-59) 分, (0-23) 时，(1-31)日，(1-12)月，(0-7) (周日为 0 或 7)星期几
# 接下来是 用户名 和 命令
* * * * * username command
```
