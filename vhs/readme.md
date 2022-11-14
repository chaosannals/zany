# vhs

[vhs GitHub](https://github.com/charmbracelet/vhs)

依赖：
[ffmpeg GitHub](https://github.com/FFmpeg/FFmpeg)
[ttyd GitHub](https://github.com/tsl0922/ttyd)

以上几个都是直接下载后配置 PATH 就可以使用。

## 使用

```bash
# 生成脚本
vhs new demo.tape

# 自己修改 demo.tape 脚本

# 生成 gif
vhs demp.tape
```

```tape
# 手打字的输出
Type "ls -al"

# 回车
Enter

# 停顿 0.5秒
Sleep 0.5

Show

# 其他的查看官方文档。
```