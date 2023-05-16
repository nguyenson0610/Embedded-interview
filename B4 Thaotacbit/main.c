#include <stdio.h>
#include <stdint.h>

void readByte(uint8_t byte)
{
    printf("0b");
    for (int i = 0; i < 8; i++)
    {
        uint8_t temp = 0b10000000;
        uint8_t kq = byte & temp;
        if (kq == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        byte = byte << 1;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    uint8_t test = 0b10010001;
    readByte(test);
    return 0;
}



