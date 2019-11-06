#### normal 下的复制粘贴

- 复制粘贴：y（yank）和 p（put）,剪贴 d（delete）和  p

- yiw 复制一个单词，yy 复制一行

#### insert 下的复制粘贴

- Ctrl + V

- 先使用 set paste 再粘贴，防止缩进混乱。然后再使用 set nopaste 恢复原来的模式，否则 set autoindent 会失效

#### 寄存器

- vim 里操作的是寄存器而不是系统剪切板，这和其他编辑器不同
- 默认我们使用 d 删除或者 y 复制的内容都放到了 “无名寄存器”
- 用 x 删除一个字符放到无名寄存器，然后 p 粘贴，可以调换两个字符

#### 深入寄存器

- 使用 "{register} （双引号+寄存器的名称）可以指定寄存器来进行复制粘贴
- 复制专用寄存器  "0 使用 y 复制文本同时会被拷贝到复制寄存器 0
- 系统剪切板 "+ 可以再复制前加上 "+ 复制到系统剪切板
- 其他寄存器比如 "%当前文件名， ". 上次插入的文本（了解即可）

> echo has('clipboard') 输出为 1 表示可以使用系统剪切板