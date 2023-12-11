# [Huggingface](https://huggingface.co)

### huggingface_hub

因为墙 需要使用 huggingface_hub 设置镜像

```bat
@rem 安装
pip install -U huggingface_hub

@rem 设置镜像 cmd
set HF_ENDPOINT=https://hf-mirror.com

@rem 设置镜像 POWERSHELL
$env:HF_ENDPOINT="https://hf-mirror.com"

@rem 下载到指定路径
@rem --resume-download （huggingface 路径）发布者/模型
@rem --local-dir 本地地址 默认 ~/cache/huggingface/hub
huggingface-cli download --resume-download intfloat/e5-large-v2 --local-dir ~/cache/huggingface/hub
```

### hf-transfer

上面切换代理，但是速度还是太慢，因为模型都是用 G 表示大小的。

装上后 使用 huggingface_hub 会提速。

缺点：
1. 启用后没有进度，所以看着像卡着。。
2. 启用镜像和国内镜像源不兼容。

```bat
@rem 安装
pip install -U hf-transfer

@rem 设置启动 cmd
set HF_HUB_ENABLE_HF_TRANSFER=1

@rem 设置启动 powershell
$env:HF_HUB_ENABLE_HF_TRANSFER=1

@rem 之后流程就是使用 huggingface_hub
```