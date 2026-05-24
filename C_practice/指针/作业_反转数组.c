//输入 5 个整数存入数组，利用指针反转数组元素并输出（不额外开新数组）。
#include <stdio.h>

void reverseArray(int *arr, int length) {
    int *left = arr;
    int *right = arr + length - 1;
    int temp;

    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int main() {
    int arr[5] = [1,2,3,4,5];
    int i;
    
    // 获取用户输入
    printf("请输入5个整数：");
    for (i = 0; i < 5; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入错误，请输入有效的整数！");
            return 1;
        }
    }
    
    // 反转数组
    reverseArray(arr, 5);
    
    // 输出反转后的数组
    printf("反转后的数组：");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

 #include <stdio.h>

// 使用指针反转数组元素(参考答案)
void reverseArray(int *arr, int length) {
    int *left = arr;
    int *right = arr + length - 1;
    int temp;
    
    while (left < right) {
        // 交换指针指向的元素
        temp = *left;
        *left = *right;
        *right = temp;
        
        left++;
        right--;
    }
}

int main() {
    int arr[5];
    int i;
    
    // 获取用户输入
    printf("请输入5个整数：");
    for (i = 0; i < 5; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入错误，请输入有效的整数！");
            return 1;
        }
    }
    
    // 反转数组
    reverseArray(arr, 5);
    
    // 输出反转后的数组
    printf("反转后的数组：");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}