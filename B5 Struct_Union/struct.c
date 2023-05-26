#include <stdio.h>
#include <stdint.h>

struct typeDate
{
    uint8_t ngay;
    uint32_t thang;
    uint64_t nam;
};

struct typeData
{
    uint8_t arr2[7];
    uint16_t arr1[4];
    uint64_t arr3[2];
};

struct typeDean
{
    uint32_t arr1[8];
    uint8_t arr4[3];
    uint16_t arr2[5];
    uint64_t arr3[7];
};


int main(int argc, char const *argv[])
{
    /* code */
    struct typeDate a;
    printf("kich thuoc la %d byte", sizeof(struct typeDean));
    return 0;
}

