(script-fu-register
    "zany-none"; 函数名
    "Zany None"; 菜单标签
    "a script."; 描述
    "Chen Shen Chao"; 作者
    "copyright 2018,\
     Chen Shen Chao"; 版权
    "June 24 2018"; 创建日期
    "";
    SF-STRING "Text" "Text Box"; 字符串参数
    SF-FONT "Font" "Charter"; 字体
)
(script-fu-menu-register "zany-none" "<Image>/ZanyNone")

(define (zany-none text font)
    (gimp-image-list)
)