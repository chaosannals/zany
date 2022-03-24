# gdb

```bash
gdb
# 由于 wsl 所以通过 cat /etc/resolv.conf 查到宿主地址
target remote 172.19.80.1:1234

# 设置架构
set architecture i8086

# 设置汇编风格为 intel
set disassembly-flavor intel

# 显示界面
layout
# Ctrl + L 刷新
layout src #显示源代码窗口
layout asm #显示汇编窗口
layout regs #显示源代码/汇编和寄存器窗口
layout split #显示源代码和汇编窗口
layout next #显示下一个layout
layout prev #显示上一个layout

# 设置断电 启示内存
b *0x7c00

# 断点到 加载器
b *0x8200

# 查看断点情况
info b

ni # next instruction
si # step instruction
c # continue # 直接执行

# 显示寄存器
p $eax

x/i $pc #显示指针汇编指令
x/10i $pc # 显示指针后10个汇编指令

x/10b $esp # 显示 10个 byte 数据
x/10w $esp # 显示栈10个 dword 数据
x/10s $rdi # 显示为10个 0结尾字符串

b 0x7c00 # 设置断点
```
