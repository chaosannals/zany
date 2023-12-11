# [Huggingface](https://huggingface.co)

因为墙 需要使用 huggingface_hub 设置镜像

```bat
@rem 安装
pip install -U huggingface_hub

@rem 设置镜像
$env:HF_ENDPOINT="https://hf-mirror.com"

@rem 下载到指定路径
@rem --resume-download （huggingface 路径）发布者/模型
@rem --local-dir 本地地址 默认 ~/cache/huggingface/hub
huggingface-cli download --resume-download intfloat/e5-large-v2 --local-dir ~/cache/huggingface/hub
```
