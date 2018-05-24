[TOC]
# Markdown中Latex数学公式基本语法

## 公式排版
分为两种排版：
* 行内公式：用`\`或者`$`包裹公式
* 独立公式：用`\$`包裹公式

eg.
$ \sum_{i=0}^{n}i^2 $

$$ \sum_{i=0}^{n}i^2 $$

以下几个字符：`# $ % & ~ _ ^ \ { }`有特殊意义，需要表示这些字符时，需要转义（字符前加`.`)

'\boxed`命令给公式加一个方框

eg.
$$ E = mc^2 $$
$$ \boxed{E=mc^2} $$
##希腊字母
![](./希腊字母.png '希腊字母')
## 上下标和根号
用`^`表示上标，用`_`表示下标，根号用`\sqrt`表示，上下标如果多于一个字符或符号，需要用`{}`括起来
`\sqrt[开方次数]{开方公式}`

eg.
$\sum_{i=1}^n a_i$
$$ x_{ij}^2\quad \sqrt{x}\quad \sqrt[3]{x} $$

`\quad`表示空格
## 分数
分数用`\frac`表示，字号工具环境设置，该命令把字号设置为独立公式中的大小，`\tfrac`则把字号设置为行间公式中的大小。
eg.
$ \frac{1}{2} \dfrac{1}{2} $
$$ \frac{1}{2} \dfrac{1}{2} $$
## 运算符
* `+ - * / =`直接输入，特殊运算则用以下特殊命令
$$ \pm\; \times\; \div\; \cdot\; \cap\; \cup\; \geq\; \leq\;  \neq\; \approx\; \equiv $$
* 和、积、极限、积分等运算符用`\sum`,`\prod`,`\lim`,`\int`,这些公式在行内公式被压缩，以适应行高，可以通过`\limits`和`\nolimits`命令显示制动是否压缩
$ \sum\; \prod\; \lim\; \int\; $
$ x\to 0 $

    $ \sum_{i=1}^n i \quad \prod_{i=1}^n \quad
    \lim_{x\to0}x^2 \quad \int_{a}^{b}x^2 dx $

    $$ \sum_{i=1}^n i \quad \prod_{i=1}^n
	\quad \lim_{x\to0} x^2 \quad \int_a^b x^2 dx $$

    $$ \sum_{i=1}^n i \quad	\prod_{i=1}^n\quad
	\lim_{x\to0} x^2 \quad \int_a^b x^2 dx $$

    $$\sum\nolimits_{i=1}^n\quad\prod\nolimits_{i=1}^n\quad
	\lim\nolimits_{x\to0} x^2 \quad \int\nolimits_a^b x^2 dx $$

多重积分使用如下形式
` \int \iint \iiint \iiiint \idotsint `

$$ \int\int\quad \int\int\int\quad
   \int\int\int\int\quad \int\dots\int $$
$$
	\iint\quad \iiint\quad
$$

## 定理和证明
$ \newtheorem $