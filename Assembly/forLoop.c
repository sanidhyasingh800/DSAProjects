#include <stdio.h>
int a[5] = {1,2,3,4,5};
int b = 0;
int i = 0;
int main() {
   for (i = 0; i<5; i++) {
       if (a[i] % 2 == 0) {
           b++;
       }
   }
    printf("%d\n", b);
    return 0;

}