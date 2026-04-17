/*求水仙花数*/
#include <stdio.h>
int main() {
    for (int a = 100; a < 1000; a++) {
        int n1 = a / 100;
        int n2 = (a % 100) / 10;
        int n3 = a % 10;
        if (a == n1 * n1 * n1 + n2 * n2 * n2 + n3 * n3 * n3) {
            printf("%d是水仙花数\n", a);
        }
    }

    return 0;
}