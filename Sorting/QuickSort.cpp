#include <iostream>

using namespace std;

namespace Sorting {
    template<class Data>
    class QuickSort{
    private:
    int numCompares;

        int partition2(Data* x, int lo, int hi) {
            int p = lo+1;
            for( int i=lo+1; i <= hi; i++ ) {
                numCompares++;
                if( x[i] < x[lo] ) { 
                    swap(x, p, i); 
                    ++p; 
                }
            }
                swap(x, lo, p-1);
                return p-1;
        }
        int partition(Data* arr, int partitionIndex, int high) {
            int smaller = partitionIndex+1;
            int larger = high;
            while(true) {
                while (arr[smaller] < arr[partitionIndex]) {
                    if (smaller > high) {
                        break;
                    }
                    smaller++;
                }
                while (arr[larger]  > arr[partitionIndex]) {
                    if (larger<partitionIndex+1) {
                        break;
                    }
                    larger--;
                }
                if (smaller > larger) {
                    break;
                }
                swap(arr, smaller, larger);


            }
            swap(arr, partitionIndex, larger);
            return larger;

        }

        void swap(Data* arr, int i, int j) {
            Data temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        void qSort(Data* arr, int partitionIndex, int high) {
            if (partitionIndex >= high) {
                return;
            }
            int p = partition2(arr, partitionIndex, high);
            qSort(arr, 0, p-1);
            qSort(arr, p+1, high);
        }


    public:
        QuickSort() {}

        
        void quickSort(Data* arr, int size) {
            numCompares = 0;
            qSort(arr, 0, size-1);
            cout << "compares: " << numCompares;
        }
    };
}