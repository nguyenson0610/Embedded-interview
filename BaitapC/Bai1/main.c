#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

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

// Dem so lan xuat hien
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
                count = 0;
            }
        }
        else
        {
            for (int j = i + 1; j < i + 1 + count; j++)
            {
                printf("%c", chuoi[j]);
            }
            printf(" ");
            count = 0;
        }
    }
}

typedef struct
{
    char *array;
    uint8_t size;
} Words;

Words words[100];

void splitArray(char arr[])
{
    int index = 0;
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (arr[i] == ' ' || arr[i] == ',' || arr[i] == '.')
        {
            Words word;
            word.size = count;
            word.array = (arr[i - count]);
            words[index] = word;
            index++;
            count = 0;
        }
        else
        {
            count++;
        }
    }
}

bool isEqual(const char arr1[], const char arr2[])
{
    int i = 0;
    uint8_t length1, length2;
    length1 = sizeof(arr1) / sizeof(char);
    for (int i = 0; i < length1; i++)
    {
        if (arr1[i] == arr2[i])
        {
            if (i == length1 - 1)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
}

void ketqua(Words words[])
{
    
    
    for (int i = 0; i < 100; i++)
    {
        
        int count = 0;
        for (int j = 1; j < 100; j++)
        {
            
            if (words[i].size == words[j].size)
            {
                if (isEqual(words[i].array, words[j].array) == 1)
                {
                    count++;
                }
            }
        }
        
        printf("Ki tu %c xuat hien %d lan\n", words[i].array, count);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    char arr1[] = "HXin";
    char arr2[] = "Xin";
    char chuoi[] = "Xin Chao ban Rat vui khi duoc lam quen.";
    uint8_t length = sizeof(chuoi) / sizeof(char);
    printf("%d\n", length);
    daochuoi(length, chuoi);
    splitArray(chuoi);
    ketqua(words);

    // for (int i = 0; i <= words[0].size; i++)
    // {
    //     printf("\nki tu la %c", ((words[0].array) + i));
    // }

    // printf("\n%d\n", isEqual(*(words[0].array), *(words[1].array)));
    // printf("%s\n", words[0].array);

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
