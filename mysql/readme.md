# MySQL

```sql
/* 删除指定日志文件 */
PURGE MASTER LOGS TO 'mysql-bin.010';

/* 删除指定日期之前 */
PURGE MASTER LOGS BEFORE '2008-12-19 21:00:00';
```
