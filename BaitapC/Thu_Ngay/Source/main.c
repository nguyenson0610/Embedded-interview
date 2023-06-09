#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    Thu2 = 2,
    Thu3 = 3,
    Thu4 = 4,
    Thu5 = 5,
    Thu6 = 6,
    Thu7 = 7,
    ChuNhat = 8
} Thu;

typedef enum
{
    Thang1 = 1,
    Thang2 = 2,
    Thang3 = 3,
    Thang4 = 4,
    Thang5 = 5,
    Thang6 = 6,
    Thang7 = 7,
    Thang8 = 8,
    Thang9 = 9,
    Thang10 = 10,
    Thang11 = 11,
    Thang12 = 12,
} Thang;

typedef struct typeDate
{
    uint8_t thu;
    uint8_t ngay;
    uint8_t thang;
    uint8_t nam;
} typeDate;

bool kiemtranamnhuan(typeDate Date)
{
    if ((Date.nam % 4 == 0 && Date.nam % 100 != 0) || Date.nam % 400 == 0)
    {
        return 1;
    }
    return 0;
}

int xacdinhsongay(typeDate Date, Thang thang)
{
    switch (thang)
    {
    case Thang1:
    case Thang3:
    case Thang5:
    case Thang7:
    case Thang8:
    case Thang10:
    case Thang12:
    {
        return 31;
        break;
    }
    case Thang2:
    {
        if (kiemtranamnhuan(Date))
        {
            return 29;
            break;
        }
        else
        {
            return 28;
            break;
        }
    }
    case Thang4:
    case Thang6:
    case Thang9:
    case Thang11:
    {
        return 30;
        break;
    }
    default:
        break;
    }
}

int timsongay(typeDate Date)
{
    // Chon ngay goc la 1/1/1 thu 2
    typeDate DateGoc;
    DateGoc.ngay = 1;
    DateGoc.thang = 1;
    DateGoc.nam = 1;
    int countNgay = 0;
    for (int i = DateGoc.nam; i < Date.nam; i++)
    {
        if (kiemtranamnhuan(Date))
        {
            countNgay = countNgay + 366;
        }
        else
        {
            countNgay = countNgay + 365;
        }
    }

    for (int i = DateGoc.thang; i < Date.thang; i++)
    {
        printf("aaa\n");
        countNgay = countNgay + xacdinhsongay(Date, i);
    }

    for (int i = DateGoc.ngay; i < Date.ngay; i++)
    {
        countNgay += 1;
    }

    return countNgay;
}

void timThu(typeDate Date)
{
    int tinhtoan;
    int temp;
    Thu xuatThu;
    tinhtoan = timsongay(Date);
    temp = tinhtoan % 7;
    xuatThu = Thu2 + temp;
    printf("Ngay %d thang %d nam %d la thu %d\n", Date.ngay, Date.thang, Date.nam, xuatThu);
}

int main(int argc, char const *argv[])
{
    // Nhap ngay muon tim
    typeDate Date;
    printf("Nhap ngay la ");
    scanf("%d", &(Date.ngay));
    printf("Nhap thang la ");
    scanf("%d", &(Date.thang));
    printf("Nhap nam la ");
    scanf("%d", &(Date.nam));

    timThu(Date);

    return 0;
}
