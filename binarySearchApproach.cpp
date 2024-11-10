#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float eq(float x, float c){
    return pow(x,2)+sqrt(x)-c;
}

float binarySearch(float n,float c) {
    float l=0;
    float r=n;
    float mid;
    while ((r-l)>0.000001f) {
        mid=l+(r-l)/2;
        float eqv = eq(mid, c);
        if(eqv == 0){
            return mid;
        } else if (eqv > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return mid;
}

int main() {
    float c;
    cin >> c;
    cout << setprecision(6) << binarySearch(100000, c) << endl;
    return 0;
}