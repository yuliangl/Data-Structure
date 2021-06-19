#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//O(n^2)
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

//O(n^2)
class SelectSort{
public:
    static void sort(vector<int>& arr){
        size_t minindex = 0;
        for(size_t i=0; i<arr.size(); ++i){
            int min = arr[i];
            for(size_t j=i+1; j<arr.size(); ++j){
                if(min > arr[j]){
                    min = arr[j];
                    minindex = j;
                }
            }
            arr[minindex] = arr[i];
            arr[i] = min;

//            cout << i << "----th" << endl;
//            for(int e : arr){
//                cout << e << " ";
//            }
//            cout << endl;
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
class QuickSort{
public:
    static void sort(vector<int>& arr, int start, int end){
        if(start >= end)
            return;
        int i = start;
        int j = end;
        int base = arr[start];
        int tmp = 0;
        while(i < j){
            while(i<j && arr[j] >= base) {--j;}
            while(i<j && arr[i] <= base) {++i;}
            if(i<j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        arr[start] = arr[i];
        arr[i] = base;
//                cout << "----" << i <<"----th" << endl;
//                for(int e : arr){
//                    cout << e << " ";
//                }
//                cout << endl;
        sort(arr, start, i-1);
        sort(arr, i+1 , end);
    }
};


class QuickSort_optimization{
public:
    static void sort(vector<int>& arr, int start, int end){
        if(start+10 <= end){
            int pivot = median(arr, start, end);
            int i = start + 1;
            int j = end - 2;
            int tmp =0;

            for( ; ; ){
                while(arr[i] < pivot) {++i;}
                while(arr[j] > pivot) {--j;}

                if(i < j){
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }else{
                    break;
                }
            }
            tmp = arr[i];
            arr[i] = arr[end-1];
            arr[end-1] = tmp;
//                cout << "----" << i <<"----th" << endl;
//                for(int e : arr){
//                    cout << e << " ";
//                }
//                cout << endl;
            sort(arr, start, i-1);
            sort(arr, i+1, end);
        }else{
            InsertSort::sort(arr);
        }
    }

    static int median(vector<int>& arr, int left, int right){
        int mid = (left + right)/2;
        if(arr[left] > arr[mid])
            swap(arr[left], arr[mid]);
        if(arr[left] > arr[right])
            swap(arr[left], arr[right]);
        if(arr[mid] > arr[right])
            swap(arr[mid], arr[right]);

        swap(arr[mid], arr[right-1]);
        return arr[right-1];
    }
};



int main()
{
    vector<int> array{2,4,5,8,10,2,3,5,7,5,0};
    for(int i=0; i<8000000; ++i){
        array.push_back(rand());
    }
//    InsertSort::sort(array);
//    BubbleSort::bsort(array);
//    SelectSort::sort(array);
    QuickSort::sort(array, 0,array.size()-1);
//    QuickSort_optimization::sort(array, 0,array.size()-1);

    //for(int i : array){
    //    cout << i << " ";
    //}

    return 0;
}
