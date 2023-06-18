#include <iostream>
#include <string>

using namespace std;

class DoiTuong
{
protected:
   int tuoi;
   string ten;
   
public:
    void setThongTin(int tuoi,string ten);
    void HienThi();
    static int lop;
};

// Khoi tao lan dau cho bien static
int DoiTuong::lop;

void DoiTuong::setThongTin(int tuoi, string ten){
    DoiTuong::tuoi = tuoi;
    DoiTuong::ten = ten;
}

void DoiTuong::HienThi(){
    cout<<"Tuoi "<<tuoi<<endl;
    cout<<"Ten "<<ten<<endl;
}

//Tinh Ke thua
class Sinhvien : public DoiTuong{
    private:
        int mssv;
    public:
        void setThongTin(int tuoi, string ten, int mssv);
        void HienThi();
};

void Sinhvien::setThongTin(int tuoi, string ten, int mssv){
    Sinhvien::tuoi = tuoi;
    Sinhvien::ten = ten;
    Sinhvien::mssv = mssv;
}

void Sinhvien::HienThi(){
    cout<<"Ten la "<<tuoi<<endl;
    cout<<"Ten la "<<ten<<endl;
    cout<<"MSSV la "<<mssv<<endl;
}

template<typename var>

var tong(var a, var b){
    return (var)(a+b);
}



int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.setThongTin(78,"An");
    dt.HienThi();

    Sinhvien sv;
    sv.setThongTin(23,"Toan",1914955);
    sv.HienThi();

    return 0;
}
