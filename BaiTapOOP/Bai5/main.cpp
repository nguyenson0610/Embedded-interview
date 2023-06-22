#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class Person{
    private:
        string ten;
        uint8_t tuoi;
        string diachi;
    public:
        void setThongTin(string Ten, uint8_t Tuoi, string DiaChi);
        void getThongTin();
};

void Person::setThongTin(string Ten, uint8_t Tuoi, string DiaChi){
    ten = Ten;
    tuoi = Tuoi;
    diachi = DiaChi;
}

void Person::getThongTin(){
    cout<<"Ten la "<<Person::ten<<endl;
    printf("Tuoi la %d\n", Person::tuoi);
    cout<<"Dia chi la "<<Person::diachi<<endl;

}



int main(int argc, char const *argv[])
{
    Person person;
    person.setThongTin("Tien", 21, "Quan an Nong Lam");
    person.getThongTin();
    return 0;
}
