#include <iostream>

using namespace std;

namespace Sorting{
template<class Data>
class BinarySearch {
    private:

    int binarySearch(int start, int end, int middle, Data* array, Data& searchValue) {
        if (start > end) {
            return -1;
        }
        else if (searchValue > array[middle]) {
            return binarySearch(middle, end, (end +middle)/2, array, searchValue);
        }
        else if (searchValue < array[middle]) {
            return binarySearch(start, middle, middle/2, array, searchValue);
        } 
        return middle;

    }



    public: 

    BinarySearch(){}

    int binarySearch(Data* array, int size, Data& searchValue){
        // assumes array is sorted
        return binarySearch(0, size, size/2, array, searchValue);

    }



};

}