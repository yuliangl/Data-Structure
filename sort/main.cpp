#include <iostream>
#include <vector>

using namespace std;

class InsertSort{
public:
    static void sort(vector<int>& arr){
         for(uint32_t i=1; i<arr.size(); i++){
             int tmp = arr[i];
             for(int j=i; j>0 && tmp < arr[j-1]; j--){
                     arr[j] = arr[j-1];
                     arr[j-1] = tmp;
             }
         }
    }
};

// O(n^2)
class BubbleSort{
public:
    static void bsort(vector<int>& arr){
        bool flag = true;
        for(size_t i=0; i<arr.size(); ++i){
            for(size_t j=0; j<arr.size()-1-i; ++j){
                int tmp = arr[j];
                if(arr[j] > arr[j+1]){
                    flag = false;
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
            if(flag)
                break;
            flag = true;
        }

    }
};
//class BubbleSort{
//public:
//    static void bsort(vector<int>& arr){
//         for(uint32_t i=0; i<arr.size()-1; i++){
//             for(uint32_t j=0; j<arr.size()-1-i; j++){
//                 if(arr[j] > arr[j+1]){
//                     int tmp = arr[j];
//                     arr[j] = arr[j+1];
//                     arr[j+1] = tmp;
//                 }
//             }
//         }
//    }
//};

class QuickSort{
public:
    static void sort(vector<int>& arr, int start, int end){
        if(start < end){
        int low = start;
        int high = end;
        int standrad = arr[start];
        while(low < high){
            while(low < high && arr[high] > standrad){
                high--;
            }
            arr[low] = arr[high];
            while(low < high && arr[low] < standrad){
                low++;
            }
            arr[high] = arr[low];
        }
        arr[low] = standrad;
        sort(arr, start, low);
        sort(arr, low+1, end);
        }
    }
};


int main()
{
    vector<int> array{2,4,6,8,10,1,3,5,7,9};
    for(int i=0; i<80000; ++i){
        array.push_back(rand());
    }
//    InsertSort::sort(array);
//    BubbleSort::bsort(array);
    QuickSort::sort(array, 0, 10);

    for(int i : array){
        cout << i << endl;
    }

    cout << 1 << endl;
    return 0;
}
