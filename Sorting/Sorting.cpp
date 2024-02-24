#include "MergeSort.cpp"
#include "BinarySearch.cpp"
#include "QuickSort.cpp"
#include <iostream>

using namespace std;
using namespace Sorting;

int main() {
    int array[7] = {61, 6, 59, 77, 96, 87, 57};
    int array2[7] = {6, 57, 59, 61, 77, 87, 96}; // worst (selection sort )

    int array3[7] = {96, 87, 77, 61, 59, 57, 6}; // worst (selection sort but selecting largest)
    int array4[7] = {6, 57, 59, 61, 77, 96, 87}; // best performance 
    int array5[7] = {57, 6, 59, 61, 77, 87, 96};
    // int array[5] = {0,1,2,3,4};
    // int array2[5] = {4,3,2,1,0}; // worst (selection sort )

    // int array3[5] = {0, 2,1, 4,3}; // worst (selection sort but selecting largest)
    // int array4[5] = {2,3,4,1,0}; // best performance 
    // int array5[5] = {4, 0,1,2,3}; // 
    QuickSort<int> sorter;
    QuickSort<int> sorter2;
    QuickSort<int> sorter3;
    QuickSort<int> sorter4;
    QuickSort<int> sorter5;
    sorter.quickSort(array, 7);
    cout << endl;
    sorter2.quickSort(array2, 7);
    cout << endl;
    sorter3.quickSort(array3, 7);
    cout << endl;
    sorter4.quickSort(array4, 7);
    cout << endl;
    sorter4.quickSort(array5, 7);
    //  for (int i = 0; i<7; i++) {
    //      cout << array[i] << endl;
    // }
    // BinarySearch<int> searcher;
    // int find = 0;
    // int index = searcher.binarySearch(array,7, find);
    





}