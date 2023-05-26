#include <stdio.h>
#include <stdint.h>

//static toan cuc
static int b = 16;


//static cuc bo
void hienthi(){
    static a = 15;
    a = a + 10;
    printf("a la %d\n", a);
}



int main(int argc, char const *argv[])
{
    /* code */
    hienthi();
    hienthi();
    return 0;
}
