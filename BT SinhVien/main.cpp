#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum
{
    NAM,
    NU
} TypeSex;

typedef enum
{
    GIOI,
    KHA,
    TRUNGBINH,
    YEU
} TypeHocLuc;

class SinhVien
{
private:
    uint8_t ID;
    string ten;
    TypeSex GIOI_TINH;
    int tuoi;
    float diemToan;
    float diemHoa;
    float diemLy;
    TypeHocLuc HOC_LUC;

public:
    SinhVien(string ten, TypeSex gioitinh, int tuoi, float diemToan, float diemHoa, float diemLy);
    string getHocLuc();
    int getId();
    float getDiemTB();
    void getThongTin();
    void changeThongTin();
    string getTen();
};

SinhVien::SinhVien(string ten, TypeSex gioitinh, int tuoi, float diemToan, float diemHoa, float diemLy)
{
    SinhVien::ten = ten;
    SinhVien::GIOI_TINH = gioitinh;
    SinhVien::tuoi = tuoi;
    SinhVien::diemToan = diemToan;
    SinhVien::diemHoa = diemHoa;
    SinhVien::diemLy = diemLy;
    static uint8_t id = 100;
    ID = id;
    id++;
}

int SinhVien::getId()
{
    return SinhVien::ID;
}

string SinhVien::getTen(){
    return SinhVien::ten;
}

float SinhVien::getDiemTB()
{
    return (SinhVien::diemToan + SinhVien::diemHoa + SinhVien::diemLy) / 3;
}

string SinhVien::getHocLuc()
{
    if (SinhVien::getDiemTB() >= 8)
    {
        return "GIOI";
    }
    else if (SinhVien::getDiemTB() >= 6.5)
    {
        return "KHA";
    }
    else if (SinhVien::getDiemTB() >= 5)
    {
        return "TRUNGBINH";
    }
    else
    {
        return "YEU";
    }
}

void SinhVien::getThongTin()
{
    cout << "Ten: " << SinhVien::ten << endl;
    cout << "Gioi tinh: " << SinhVien::GIOI_TINH << endl;
    cout << "Tuoi: " << SinhVien::tuoi << endl;
    cout << "Diem ly: " << SinhVien::diemLy << endl;
    cout << "Diem hoa: " << SinhVien::diemHoa << endl;
    cout << "Diem toan: " << SinhVien::diemToan << endl;
    cout << "Diem trung binh: " << SinhVien::getDiemTB() << endl;
}

void SinhVien::changeThongTin(){
    string change;
    cout<<"Nhap thong tin muon thay doi: ";
    cin>>change;
    if (change == "TEN")
    {
        string TEN;
        cout<<"Nhap ten ";
        cin>>TEN;
        SinhVien::ten = TEN;
    }else if (change == "GT")
    {
        string GT;
        cout<<"Nhap gioi tinh la ";
        cin>>GT;
        if (GT == "NAM")
        {
            SinhVien::GIOI_TINH = NAM;
        }else
        {
            SinhVien::GIOI_TINH = NU;
        }
        
    }else if (change == "TUOI")
    {
        int TUOI;
        cout<<"Nhap tuoi la ";
        cin>>TUOI;
        SinhVien::tuoi = TUOI;
    }else if (change == "TOAN")
    {
        float TOAN;
        cout<<"Nhap diem toan la ";
        cin>>TOAN;
        SinhVien::diemToan = TOAN;
    }else if (change == "LY")
    {
        float LY;
        cout<<"Nhap diem ly la ";
        cin>>LY;
        SinhVien::diemLy = LY;
    }else if (change == "HOA")
    {
        float HOA;
        cout<<"Nhap diem hoa la ";
        cin>>HOA;
        SinhVien::diemHoa = HOA;
    }
    
    
    
    
}

class Menu
{
private:
    list<SinhVien> Database;

public:
    void themSinhVien();
    void capNhatThongTin();
    void XoaSinhVien();
    void findSinhVien();
    void sapxeptheoGPA();
    void sapxeptheoTen();
    void hienthiDanhSach();
};

void Menu::themSinhVien()
{
    string ten;
    int tuoi;
    string gt;
    TypeSex gioitinh;
    float diemtoan;
    float diemly;
    float diemhoa;
    cout << "Nhap ten la ";
    cin >> ten;
    cout << "Nhap gioi tinh la ";
    cin >> gt;

    do
    {
        cout << "Nhap tuoi la ";
        cin >> tuoi;

    } while (tuoi < 0 || tuoi > 100);

    if (gt == "NAM")
    {
        gioitinh = NAM;
    }
    else if (gt == "NU")
    {
        gioitinh = NU;
    }

    do
    {
        cout << "Nhap diem toan la ";
        cin >> diemtoan;
    } while (diemtoan < 0 || diemtoan > 10);

    do
    {
        cout << "Nhap diem ly la ";
        cin >> diemly;
    } while (diemly < 0 || diemly > 10);

    do
    {
        cout << "Nhap diem hoa la ";
        cin >> diemhoa;
    } while (diemhoa < 0 || diemhoa > 10);

    SinhVien sv(ten, gioitinh, tuoi, diemtoan, diemhoa, diemly);
    Database.push_back(sv);
}

void Menu::capNhatThongTin()
{
    int id;
    cout << "Nhap id = ";
    cin >> id;
    for (auto item : Database)
    {
        if (item.getId() == id)
        {
            cout << "Da tim thay thong tin"<<endl;
            item.getThongTin();
            cout << "Cap nhat thong tin cho sinh vien" << endl;
            item.changeThongTin();
            item.getThongTin();
            break;
            
        }else{
            cout<<"Khong ton tai id = "<<id<<endl;
        }
    }

}

void Menu::XoaSinhVien(){
    int id;
    int index = 0;
    cout<<"Nhap id = "<<endl;
    cin>>id;
    auto itr = Database.begin();
    for (auto item : Database)
    {
        
        if (item.getId() == id)
        {
            cout << "Da tim thay sinh vien muon xoa"<<endl;
            Database.erase(itr);
            index = 1;
            break;
        }else{
            itr++;
        }
    }
    if (index == 0)
    {
        cout<<"Khong ton tai ID can tim"<<endl;
    }
    

}

void Menu::findSinhVien(){
    string TEN;
    int index = 0;
    cout<<"Nhap ten muon tim kiem ";
    cin>>TEN;
    for (auto item : Database)
    {
        if (item.getTen() == TEN)
        {
            cout<<"Da tim thay ten "<<endl;
            cout<<"Thong tin sinh vien tim kiem la"<<endl;
            item.getThongTin();
            index = 1;
            break;
        }
        
    }
    if (index == 0)
    {
        cout<<"Khong ton tai ten muon tim kiem";
    }
    
    
}

void Menu::sapxeptheoGPA(){
    
    for (auto item : Database)
    {
        item.getDiemTB();
    }
    
}

void Menu::sapxeptheoTen(){

}

void Menu::hienthiDanhSach(){
    int i = 1;
    for (auto item : Database)
    {
        cout<<"   So thu tu: "<<i<<endl;
        item.getThongTin();
        i++;
    }
    
}


int main(int argc, char const *argv[])
{
    cout<<"****QUAN LY SINH VIEN****"<<endl;
    cout<<"           Menu          "<<endl;
    cout<<"1. Them sinh vien."<<endl;
    cout<<"2. Cap nhat thong tin sinh vien theo ID."<<endl;
    cout<<"3. Xoa sinh vien boi ID."<<endl;
    cout<<"4. Tim kiem sinh vien theo ten."<<endl;
    cout<<"5. Sap xep sinh vien theo diem GPA."<<endl;
    cout<<"6. Sap xep sinh vien theo ten."<<endl;
    cout<<"7. Hien thi danh sach sinh vien."<<endl;
    Menu Choose;
    int i;
    cout<<"Nhap lua chon: ";
    cin>>i;
    switch (i)
    {
    case 1:
        Choose.themSinhVien();
        break;
    case 2:
        Choose.capNhatThongTin();
    case 3:
        Choose.XoaSinhVien();
        break;
    case 4:
        Choose.findSinhVien();
        break;
    case 5:
        Choose.sapxeptheoGPA();
        break;
    case 6:
        Choose.sapxeptheoTen();
        break;
    case 7:
        Choose.hienthiDanhSach();
        break;
    default:
        cout<<"Ban da nhap sai !!!"<<endl;
        break;
    }
    return 0;
}
