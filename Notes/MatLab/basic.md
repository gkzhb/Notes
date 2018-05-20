# 创建变量
x=[1 2 3;4 5 6;7 8 9]
	// 创建矩阵
# 修改变量
x(i,j)=k
	// 修改矩阵第i行第j列元素
x(i,:)=[...]
	// 修改第i行元素，“:”出现位置表示取整行/列
# 保存、删除变量
save 文件名 变量名
	// 保存变量，多变量时各变量间用空格分开
clear 变量名
	// 删除变量
clear
	// 删除所有的变量

# 基本运算
加法：+
减法：-
乘法：*
除法：/
指数：^
转置：'

# 数组运算
同维向量的对应元素间的运算：在符号前加“.”，即 ./ 与 .*

# 三角函数
sin , cos , tan , cot , atan , acot

# 复数运算
取模： abs
相角： angle
实部： real
虚部： imag

# 傅立叶变换
fft
逆变换：ifft

# plot作图
语法：plot(变量1，变量2，‘参量名’，参量值)
也可以只对单变量作图，横坐标为数据点。
xlabel,ylabel指令可以更改坐标轴的标签，如xlabel('横坐标')

## plot3作图
语法同上，是3维作图。新的作图一般会覆盖旧的作图，hold on 命令使旧的作图保持不被覆盖，hold off 正好相反。单独键入 hold ，则是在两种模式间切换

## 带误差限的作图
errorbar(变量X,变量Y,Y的误差范围)
其中“Y的误差范围”应当与变量Y同维。
## 极坐标作图
polar(角度,极径)

# 函数拟合工具包
## 函数命令拟合
最常用的函数拟合命令为fit，语法为：
[拟合结果 拟合精度]＝fit（X数据，Y数据，'拟合类型'）
其中，具体的拟合类型可以参看帮助文档，也可以使用fittype来自定义新的函数类型，比如定义拟合函数：a*x+b*x^2+exp(4*x)，语法为：
newtype=fittype('a*x+b*x^2+exp(4*x)')
现在就用刚定义newtype函数类型来拟合数据（1,2）,(2,3),(3,4),(4,5),(5,6)
x=[1;2;3;4;5];
y=[2;3;4;5;6];
fit(x,y,newtype)

# 编程
## for
for i=start:step:end
xxxx
end
## if
if xxx
elseif xxxx
else xxxx
end
## switch
switch *switch_expr*
case *case_expr*
xxx
case *case_expr 2*
xxx
end
## while
while condition
xxx
end
## 注释用“%”