#include <algorithm.h>

//template <typename T>
int binarySerch(vector<int>& arr, int val){
    int left = 0;
    int right = arr.size()-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if( arr[mid] == val){
                return mid;
        }else if(arr[mid] > val){
                right = mid - 1;
        }else {
                left = mid + 1;
        }
    }
    return INT_LEAST32_MIN;
}

int divideConquer() {
    cout << "meishi " << endl;
    return 0;
}
