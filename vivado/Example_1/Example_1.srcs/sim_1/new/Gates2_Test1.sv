`timescale 1ns / 1ps

module Gates2_Test1( ); //无接口
    logic a, b;     //待测模块输入端口变量
    logic [5:0] z;  //待测模块输出端口变量
    
    //实例化
    Gates2 G2(a, b, z);
    //激励信号
    initial
      begin
             a = 0; b = 0; // 0ns
         #10 a = 0; b = 1; //10ns
         #10 a = 1; b = 0; //20ns
         #10 a = 1; b = 1; //30ns
      end    
endmodule