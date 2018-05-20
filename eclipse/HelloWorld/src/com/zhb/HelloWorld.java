package com.zhb;

public class HelloWorld {

	public static void main(String[] args){
		//System.out.printf("Hello World! ");
		Post post=new Post(); // 创建对象
		post.title="我的博客"; //访问对象属性
		post.content="第一篇博客"; 
		post.print(); // 调用对象方法
	}
}