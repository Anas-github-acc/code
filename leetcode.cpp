#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, s, n) for(int i=s; i<n; i++)

class Solution {
public:
    bool xpalandrom(string x) {
        int n = x.size();
        bool flag = true;

        int i = 0;
        rep(j, n/2, n) {
            if(x[i] == x[j]) {
                flag = 1;
                i++;
            } else {
                i = 0;
                flag = 0;
            }
        }
        return flag;
    }
};

int main() {
    Solution s;
    string x;
    cin >> x;

    cout << (s.xpalandrom(x)?"YES":"NO") << endl;
    return 0;
}