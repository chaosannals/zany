# pip

```bash
# -U 安装最新版本，已安装老版本则升级。
pip install -U numpy

# -i 指定源
pip install -i https://mirrors.aliyun.com/pypi/simple/ numpy
```

## 打包发布

```bash
# 打包
python setup.py sdist bdist_wheel

# 上传
twine upload dist/*
```
