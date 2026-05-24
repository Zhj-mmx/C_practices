//二维数组int mat[2][3] = {{1,2,3},{4,5,6}}；
//利用行指针 + 解引用*(*(p+i)+j)方式，打印第二行第二列、第一行第三列元素。

#include <stdio.h>

int main() {
    int mat[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3] = mat;

    printf("%d", *(*(p+1)+1));
    printf("%d", *((*p)+2));
    
    return 0;
}