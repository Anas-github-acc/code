#include<iostream>
using namespace std;
int compliment(int n){
    if(n == -1)
        return n;
    n = compliment(n>>1);
    return n<<1;
}
int main(){
    int n;
    cin>>n;
    int x = compliment(~n);
    if(n == 0)
        cout<<1<<endl;
    else
        cout<<~n - x<<endl;
    return 0;
}