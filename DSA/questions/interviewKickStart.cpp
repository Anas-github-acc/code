#include<iostream>

using namespace std;

int solve(int n, int unit_to[], int unit_from[], int weight[], int x) {
    
}

int main() {
    int n;
    std::cin>>n;
    int unit_to[n-1];
    int unit_from[n-1];
    int weight[n-1];
    int x;
    for(int j=0;j<n-1;j++) {
        std::cin>>unit_to[j];
    }
    for(int j=0;j<n-1;j++) {
        std::cin>>unit_from[j];
    }
    for(int j=0;j<n-1;j++) {
        std::cin>>weight[j];
    }
    std::cin>>x;

    solve(n, unit_to, unit_from, weight, x);
    return 0;
}