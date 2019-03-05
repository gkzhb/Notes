module Gates2(
    input  logic a,
    input  logic b,
    output logic [5:0] z );
    
    assign z[5] = a & b;    //与门
    assign z[4] = ~(a & b); //与非门
    assign z[3] = a | b;    //或门
    assign z[2] = ~(a | b); //或非门
    assign z[1] = a ^ b;    //异或门
    assign z[0] = a ~^ b;   //同或门
endmodule