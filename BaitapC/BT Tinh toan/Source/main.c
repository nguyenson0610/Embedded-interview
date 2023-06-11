#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

// tinh toan thong thuong
// void TinhToan(char *arr)
// {

//     for (int i = 0; i < strlen(arr); i++)
//     {
//         if (arr[i] == '(')
//         {
//             arr[i + 1] =
//         }

//         if (arr[i] == '+' || arr[i] == '-')
//         {
//         }

//         printf("la %d\n", strlen(arr));
//     }
// }

// phuong trinh bac nhat ax+b=0
void BacNhat(char *arr)
{
    int a = 0;
    int b = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == 'x')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                a += (int)(arr[j] - '0') * pow(10, i - j - 1);
            }
            printf("a la %d\n", a);

            for (int j = i + 2; j < strlen(arr); j++)
            {
                b += (int)(arr[j] - '0') * pow(10, strlen(arr) - j - 1);
            }
            printf("b la %d\n", b);

            if (a == 0)
            {
                printf("phuong trinh vo nghiem\n");
            }
            else if (arr[i + 1] == '+')
            {
                printf("ket qua phuong trnh bac nhat la %f\n", (float)-b / a);
            }
            else if (arr[i + 1] == '-')
            {
                printf("ket qua phuong trnh bac nhat la %f\n", (float)+b / a);
            }
        }
    }
}

// phuong trinh bac hai ax^2 + bx + c =0
// void BacHai(char *arr){
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     for (int i = 0; i < strlen(arr); i++)
//     {
//         if ((arr[i] == 'x') && (arr[i+1] = '^'))
//         {
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 a += (int)(arr[j] - '0') * pow(10, i - j - 1);
//             }
//             printf("a la %d\n", a);
//         }
        
//     }
// }

int main(int argc, char const *argv[])
{
    char arr[20];
    printf("Nhap chuoi tinh toan ");
    scanf("%s", &arr);
    BacNhat(arr);
    return 0;
}
