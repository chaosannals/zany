# 清华源

注： 如果修改后访问出现问题，可能是域名解析出了问题。
修改 /etc/resolv.conf 添加域名服务器。

```conf
nameserver 8.8.8.8
nameserver 114.114.114.114
nameserver 8.8.4.4
```

```bash
sudo vim /etc/resolv.conf
```

```bash
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak
sudo sed -i 's#http://security.ubuntu.com#https://mirrors.tuna.tsinghua.edu.cn#g' /etc/apt/sources.list
sudo sed -i 's#http://archive.ubuntu.com#https://mirrors.tuna.tsinghua.edu.cn#g' /etc/apt/sources.list
sudo apt update
sudo apt-get upgrade
```
