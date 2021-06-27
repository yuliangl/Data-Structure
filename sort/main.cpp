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
             int j=0;
             for(j=i; j>0 && tmp < arr[j-1]; j--){
                     arr[j] = arr[j-1];//
//                     arr[j-1] = tmp;
             }
             arr[j] = tmp;
         }
    }
};

//O(n^1.3)
class ShellSort{
public:
    static void sort(vector<int>& arr){
        for(int gap=arr.size()/2; gap>0; gap/=2 ){
            for(int i=gap; i<(int)arr.size(); i++ ){
                int tmp=arr[i];
                for(int j=i; j>=gap; j-=gap){
                    if(arr[j] < arr[j-gap]){
                        arr[j] = arr[j-gap];
                        arr[j-gap] = tmp;
                    }
                }
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


class MergeSort{
public:
    static void sort(vector<int>& arr, int left, int right){
        if(left < right){
            int mid = (left + right) / 2;
            sort(arr, left, mid);
            sort(arr, mid + 1, right);

            merge(arr, left, right, mid);
        }
    }

    static void merge(vector<int>& arr, int left, int right, int mid){
        int i = left;
        int j = mid + 1;
        int t = 0;
        vector<int> tmp;

        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                tmp.push_back(arr[i]);
                ++i;
            }else{
                tmp.push_back(arr[j]);
                ++j;
            }
        }
        while(i <= mid){
                tmp.push_back(arr[i]);
            ++i;
        }
        while(j <= right){
                tmp.push_back(arr[j]);
            ++j;
        }
        int tmpleft = left;
        while(tmpleft <= right){
            arr[tmpleft] = tmp[t];
            tmpleft++;
            t++;
        }
//        for(int e : arr){
//            cout <<  e << " ";
//        }
//        cout << endl;
    }
};


int main()
{
//    vector<int> array{2,4,5,8,10,3,5,7,5,0};
    vector<int> array{8,4,5,7,1,3,6,2};
    for(int i=0; i<8000000; ++i){
        array.push_back(rand());
    }
//    InsertSort::sort(array);
//    ShellSort::sort(array);
//    BubbleSort::bsort(array);
//    SelectSort::sort(array);
//    QuickSort::sort(array, 0,array.size()-1);
//    QuickSort_optimization::sort(array, 0,array.size()-1);

    MergeSort::sort(array, 0, array.size()-1);

//    for(int i : array){
//        cout << i << " ";
//    }

    cout << endl;
    return 0;
}
