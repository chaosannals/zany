# gcc scl

可以在需要时候切换 gcc 版本。

```bash
yum install centos-release-scl scl-utils-build

# 7.xx
yum install -y devtoolset-7-toolchain
# 8.x
yum install -y devtoolset-8-toolchain
# 
yum install -y devtoolset-6-toolchain

# 切换版本，关闭 ssh 就会回到最初版本
scl enable devtoolset-7 bash

```
