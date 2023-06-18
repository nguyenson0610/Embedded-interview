#include <iostream>

using namespace std;

// Tinh dong goi va Tính truu tuong
class ToanHoc{
    public:
        void nhapABC();
        void XuatX1X2();
    private:
        int A;
        int B;
        int C;
        int X1;
        int X2;
        int delta;
        int getdelta;
};

// Tinh da hinh
template<typename var>

var tong(var a, var b){
    return (var)(a+b);
}

// namespace
namespace ConOngA{
    int a = 10;
}

namespace ConOngB{
    int a = 20;
}

int main(int argc, char const *argv[])
{
    cout<<"a = "<<ConOngA::a<<endl;
    cout<<"a = "<<ConOngB::a<<endl;
    return 0;
}
