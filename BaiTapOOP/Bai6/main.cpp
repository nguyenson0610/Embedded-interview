#include <iostream>

class Phanso{
    private:
        uint8_t tuso;
        uint8_t mauso;
    public:
        void setTuso(uint8_t tu);
        uint8_t getTuso();
        void setMauso(uint8_t mau);
        uint8_t getMauso();
        
};

void Phanso::setTuso(uint8_t tu){
    tuso = tu;
}

uint8_t Phanso::getTuso(){
    return Phanso::tuso;
}

void Phanso::setMauso(uint8_t mau){
    mauso = mau;
}

uint8_t Phanso::getMauso(){
    return Phanso::mauso;
}

class PhepToan{
    private:
        Phanso phanso1;
        Phanso phanso2;
    public:
        PhepToan(Phanso phanso1, Phanso phanso2);
        float cong();
        float tru();
        float nhan();
        float chia();
};

PhepToan::PhepToan(Phanso phanso1, Phanso phanso2){
    PhepToan::phanso1 = phanso1;
    PhepToan::phanso2 = phanso2;
}

float PhepToan::cong(){
    return (float)(phanso1.getTuso() * phanso2.getMauso() + phanso2.getTuso()*phanso1.getMauso())/(phanso1.getMauso()*phanso2.getMauso());
}

float PhepToan::tru(){
    return (float)(phanso1.getTuso() * phanso2.getMauso() - phanso2.getTuso()*phanso1.getMauso())/(phanso1.getMauso()*phanso2.getMauso());
}

float PhepToan::nhan(){
    return (float)( phanso1.getTuso() * phanso2.getTuso())/ ( phanso1.getMauso() * phanso2.getMauso());
}

float PhepToan::chia(){
    return (float)(phanso1.getTuso() * phanso2.getMauso())/ ( phanso1.getMauso() * phanso2.getTuso());
}


int main(int argc, char const *argv[])
{
    Phanso ps1, ps2;
    ps1.setTuso(5);
    ps1.setMauso(3);
    ps2.setTuso(1);
    ps2.setMauso(4);
    PhepToan toan(ps1,ps2);
    printf("Phep cong la %f\n", toan.cong());
    printf("Phep tru la %f\n", toan.tru());
    printf("Phep nhan la %f\n", toan.nhan());
    printf("Phep chia la %f\n", toan.chia());
    return 0;
}
