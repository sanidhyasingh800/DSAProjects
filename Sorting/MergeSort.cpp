#include <iostream>
using namespace std;

namespace Sorting {
    template<class Data>
    class MergeSort{
        private: 
        Data* tempArray;
        int size;

        void merge(Data* sourceArray, int start, int middle, int end) {
            int i = start;
            int j = middle;
            for (int k = 0; k< end-start; k++) {
                if (i == middle) { 
                    tempArray[k] = sourceArray[j++];
                } else if (j == end) { 
                    tempArray[k] = sourceArray[i++];
                } else if (sourceArray[i] > sourceArray[j]) {
                    tempArray[k] = sourceArray[j++];
                } else {
                    tempArray[k] = sourceArray[i++];
                }

                
            }

            for (int k = 0; k< end - start; k++) {
                sourceArray[start + k] = tempArray[k];
            }


        }

        void sort(Data* sourceArray, int startingIndex, int endingIndex) {
         // division of array into smaller and smaller subparts 
         if (endingIndex - startingIndex <= 1) {
            return;
         }
         int splitIndex = (startingIndex + endingIndex)/2;
         sort(sourceArray, startingIndex, splitIndex);
         sort(sourceArray, splitIndex, endingIndex);

         merge(sourceArray, startingIndex, splitIndex, endingIndex);

        }   

        void sort2(Data* sourceArray, int startingIndex, int endingIndex) {
            // division of array into smaller and smaller subparts 
            if (endingIndex - startingIndex <= 1) {
                cout << sourceArray[startingIndex] << endl;
                return;
            }
            int splitIndex = (startingIndex + endingIndex)/2;
            sort2(sourceArray, startingIndex, splitIndex);
            sort2(sourceArray, splitIndex, endingIndex);

           // merge(sourceArray, startingIndex, splitIndex, endingIndex);2

        }  

        public:

        void mergeSort(Data* sourceArray, int size) {
            tempArray = new Data[size];
            this->size = size;
            sort(sourceArray, 0, size);

        }


        ~MergeSort() {
            delete[] tempArray;
        }



    };
}