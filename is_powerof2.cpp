int is_pow2(int n){
    if(n == 0)
        return 0;
    while(n%2 == 0){
        n = n>>1;
    }
    if(n == 1)
        return 1;
    else
        return 0;
}