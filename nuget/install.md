# install

## 添加离线的 *.nupkg 包

使用 GUI 界面先添加资源文件夹，再像正常流程添加。

注： 一下 命令行 流程有问题。

```bash
# 通过 add 命令设置一个本地的源
# path_nupkg 离线包的路径，使用全路径。
# source_folder 离线包将被解压进这个目录，用于安装。
# -Expand 会生成 lib 文件夹 带 DLL
nuget add <path_nupkg> -Source <source_folder> -Expand

# 通过 install 命令指定离线源进行安装
# source_folder 就是 add 添加的离线源，必须全路径。
# pkg_name 包名
nuget install <pkg_name> -Source <source_folder>
```
