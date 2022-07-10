# ubuntu

```bash
# 查看宿主 IP  nameserver
cat /etc/resolv.conf

# 查看IP 
hostname -I
```

Windows Defender 入站规则（管理员身份）

```pwsh
New-NetFirewallRule -DisplayName "WSL" -Direction Inbound  -InterfaceAlias "vEthernet (WSL)"  -Action Allow
```

```bash
# 备份
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak

# 还原
sudo cp /etc/apt/sources.list.bak /etc/apt/sources.list
```

```bash
sudo apt-get update # 更新源
sudo apt-get install package # 安装包
sudo apt-get remove package # 删除包
sudo apt-cache search package # 搜索软件包
sudo apt-cache show package  # 获取包的相关信息，如说明、大小、版本等
sudo apt-get install package --reinstall  # 重新安装包
sudo apt-get -f install  # 修复安装
sudo apt-get remove package --purge # 删除包，包括配置文件等
sudo apt-get build-dep package # 安装相关的编译环境
sudo apt-get upgrade # 更新已安装的包
sudo apt-get dist-upgrade # 升级系统
sudo apt-cache depends package # 了解使用该包依赖那些包
sudo apt-cache rdepends package #  查看该包被哪些包依赖
sudo apt-get source package # 下载该包的源代码
sudo apt-get clean && sudo apt-get autoclean # 清理无用的包
sudo apt-get check # 检查是否有损坏的依赖
```

## cmake

```bash
wget https://github.com/Kitware/CMake/releases/download/v3.22.5/cmake-3.22.5-linux-x86_64.sh
./cmake-3.22.5-linux-x86_64.sh
sudo ln -s ~/cmake-3.22.5-linux-x86_64/bin/cmake /usr/bin/cmake

# ninja 下载解压后
chmod 777 ninja
sudo ln -s ~/ninja /usr/bin/ninja
```
