struct A {
    int* x;
    struct B* ptr;
    int y;
    int z;
};

struct B {
    struct A* ptr;
    int num;
};

struct A a;
struct B* b;
int main() {
    for (int i = 0; i<b->num; i++) {
        if (b->ptr[i].y > 0) {
            *(b->ptr[i].x) = b->ptr[i].y;
        }
    }
}