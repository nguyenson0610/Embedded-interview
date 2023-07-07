#ifndef __NHAHANG_H__
#define __NHAHANG_H__
#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class MonAn
{
private:
    int ID;
    string TEN;
    float GIA;

public:
    MonAn();
    void setTen(string ten);
    void setGia(float gia);
    int getID();
    string getTen();
    float getGia();
    void HienThi();
};

class QuanLy
{
private:
    int choose;
    string TEN;
    float GIA;
    int soBan;
    list<MonAn> Database;
    void ThucHien();
    void ThemMon();
    void SuaMon();
    void HienthiDS();
    void XoaMon();
    void ThietLapSoBan();

public:
    QuanLy();
    int getSoBan();
    list<MonAn> getDatabase();
};

class ThongTinBan
{
private:
    int soBan;
    bool trangthai;
    typedef struct
    {
        MonAn Mon_An;
        int soLuong;

    } TypeMon;
    list<TypeMon> Database_MonAn;

public:
    ThongTinBan(int soBan, bool trangThai);
    int getSoBan();
    void setTrangThai(bool TrangThai);
    bool getTrangThai();
    void DanhSachMon();
    void ThemMon();
    void SuaMon();
    void XoaMon();
    void ThanhToan();
};

class NhanVien
{
private:
    list<MonAn> DATABASE_MON_AN;
    list<ThongTinBan> DATABASE_BAN;
    void themmon();
    void suamon();
    void xoamon();
    void thanhtoan();
    void LuachonBan();

public:
    NhanVien(list<MonAn> database, int soban);
};

#endif
