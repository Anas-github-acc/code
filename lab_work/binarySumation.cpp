#include<iostream>
using namespace std;
string sum(string a, string b){
    if(a.size() < b.size()){
        string temp = a;
        a = b;
        b = temp;
    }
    long long len = a.size();
    int x = 0;
    for(long long i=len-1, j=b.size();i>=0;i--){
        if(j == 0){
            b = "0" + b;
        }else{
            j=j-1;
        }
        x += (int)a[i] + (int)b[j] - 96;
        if(x == 2){
            a[i] = '0';
            x = 1;
        }else{
            a[i] = char (x + 48);
            x = 0;
        }
    }
    if(x == 1)
        a = "1" + a;
    return a;
}

int main(){
    cout<<sum("101", "1")<<endl;
    return 0;
}