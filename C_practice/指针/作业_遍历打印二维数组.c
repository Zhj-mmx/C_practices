//有数组int arr[3][4]自行赋值，定义行指针int (*p)[4]，用行指针遍历打印二维数组所有元素。

#include <stdio.h>

int main() {
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int (*p)[4] = arr;

    for (int x = 0;x < 3;x++) {
        for (int y = 0; y < 4; y++) {
            printf("%d\n",*(*(p+x)+y));
        }
    }
    return 0;
}