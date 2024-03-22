#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(int arr[],int s, int e)
    {
        int pivot = arr[s];
        int count = 0;
        for (int i = s + 1; i <= e; i++) {
            if (arr[i] <= pivot)
                count++;
        }
        int pivotIndex = s + count;
        swap(arr[pivotIndex], arr[s]);

        int i = s, j = e;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                int temp = arr[i];
                swap(arr[i++], arr[j--]);
            }
        }
        return pivotIndex;
    }
    
    void quickSort(int arr[],int s, int e)
    {
        if (s >= e)
            return;
        int p = partition(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }

    vector<int> twoSum(vector<int>& arr, int target) {
        std::vector<int> ans;
        int n = arr.size();
        int* arrArray = arr.data();
        quickSort(arrArray, 0, n - 1);

        for(int i = 0; i < n; i++) {
            cout<<arrArray[i]<<endl;
        }
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int sum = arrArray[s] + arrArray[e];
            if (sum == target) {
                
                ans.push_back(s);
                ans.push_back(e);
                return ans;
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> arr = { 2, 11, 7, 15 };
    int target = 9;
    std::vector<int> ans = s.twoSum(arr, target);
    return 0;
}