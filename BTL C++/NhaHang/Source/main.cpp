/*
* File: main.cpp
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a main.cpp file for restaurant management
*/

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
        Manager manager;
        break;
    case 2:
        Staff staff;
        break;
    default:
        cout << "Ban da nhap sai";
        break;
    }

    return 0;
}
