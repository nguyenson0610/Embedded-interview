#include <iostream>
#include <string>

using namespace std;

class Car{
    private:
        string color;
        string kieuDongco;
        static int soKm;
    public:
        void setThongtin(string color, string kieuDongco, int soKm);
        void getThongtin();
        int getSoKm();
        float chiphibaotri();
};

int Car::soKm = 0;

void Car::setThongtin(string color, string kieuDongco, int soKm){
    Car::color = color;
    Car::kieuDongco = kieuDongco;
    Car::soKm = soKm;
}

void Car::getThongtin(){
    cout<<"Mau cua o to la "<<Car::color<<endl;
    cout<<"Kieu dong co cua o to la "<<Car::kieuDongco<<endl;
    cout<<"So km da di la "<<Car::soKm<<endl;
}

int Car::getSoKm(){
    return Car::soKm;
}



int main(int argc, char const *argv[])
{
    Car car;
    car.setThongtin("White", "Dong co chu V", 5555);
    car.getThongtin();
    cout<<"So km la "<<car.getSoKm()<<endl;
    return 0;
}
