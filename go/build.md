# build

## 交叉编译

```bash
# 设置环境变量
env GOOS=linux GOARCH=amd64

# 构建
go build -o target
```

```bash
# 查看支持构建的种类
go tool dist list
```
