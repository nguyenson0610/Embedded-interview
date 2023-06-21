#include <iostream>
#include <math.h>

using namespace std;

class Rectangle{
    private:
        uint8_t Chieu_dai;
        uint8_t Chieu_rong;
    public:
        Rectangle(uint8_t dai = 0, uint8_t rong = 0);
        uint16_t getChieuDai();
        uint16_t getChieuRong();
        uint16_t ChuVi();
        uint16_t DienTich();
        uint16_t DuongCheo();
        void KiemtraHinhVuong();
};

Rectangle::Rectangle(uint8_t dai, uint8_t rong){
    Chieu_dai = dai;
    Chieu_rong = rong;
}

uint16_t Rectangle::getChieuDai(){
    uint16_t dai;
    printf("Nhap chieu dai la ");
    scanf("%d", &dai);
    Chieu_dai = dai;
    return Chieu_dai;
}

uint16_t Rectangle::getChieuRong(){
    uint16_t rong;
    printf("Nhap chieu rong la ");
    scanf("%d", &rong);
    Chieu_rong = rong;
    return Chieu_rong;
}

uint16_t Rectangle::ChuVi(){
    return 2*(Chieu_dai + Chieu_rong);
}

uint16_t Rectangle::DienTich(){
    return (Chieu_dai * Chieu_rong);
}

uint16_t Rectangle::DuongCheo(){
    return sqrt((Chieu_dai*Chieu_dai) + (Chieu_rong*Chieu_rong));
}

void Rectangle::KiemtraHinhVuong(){
    if (Chieu_dai == Chieu_rong)
    {
        printf("La hinh vuong\n");
    }else{
        printf("Khong la hinh vuong\n");
    }
    
}

int main(int argc, char const *argv[])
{
    Rectangle hcn;
    hcn.getChieuDai();
    hcn.getChieuRong();
    printf("Chu vi la %d\n", hcn.ChuVi());
    printf("Dien tich la %d\n", hcn.DienTich());
    printf("Duong cheo la %d\n", hcn.DuongCheo());
    hcn.KiemtraHinhVuong();
    return 0;
}
