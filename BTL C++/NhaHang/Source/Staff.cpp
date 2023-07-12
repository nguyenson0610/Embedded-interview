/*
* File: Staff.cpp
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a Staff.cpp file for staff 
*/
#include "Staff.hpp"

/*
* Class: Staff
* Description: this function use for 
*/

Staff::Staff(list<Dish> database, int numberTable)
{
    DATABASE_DISH.assign(database.begin(), database.end());
    for (int i = 1; i <= numberTable; i++)
    {
        TableInfomation table(i, false);
        DATABASE_TABLE.push_back(table);
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

/*
* Class: Staff
* Function: choiceTable
* Description: this function use for choice a table
* Input: Dont have input parameter
* Output: none
*/
void Staff::choiceTable()
{
    int numbertable;
    cout << "Nhap so ban = ";
    cin >> numbertable;
    for (auto item : DATABASE_TABLE)
    {
        item.getnumberTable() == numbertable;
        int key;
        do
        {
            cout << "Nhap lua chon: ";
            cin >> key;
        } while (key > 5 && key < 0);
        switch (key)
        {
        case 1:
            addDish();
            break;
        case 2:
            fixDish();
            break;
        case 3:
            deleteDish();
            break;
        case 4:
            Pay();
            break;
        default:
            break;
        }
    }
}

/*
* Class: Staff
* Function: choiceTable
* Description: this function use for add dish at a table
* Input: Dont have input parameter
* Output: none
*/
void Staff::addDish()
{
    int numberTable;
    cout << "Nhap so ban = ";
    cin >> numberTable;
    for (auto item : DATABASE_TABLE)
    {
        if (item.getnumberTable() == numberTable)
        {
            item.addDish();
        }
    }
}

/*
* Class: Staff
* Function: fixDish
* Description: this function use for fix dish at a table
* Input: Dont have input parameter
* Output: none
*/
void Staff::fixDish()
{
    int numberTable;
    cout << "Nhap so ban = ";
    cin >> numberTable;
    for (auto item : DATABASE_TABLE)
    {
        if (item.getnumberTable() == numberTable)
        {
            int id;
            cout << "Nhap id mon an: ";
            cin >> id;
            item.fixDish();
        }
    }
}

/*
* Class: Staff
* Function: deleteDish
* Description: this function use for delete dish at a table
* Input: Dont have input parameter
* Output: none
*/
void Staff::deleteDish()
{
    int numberTable;
    cout << "Nhap so ban = ";
    cin >> numberTable;
    for (auto item : DATABASE_TABLE)
    {
        if (item.getnumberTable() == numberTable)
        {
            item.deleteDish();
        }
    }
}

/*
* Class: Staff
* Function: Pay
* Description: this function use for pay bill at a table
* Input: Dont have input parameter
* Output: none
*/
void Staff::Pay()
{
    int numberTable;
    cout << "Nhap so ban = ";
    cin >> numberTable;
    for (auto item : DATABASE_TABLE)
    {
        if (item.getnumberTable() == numberTable)
        {
            
            item.DishList();
            item.Pay();
        }
    }
}
