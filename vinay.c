#include<stdio.h>
#include<string.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    char userinput[40];
    int key;
    printf("enter the message and the key: ");
    scanf("%s%d", userinput, &key);

    for(int i = 0; i < strlen(userinput); i++) {
        userinput[i] = userinput[i] + key;
    }

    printf("hello owner your current password is %s",  userinput);

    int userkey;
    printf("\nenter the key to decrypt the message: ");
    getchar();
    scanf("%d", &userkey);
    for(int i = 0; i < strlen(userinput); i++) {
        userinput[i] = userinput[i] - userkey;
    }
    printf("the decrypted message is %s", userinput);
    return 0;
}