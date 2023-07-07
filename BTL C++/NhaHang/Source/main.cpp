#include "NhaHang.h"


int main(int argc, char const *argv[])
{

    cout << "    Lua chon " << endl;
    cout << " 1. Quan ly" << endl;
    cout << " 2. Nhan vien" << endl;
    cout << " 0. Quay lai" << endl;
    int value;
    cout << "-----------------------" << endl;
    cout << " Nhap lua chon: ";
    cin >> value;
    switch (value)
    {
    case 0:
        cout << "Da ket thuc chuong trinh";
        break;
    case 1:
        QuanLy quanly;
        break;
    case 2:
        NhanVien nhanvien;
        break;
    default:
        cout << "Ban da nhap sai";
        break;
    }

    return 0;
}
