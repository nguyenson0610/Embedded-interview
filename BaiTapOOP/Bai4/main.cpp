#include <iostream>
#include <string>

using namespace std;

class DongVat{
    private:
        string ten;
        uint8_t tuoi;
        uint8_t trongluong;
        float chieucao;
    public:
        void setThongtin(string ten, uint8_t tuoi, uint8_t trongluong, float chieucao);
        uint8_t getTuoi();
        uint8_t getTrongLuong();
        string getTen();
        float getChieucao();
};

void DongVat::setThongtin(string ten, uint8_t tuoi, uint8_t trongluong, float chieucao){
    DongVat::ten = ten;
    DongVat::tuoi = tuoi;
    DongVat::trongluong = trongluong;
    DongVat::chieucao = chieucao;
}

uint8_t DongVat::getTuoi(){
    return DongVat::tuoi;
}

uint8_t DongVat::getTrongLuong(){
    return DongVat::trongluong;
}

string DongVat::getTen(){
    return DongVat::ten;
}

float DongVat::getChieucao(){
    return DongVat::chieucao;
}

class ThucHien{
    private:
        DongVat Dv1;
        DongVat Dv2;
        typedef enum{
            CHI_SO_BMI,
            SO_SANH_TUOI,
            SO_SANH_TRONG_LUONG
        } Luachon;
        Luachon LuaChon;
    public:
        ThucHien(DongVat Dv1, DongVat Dv2);
        ThucHien(DongVat Dv1);
        float getBMI();
        void SoSanhTuoi();
        void SoSanhTrongLuong();
};

ThucHien::ThucHien(DongVat Dv1, DongVat Dv2){
    ThucHien::Dv1 = Dv1;
    ThucHien::Dv2 = Dv2;
}

ThucHien::ThucHien(DongVat Dv1){
    LuaChon = CHI_SO_BMI;
    ThucHien::Dv1 = Dv1;
}

float ThucHien::getBMI(){
    if (LuaChon == CHI_SO_BMI)
    {
        return Dv1.getTrongLuong()/(Dv1.getChieucao() * Dv1.getChieucao());
    }else
    {
        cout<<"Khong tinh duoc chi so BM1"<<endl;
    }
}

void ThucHien::SoSanhTuoi(){
    if (Dv1.getTuoi() > Dv2.getTuoi())
    {
        cout<<""<<Dv1.getTen()<<" lon tuoi hon "<<Dv2.getTen()<<endl;
    }else if (Dv1.getTuoi() < Dv2.getTuoi())
    {
        cout<<""<<Dv1.getTen()<<" nho tuoi hon "<<Dv2.getTen()<<endl;
    }else
    {
        cout<<""<<Dv1.getTen()<<" bang tuoi "<<Dv2.getTen()<<endl;
    }
    
}

void ThucHien::SoSanhTrongLuong(){
    if (Dv1.getTrongLuong() > Dv2.getTrongLuong())
    {
        cout<<""<<Dv1.getTen()<<" nang hon "<<Dv2.getTen()<<endl;
    }else if (Dv1.getTrongLuong() < Dv2.getTrongLuong())
    {
        cout<<""<<Dv1.getTen()<<" nhe hon "<<Dv2.getTen()<<endl;
    }else
    {
        cout<<""<<Dv1.getTen()<<" nang bang "<<Dv2.getTen()<<endl;
    }
}

int main(int argc, char const *argv[])
{
    DongVat DV1, DV2;
    DV1.setThongtin("TRAU", 10, 99, 1.32);
    DV2.setThongtin("CUU", 4, 25, 0.81);
    ThucHien TimKiem(DV1, DV2);
    ThucHien XacDinh(DV1);
    TimKiem.SoSanhTrongLuong();
    cout<<"Chi so BMI cua "<<DV1.getTen()<<" la "<<XacDinh.getBMI()<<endl;
    return 0;
}
