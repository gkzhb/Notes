[TOC]
        //TOC   根据标题生成目录
#导入
@import "1.jpg"

#字体
有趣

*有趣*
_有趣_//斜体

组合**有趣**
__有趣__//粗体

~~有趣~~  //横线

#标题
#一级
<h1>标题 和 id {#my_id}
##二级
<h2>标题classes {.class1 .class2}
第二阶标题
-
最高阶标题
=
#引用
As what he said:
>Life is great.
>>多层引用

区块引用
>a
>
># b
>1
2

* 项目1
    >列表项目内放引用则>要缩进
* 项目2
        代码块
        aaa

    项目2a

    项目2b
*   a
*   b
+ 另一种项目
- 再一种项目

#列表
数字-句点-空白

1998\. aaa
1. 项目1

    段落  //缩进4个空格或1个制表符
1. 项目2
   1. a         //项目标记前面最多3个空格，后面至少1个空格
   21. 项目2a

   22. 项目2b

#图片
![Alt Text](url)        //添加图片

![alt text](/path/to/img.jpg "Title")   //行内形式

![alt text][id]

[id]: /path/to/img.jpg "Title"
//参考形式

#链接
http://github.com       //链接自动生成

链接内容定义的形式为：

方括号（前面可以选择性地加上至多三个空格来缩进），里面输入链接文字
接着一个冒号
接着一个以上的空格或制表符
接着链接的网址
选择性地接着 title 内容，可以用单引号、双引号或是括弧包着

eg. [foo]: http://example.com/  "Optional Title Here"
or [foo]: <http://example.com/>  "Optional Title Here"

1. 行内

This is an [example link](http://www.baidu.com/)

This is an [example link](http://example.com/ "With a Title").

2. 参考

I get 10 times more traffic from [Google][1] than from [Yahoo][2] or [MSN][3].  //链接名称可用字母、数字和空格，但是不分大小写

[1]: http://google.com/ "Google"
[2]: http://search.yahoo.com/ "Yahoo Search"
[3]: http://search.msn.com/ "MSN Search"

3. 隐式链接标记
[Google][]

[Google]: http://google.com/


分割线（三个或更多）：

---
连字符
***
星号
___
下划线
* * *

代码：
`<addr>`
代码块     //在代码块上下使用```
```
#include<stdio.h>
int main(void)
{
    return 0;
}
```

#特殊字符自动转换
//markdown会自动转换

&lt;        //<用于起始标签

&amp;       //&符号用于标记html实体

&copy;      //版权符号

#反斜杠
Markdown 支持以下这些符号前面加上反斜杠来帮助插入普通的符号：

\   反斜线
`   反引号
*   星号
_   底线
{}  花括号
[]  方括号
()  括弧
#   井字号
+   加号
-   减号
.   英文句点
!   惊叹号
