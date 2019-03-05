`timescale 1ns / 1ps

module Gates2_Test1( ); //�޽ӿ�
    logic a, b;     //����ģ������˿ڱ���
    logic [5:0] z;  //����ģ������˿ڱ���
    
    //ʵ����
    Gates2 G2(a, b, z);
    //�����ź�
    initial
      begin
             a = 0; b = 0; // 0ns
         #10 a = 0; b = 1; //10ns
         #10 a = 1; b = 0; //20ns
         #10 a = 1; b = 1; //30ns
      end    
endmodule