# pacman

```bash
# 同步源并更新系统
pacman -Syu

# 安装 gcc
pacman -Sy gcc

# 查看已安装
pacman -Q

# 查看是否已经安装 zlib
pacman -Q zlib

# 查看 zlib 详细信息
pacman -Qi zlib
```

```bash
# 安装工具链
pacman -S mingw-w64-x86_64-toolchain
pacman -S make
```