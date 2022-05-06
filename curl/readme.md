# cUrl

## 代理

```bash
curl -x 'http://user:pwd@127.0.0.1:8088' 'http://baidu.com' 
curl -proxy 'http://user:pwd@127.0.0.1:8088' 'http://baidu.com' 
```



```cmd
set http_proxy='http://user:pwd@127.0.0.1:8088'
set https_proxy='http://user:pwd@127.0.0.1:8088'
```

在环境下配置临时全局变量设置代理。

```cmd
set http_proxy='http://127.0.0.1:1088'
set https_proxy='http://127.0.0.1:1088'
```