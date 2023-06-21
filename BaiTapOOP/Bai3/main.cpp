#include <iostream>

class Circle{
    private:
        uint8_t BanKinh;
    public:
        Circle(uint8_t R = 0);
        uint8_t getBankinh();
        float ChuVi();
        float DienTich();
};

Circle::Circle(uint8_t R){
    BanKinh = R;
}

uint8_t Circle::getBankinh(){
    printf("Nhap ban kinh la ");
    scanf("%d", &BanKinh);
    return BanKinh;
}

float Circle::ChuVi(){
    return 3.14 * 2.00* BanKinh;
}

float Circle::DienTich(){
    return 3.14*BanKinh*BanKinh;
}

int main(int argc, char const *argv[])
{
    Circle Hinhtron;
    Hinhtron.getBankinh();
    printf("Chu vi la %f\n", Hinhtron.ChuVi());
    printf("Dien tich la %f\n", Hinhtron.DienTich());
    return 0;
}
