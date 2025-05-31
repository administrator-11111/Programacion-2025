#include <stdio.h>

int main() {
    int dias[31];
    for (int i = 0; i < 31; i++) {
        dias[i] = i+1;
        printf("día %d\n", dias[i]); // 0 +1 = 1
    }
    return 0;
}
