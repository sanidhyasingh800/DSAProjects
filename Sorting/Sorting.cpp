#include "MergeSort.cpp"
#include "BinarySearch.cpp"
#include <iostream>

using namespace std;
using namespace Sorting;

int main() {
    int array[8] = {0,1,6,4,3,4,5,9};
    MergeSort<int> sorter;
    sorter.mergeSort(array, 8);
    // for (int i = 0; i<7; i++) {
    //     cout << array[i] << endl;
    // }
    BinarySearch<int> searcher;
    int find = 0;
    int index = searcher.binarySearch(array,8, find);
    cout << index;





}