#include <stdio.h>

struct complex
{
    int real;
    int imag;
};


int main() {
    typedef struct complex complex;
    complex c1, c2;
    scanf("%d + i%d", &c1.real, &c1.imag);
    scanf("%d + i%d", &c2.real, &c2.imag);
    printf("%d + i%d\n", c1.real + c2.real, c1.imag + c2.imag);
    return 0;
}