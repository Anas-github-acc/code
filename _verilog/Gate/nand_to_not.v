module nand_to_not (
    input a,b,
    output y
);
    assign y=~(a&b);
    endmodule