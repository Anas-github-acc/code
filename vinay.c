#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *f1,*f2;
    char c;
    f1 = fopen("vinay1.txt","rb");
    f2 = fopen("vinay2.txt","w");
    c = fread(&c,sizeof(char),1,f1);
    fputc(c,f2);
    printf("File copied successfully\n");
    f2 = fopen("vinay2.txt","r");
    char ch[100];
    fgets(ch, 3,f2);
    printf("\n%sko",ch);
    fclose(f1);
    fclose(f2);
    return 0;
}