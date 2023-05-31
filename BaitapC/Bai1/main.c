#include <stdio.h>
#include <stdint.h>


// Sap xep tư lon den be
void sortList(uint8_t n, uint8_t arr[])
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Dem so lan xuat hien
void lietke(uint8_t n, uint8_t arr[])
{
    sortList(n, arr);
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        if (arr[i] == arr[i - 1] && i > 0)
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        printf("So lan %d xuat hien la %d\n", arr[i], count);
    }
}

// dao nguoc 1 chuoi
void daochuoi(uint8_t length, char chuoi[])
{
    int count = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        if (chuoi[i] != ' ')
        {
            count++;
            if ((chuoi[i] >= 'A') && (chuoi[i] <= 'Z'))
            {
                for (int j = i; j < i + count; j++)
                {
                    printf("%c", chuoi[j]);
                }
                printf(" ");
                count = 0;
            }
        }
        else
        {
            for (int j = i + 1; j < i + 1 + count; j++)
            {
                printf("%c", chuoi[j]);
            }
            count = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    char chuoi[] = "Rat vui khi duoc lam quen voi moi nguoi";
    uint8_t length = sizeof(chuoi) / sizeof(char);
    printf("%d\n", length);
    daochuoi(length, chuoi);

    // uint8_t arr[] = {2, 5, 6, 7, 1, 2, 9, 6, 7, 10, 1, 1, 9};
    // uint8_t length = sizeof(arr) / sizeof(uint8_t);

    // lietke(length, arr);

    // printf("Xuat mang la \n");
    // for (int i = 0; i < length; i++)
    // {

    //     printf("arr[%d] = %d\n", i, arr[i]);
    // }

    return 0;
}
