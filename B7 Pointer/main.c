#include <stdio.h>
#include <stdint.h>

void tong(int a, int b){
    printf("tong la %d\n", a+b);
}

void hieu(int a, int b){
    printf("hieu la %d\n", a-b);
}

void tich(int a, int b){
    printf("tich la %d\n", a*b);
}

void thuong(int a, int b){
    printf("thuong la %d\n", a/b);
}

void tinhtoan(int a, int b, void (*ptr)(int,int)){
    printf("chuong trinh tinh toan \n");
    ptr(a,b);
}
int main(int argc, char const *argv[])
{
    int *ptr1;
    void (*ptr)(int,int) = NULL;
    ptr = &tong;
    ptr(2,9);
    tinhtoan(9,3,&hieu);
    float c = 11.9;
    void *ptr2 = &c;
    printf("con tro void la %0.1f\n", *(float*)ptr2);   // ep kieu ve con tro float
    ptr1 = &tong;
    ((void (*)(int,int))ptr1)(8,9);

    // pointer to poniter
    char *arr = "Hello";
    char arr1[] = "Hi";
    char *arr2[] = {"Hi", "Hello", "World"};
    printf("test: %c\n", **(arr2 +1));


    return 0;
}
