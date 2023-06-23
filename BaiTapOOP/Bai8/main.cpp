#include <iostream>
#include <string>

using namespace std;

class TaiKhoanNganHang{
    private:
        string soTK;
        string tenTK;
        float sodu;

    public:
        void setThongtin(string so, string ten, float du);
        float rutTien(float tien);
        float nopTien(float tien);
        float Kiemtrasodu();
        
};


void TaiKhoanNganHang::setThongtin(string so, string ten, float du){
    soTK = so;
    tenTK = ten;
    sodu = du;
}

float TaiKhoanNganHang::rutTien(float tien){
    sodu = sodu-tien;
    return sodu;
}

float TaiKhoanNganHang::nopTien(float tien){
    sodu = sodu + tien;
    return sodu;
}

float TaiKhoanNganHang::Kiemtrasodu(){
    return sodu;
}


int main(int argc, char const *argv[])
{
    TaiKhoanNganHang TaiKhoan;
    TaiKhoan.setThongtin("19145236", "Tien", 5000000);
    TaiKhoan.rutTien(3000000);
    printf("So du hien tai la %0.1f\n", TaiKhoan.Kiemtrasodu());
    TaiKhoan.nopTien(2500000);
    printf("So du hien tai la %0.1f\n", TaiKhoan.Kiemtrasodu());
    return 0;
}
