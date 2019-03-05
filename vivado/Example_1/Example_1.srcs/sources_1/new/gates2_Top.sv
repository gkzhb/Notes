module gates2_Top(
    input  logic [1:0]SW,
    output logic [5:0]LED );
    
    //สตภýปฏ
    Gates2 G2(.a(SW[1]), .b(SW[0]), .z(LED));
endmodule