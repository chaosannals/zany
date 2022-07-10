# 阿里源

[阿里源](https://developer.aliyun.com/mirror/)
[阿里源 ubuntu](https://developer.aliyun.com/mirror/ubuntu)

```bash
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak
sudo sed -i 's/security.ubuntu/mirrors.aliyun/g' /etc/apt/sources.list
sudo sed -i 's/archive.ubuntu/mirrors.aliyun/g' /etc/apt/sources.list
sudo apt update
# //更新已安装的包到最新，这个是可选的
sudo apt-get upgrade
```
