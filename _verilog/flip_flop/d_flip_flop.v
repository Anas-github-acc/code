`timescale 1ns / 1ps

module D_FlipFlop_tb;
    
    reg D;
    reg clk;
    reg reset;
    wire Q;
    
    D_FlipFlop uut (
        .D(D), 
        .clk(clk), 
        .reset(reset), 
        .Q(Q)
    );
    
    always begin
        #5 clk = ~clk;
    end
    
    initial begin
        clk = 0;
        D = 0;
        reset = 0;
        
        #10 reset = 1;
        #10 reset = 0;
        
        #10 D = 1;
        #10 D = 0;
        #10 D = 1;
        #10 D = 0;
        
        #10 reset = 1;
        #10 reset = 0;
        
        #20 $finish;
    end
    
endmodule
