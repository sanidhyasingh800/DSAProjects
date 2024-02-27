#include <stdio.h>
int a = 10;
int b = 0;

void changeB() {
    b = 5;

}
int main() {
    changeB();
    a++;
    printf("a = %d\nb = %d", a, b);
    
}