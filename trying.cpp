#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }

   for(int i=arr.size()-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(arr[i]==arr[j]){
                arr.erase(arr.begin() + j);
                i--; 

            }

        }


   }
   cout<<arr.size()<<endl;

   for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
    }
 
    return 0;
}