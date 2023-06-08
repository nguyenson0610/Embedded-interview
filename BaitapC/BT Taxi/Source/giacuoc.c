#include <stdio.h>
#include <stdint.h>


int main(int argc, char const *argv[])
{
    /* code */
    float numKm;
    float price = 0;
    printf("Nhap so km la ");
    scanf("%f", &numKm);

    if (numKm < 1 )
    {
        price = numKm * 14000;
    } else if(numKm <=30 && numKm > 1){
        price = (numKm-1)*10000 + 1*14000;
    } else if(numKm > 30)
    {
        price = (numKm-30)*8000 + 29*10000 + 1*14000;
    }
    printf("So tien phai tra la %0.0f dong", price);

    return 0;
}
