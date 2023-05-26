#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint16_t a;
    uint32_t b;
    uint8_t c;
}typeData;

typedef union 
{
    uint8_t arr1[6];
    uint8_t arr2[3];
}typeTest;


void hienthi(typeData data){
    printf("a la %d, b la %d, c la %d\n", data.a, data.b, data.c);
}

int main(int argc, char const *argv[])
{
    typeData data;
    data.a = 12;
    data.b = 23;
    data.c = 9;
    hienthi(data);
    typeTest test;
    strcpy(test.arr1,(char*)"Hello");
    test.arr1[5] = '\0';
    strcpy(test.arr2,(char*)"Hi");
    //test.arr2[3] = '\0';
    printf("hien thi test la %s\n", test.arr1);
    return 0;
}
