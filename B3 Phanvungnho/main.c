#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Phan vung text
const int a = 10;

//Phan vung data
int b = 15;
char arr[] = "Hello";
void hienthi(){
    static uint8_t c = 123;
}

//Phan vung bss
void luutru(){
    static int e = 0;

}
uint8_t d;

//Phan vung stack
int tong(int a, int b){
    int c;
    c = a + b;
    return c;
}


int main(int argc, char const *argv[])
{
    //Phan vung Heap
    uint8_t *prt = (uint8_t*)malloc(sizeof(uint8_t)*5);

    return 0;
}
