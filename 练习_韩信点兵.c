/*韩信点兵*/

/*1.0版本:有限循环*/
#include <stdio.h>
int main(void) {
    int x;

    for (x = 1; x < 10000; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4) {
            printf("%d\n", x);
            break;
        }
    }
    return 0;
}


/*2.0版本:无限循环*/
#include <stdio.h>
int main(void) {
    int x;

    for (x = 1; ; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4) {
            printf("%d\n", x);
            break;
        }
    }
    return 0;
}

/*3.0版本:goto*/
#include <stdio.h>
int main(void) {
    int x = 1;

    for (x = 1; ; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4) {
            printf("%d\n", x);
            goto end;
        }
    }
end:;
    return 0;
}

/*4.0版本:break*/
#include <stdio.h>
int main(void) {
    int x;

    for (x = 1; ; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4 && x % 11 == 10) {
            printf("%d\n", x);
            break;
        }
    }
    return 0;
}

/*5.0版本:标准库函数，exit(0)*/
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int x;

    for (x = 1; ; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4 && x % 11 == 10) {
            printf("%d\n", x);
            exit(0);
        }
    }
    return 0;
}

/*6.0版本：标致变量*/
#include <stdio.h>
int main(void) {
    int x;
    int find = 0; /*找到标致变量为假*/

    for (x = 1; !find; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4 && x % 11 == 10) {
            printf("%d\n", x);
            find = 1;
        }
    }
    return 0;
}

/*7.0版本：函数封装*/
#include <stdio.h>
int find_soldier(void) {
    int x;

    for (x = 1; ; x++) {
        if (x % 5 == 1 && x % 6 == 5 && x % 7 == 4 && x % 11 == 10) {
            return x;
        }
    }
}

/*8.0版本：标致变量2*/
