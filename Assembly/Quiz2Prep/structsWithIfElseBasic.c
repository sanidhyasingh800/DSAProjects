struct Basic {
    int a;
};

struct Basic b;
int num;
int main() {
    if(num > 0) {
        b.a = num;
    } else {
        b.a = -num;
    }
}