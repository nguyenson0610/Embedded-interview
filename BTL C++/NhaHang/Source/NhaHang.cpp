#include "NhaHang.h"

// Mon An
MonAn::MonAn()
{
    static int id = 100;
    ID = id;
    id++;
}

int MonAn::getID()
{
    return ID;
}

void MonAn::setTen(string ten)
{
    MonAn::TEN = ten;
}

string MonAn::getTen()
{
    return MonAn::TEN;
}

void MonAn::setGia(float gia)
{
    MonAn::GIA = gia;
}

float MonAn::getGia()
{
    return MonAn::GIA;
}

void MonAn::HienThi()
{
    cout << "-----------------------" << endl;
    cout << " ID     Ten          Gia  " << endl;
    cout << " " << MonAn::getID() << "      " << MonAn::getTen() << "     " << MonAn::getGia() << endl;
}

//    Quan ly

QuanLy::QuanLy()
{
    cout << "    QUAN LY" << endl;
    cout << " 1. Them mon" << endl;
    cout << " 2. Sua mon" << endl;
    cout << " 3. Xoa mon" << endl;
    cout << " 4. Danh sach mon" << endl;
    cout << " 5. Thiet lap so ban" << endl;
    cout << " 0. Quay lai" << endl;
    cout << "--------------------------" << endl;

    int key = 0;
    do
    {
        cout << "Nhap lua chon de quan ly: ";
        cin >> key;
    } while (key > 6 && key < 0);
    switch (key)
    {
    case 1:
        ThemMon();
        break;
    case 2:
        SuaMon();
        break;
    case 3:
        XoaMon();
        break;
    case 4:
        HienthiDS();
        break;
    case 5:
        ThietLapSoBan();
        break;
    case 0:
        QuanLy();
        break;
    }
}

list<MonAn> QuanLy::getDatabase()
{
    return this->Database;
}

void QuanLy::ThemMon()
{
    MonAn Mon;
    string ten;
    cout << "--------------------------" << endl;
    cout << " Nhap ten mon la ";
    cin >> ten;
    Mon.setTen(ten);
    float gia;
    cout << " Nhap gia = ";
    cin >> gia;
    Mon.setGia(gia);
    Database.push_back(Mon);
    int type;
    cout << "    " << endl;
    cout << "    Lua chon" << endl;
    cout << " 1. Tiep thuc them mon" << endl;
    cout << " 0. Quay lai" << endl;
    cout << " Nhap lua chon: ";
    cin >> type;
    if (type == 1)
    {
        QuanLy::ThemMon();
    }
    else if (type == 0)
    {
        QuanLy::HienthiDS();
        QuanLy();
    }
}

void QuanLy::HienthiDS()
{
    int STT = 1;
    cout << "-----------------------" << endl;
    cout << "  STT   ID     Ten          Gia  " << endl;
    for (auto item : Database)
    {
        cout << "  " << STT << "  " << item.getID() << "      " << item.getTen() << "     " << item.getGia() << endl;
        STT++;
    }
}

void QuanLy::SuaMon()
{
    QuanLy::HienthiDS();

    int ID;
    cout << "Nhap ID = ";
    cin >> ID;
    cout << "" << endl;
    cout << " 1. Sua ten" << endl;
    cout << " 2. Sua gia" << endl;
    cout << " 0. Quay lai" << endl;
    int index;
    cout << " Nhap vao: ";
    cin >> index;
    if (index == 1)
    {
        for (auto item : Database)
        {
            if (item.getID() == ID)
            {
                string changeTen;
                cout << " Nhap ten thay doi: ";
                cin >> changeTen;
                item.setTen(changeTen);
                cout << " Ban da doi ten thanh cong" << endl;
                QuanLy::HienthiDS();
                QuanLy();
            }
        }
    }
    else if (index == 2)
    {
        for (auto item : Database)
        {
            if (item.getID() == ID)
            {
                float changeGia;
                cout << " Nhap gia thay doi: ";
                cin >> changeGia;
                item.setGia(changeGia);
                cout << " Ban da doi gia thanh cong" << endl;
                QuanLy::HienthiDS();
                QuanLy();
            }
        }
    }
    else if (index == 0)
    {
        QuanLy();
    }
}

void QuanLy::XoaMon()
{
    QuanLy::HienthiDS();
    int ID;
    cout << "Nhap ID = ";
    cin >> ID;
    list<MonAn>::iterator position = Database.begin();

    for (auto item : Database)
    {
        position++;
        if (item.getID() == ID)
        {
            Database.erase(position);
        }
    }
    QuanLy::HienthiDS();
    QuanLy();
}

void QuanLy::ThietLapSoBan()
{
    cout << "" << endl;
    cout << " 1. Nhap so ban" << endl;
    cout << " 0. Quay lai" << endl;
    int soBan;
    cout << "Nhap lua chon: " << endl;
    cin >> soBan;
    if (soBan == 1)
    {
        cout << "Nhap so ban = " << endl;
        cin >> soBan;
        QuanLy();
    }
    else if (soBan == 0)
    {
        QuanLy();
    }
}

int QuanLy::getSoBan()
{
    return soBan;
}

// Thong Tin Ban

void ThongTinBan::DanhSachMon()
{
    cout << "Danh Sach mon an la" << endl;
    for (auto item : Database_MonAn)
    {
        cout << " " << item.Mon_An.getTen() << endl;
    }
}

void ThongTinBan::ThanhToan(){
    float TongTien = 0;
    cout<<"Tong gia tien: "<<endl;
    for (auto item : Database_MonAn)
    {

        TongTien += item.Mon_An.getGia() * item.soLuong;
    }
    
}

void ThongTinBan::ThemMon()
{
    MonAn mon;
    int soLuong;
    cout << "So luong = ";
    cin >> soLuong;
    TypeMon MON;
    MON.Mon_An = mon;
    MON.soLuong = soLuong;
    Database_MonAn.push_back(MON);
}

void ThongTinBan::SuaMon()
{
    int soLuong;
    int id;
    cout << "Nhap id = ";
    cin >> id;
    for (auto item : Database_MonAn)
    {
        if (item.Mon_An.getID() == id)
        {
            cout << "Nhap so luong = ";
            cin >> soLuong;
            item.soLuong = soLuong;
        }
    }
}

void ThongTinBan::XoaMon()
{
    int id;
    cout << "Nhap id = ";
    cin >> id;
    auto position = Database_MonAn.begin();
    for (auto item : Database_MonAn)
    {
        if (item.Mon_An.getID() == id)
        {
            Database_MonAn.erase(position);
        }
        position++;
    }
}

int ThongTinBan::getSoBan()
{
    return soBan;
}

void ThongTinBan::setTrangThai(bool TrangThai)
{
    trangthai = TrangThai;
}

bool ThongTinBan::getTrangThai()
{
    return trangthai;
}

//Nhan vien

NhanVien::NhanVien(list<MonAn> database, int soban)
{
    DATABASE_MON_AN.assign(database.begin(), database.end());
    for (int i = 1; i <= soban; i++)
    {
        ThongTinBan ban(i, false);
        DATABASE_BAN.push_back(ban);
    }

    cout << " Lua chon trong phan Nhan vien" << endl;
    cout << " 1. Them mon " << endl;
    cout << " 2. Sua mon " << endl;
    cout << " 3. Xoa mon " << endl;
    cout << " 4. Danh sach mon " << endl;
    cout << " 5. Thanh toan " << endl;
    cout << " 0. Quay lai " << endl;
    cout << "" << endl;
}

void NhanVien::LuachonBan()
{
    int soBan;
    cout << "Nhap so ban = ";
    cin >> soBan;
    for (auto item : DATABASE_BAN)
    {
        item.getSoBan() == soBan;
        int key;
        do
        {
            cout << "Nhap lua chon: ";
            cin >> key;
        } while (key > 5 && key < 0);
        switch (key)
        {
        case 1:
            themmon();
            break;
        case 2:
            suamon();
            break;
        case 3:
            xoamon();
            break;
        case 4:
            xoamon();
            break;
        case 5:
            thanhtoan();
            break;
        default:
            break;
        }
    }
}

void NhanVien::themmon()
{
    int soBan;
    cout << "Nhap so ban = ";
    cin >> soBan;
    for (auto item : DATABASE_BAN)
    {
        if (item.getSoBan() == soBan)
        {
            item.ThemMon();
        }
    }
}

void NhanVien::suamon()
{
    int soBan;
    cout << "Nhap so ban = ";
    cin >> soBan;
    for (auto item : DATABASE_BAN)
    {
        if (item.getSoBan() == soBan)
        {
            int id;
            cout << "Nhap id mon an: ";
            cin >> id;
            item.SuaMon();
        }
    }
}

void NhanVien::xoamon()
{
    int soBan;
    cout << "Nhap so ban = ";
    cin >> soBan;
    for (auto item : DATABASE_BAN)
    {
        if (item.getSoBan() == soBan)
        {
            item.XoaMon();
        }
    }
}

void NhanVien::thanhtoan()
{
    int soBan;
    cout << "Nhap so ban = ";
    cin >> soBan;
    for (auto item : DATABASE_BAN)
    {
        if (item.getSoBan() == soBan)
        {
            
            item.DanhSachMon();
            item.ThanhToan();
        }
    }
}


