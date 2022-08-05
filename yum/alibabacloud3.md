# Alibaba Clound 3

```bash
# EPEL
# REMI
# alibaba cloud 3 只能装低版本的 7 ，8 以上不能装
yum install https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
yum install http://rpms.remirepo.net/enterprise/remi-release-7.rpm
```

```bash
# php 7.3
yum install php73 php73-php-fpm
yum install php73-php-mysql php73-php-gd php73-php-mbstring php73-php-xml php73-php-pdo

# php 7.1
yum install php71 php71-php-fpm
yum install php71-php-mysql php71-php-gd php71-php-mbstring php71-php-xml php71-php-pdo

# php 7.0
yum install php70 php70-php-fpm
yum install php70-php-mysql php70-php-gd php70-php-mbstring php70-php-xml php70-php-pdo
```

remi 都安装在 /opt/remi

```bash
# 执行 php-fpm  配置文件需要自备。
/opt/remi/php73/root/sbin/php-fpm --fpm-config /opt/remi/php73/root/etc/php-fpm.conf
/opt/remi/php71/root/sbin/php-fpm --fpm-config /opt/remi/php71/root/etc/php-fpm.conf
/opt/remi/php70/root/sbin/php-fpm --fpm-config /opt/remi/php70/root/etc/php-fpm.conf
```

```bash
# 下载 composer
cd /opt/remi/php73/root/usr/bin
wget https://getcomposer.org/download/1.10.26/composer.phar

# 脚本 使用下面内容使用 composer 
vi /usr/bin/composer73
# 需要修改权限
chmod 755 /usr/bin/composer73

# 可以修改源
composer73 config -g repo.packagist composer https://packagist.phpcomposer.com
```

注：composer 的脚本 composer73
```bash
#!/bin/bash
# composer73
export PATH=$PATH:/opt/remi/php73/root/usr/bin
php /opt/remi/php73/root/usr/bin/composer.phar $*
```