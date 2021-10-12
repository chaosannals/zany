# build

## 交叉编译

```bash
# 设置环境变量
env GOOS=linux GOARCH=amd64

# 构建
go build -o target
```

注：windows 下要使用 cmd 而不是 pwsh 执行，且set 变量时 && 前面的空格会被弄到变量值里面，所以不能要空格，要紧挨着。
```cmd
set CGO_ENABLED=0&&set GOOS=js&&set GOARCH=wasm&&go build -o game.wasm main.go
```
指定生成 wasm 文件。


```bash
# 查看支持构建的种类
go tool dist list
```
