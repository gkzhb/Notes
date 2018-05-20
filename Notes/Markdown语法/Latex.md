[TOC]
# Markdown��Latex��ѧ��ʽ�����﷨

## ��ʽ�Ű�
��Ϊ�����Ű棺
* ���ڹ�ʽ����`\`����`$`������ʽ
* ������ʽ����`\$`������ʽ

eg.
$ \sum_{i=0}^{n}i^2 $

$$ \sum_{i=0}^{n}i^2 $$

���¼����ַ���`# $ % & ~ _ ^ \ { }`���������壬��Ҫ��ʾ��Щ�ַ�ʱ����Ҫת�壨�ַ�ǰ��`.`)

'\boxed`�������ʽ��һ������

eg.
$$ E = mc^2 $$
$$ \boxed{E=mc^2} $$
##ϣ����ĸ
![](./ϣ����ĸ.png 'ϣ����ĸ')
## ���±�͸���
��`^`��ʾ�ϱ꣬��`_`��ʾ�±꣬������`\sqrt`��ʾ�����±��������һ���ַ�����ţ���Ҫ��`{}`������
`\sqrt[��������]{������ʽ}`

eg.
$\sum_{i=1}^n a_i$
$$ x_{ij}^2\quad \sqrt{x}\quad \sqrt[3]{x} $$

`\quad`��ʾ�ո�
## ����
������`\frac`��ʾ���ֺŹ��߻������ã���������ֺ�����Ϊ������ʽ�еĴ�С��`\tfrac`����ֺ�����Ϊ�м乫ʽ�еĴ�С��
eg.
$ \frac{1}{2} \dfrac{1}{2} $
$$ \frac{1}{2} \dfrac{1}{2} $$
## �����
* `+ - * / =`ֱ�����룬������������������������
$$ \pm\; \times\; \div\; \cdot\; \cap\; \cup\; \geq\; \leq\;  \neq\; \approx\; \equiv $$
* �͡��������ޡ����ֵ��������`\sum`,`\prod`,`\lim`,`\int`,��Щ��ʽ�����ڹ�ʽ��ѹ��������Ӧ�иߣ�����ͨ��`\limits`��`\nolimits`������ʾ�ƶ��Ƿ�ѹ��
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

���ػ���ʹ��������ʽ
` \int \iint \iiint \iiiint \idotsint `

$$ \int\int\quad \int\int\int\quad
   \int\int\int\int\quad \int\dots\int $$
$$
	\iint\quad \iiint\quad
$$

## �����֤��
$ \newtheorem $