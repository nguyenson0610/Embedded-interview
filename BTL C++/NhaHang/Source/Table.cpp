/*
* File: Table.cpp
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a Table.cpp file for set table information
*/
#include "Staff.hpp"

/*
* Class: TableInfomation
* Function: DishList
* Description: this function use for display list of dishes
* Input: Dont have input parameter
* Output: none
*/
void TableInfomation::DishList()
{
    cout << "Danh Sach mon an la" << endl;
    for (auto item : Database_Dish)
    {
        cout << " " << item.dish.getName() << endl;
    }
}

/*
* Class: TableInfomation
* Function: Pay
* Description: this function use for pay the bill
* Input: Dont have input parameter
* Output: none
*/
void TableInfomation::Pay(){
    float Total = 0;
    cout<<"Tong gia tien: "<<endl;
    for (auto item : Database_Dish)
    {

        Total += item.dish.getPrice() * item.quantity;
    }
    
}

/*
* Class: TableInfomation
* Function: addDish
* Description: this function use for add a dish at this table
* Input: Dont have input parameter
* Output: none
*/
void TableInfomation::addDish()
{
    Dish dish;
    int quantity;
    cout << "So luong = ";
    cin >> quantity;
    TypeDish DISH;
    DISH.dish = dish;
    DISH.quantity = quantity;
    Database_Dish.push_back(DISH);
}

/*
* Class: TableInfomation
* Function: fixDish
* Description: this function use for fix a dish at this table
* Input: Dont have input parameter
* Output: none
*/
void TableInfomation::fixDish()
{
    int quantity;
    int id;
    cout << "Nhap id = ";
    cin >> id;
    for (auto item : Database_Dish)
    {
        if (item.dish.getID() == id)
        {
            cout << "Nhap so luong = ";
            cin >>quantity;
            item.quantity = quantity;
        }
    }
}

/*
* Class: TableInfomation
* Function: deleteDish
* Description: this function use for delete a dish at this table
* Input: Dont have input parameter
* Output: none
*/
void TableInfomation::deleteDish()
{
    int id;
    cout << "Nhap id = ";
    cin >> id;
    auto position = Database_Dish.begin();
    for (auto item : Database_Dish)
    {
        if (item.dish.getID() == id)
        {
            Database_Dish.erase(position);
        }
        position++;
    }
}

/*
* Class: TableInfomation
* Function: getnumberTable
* Description: this function use for number table
* Input: Dont have input parameter
* Output: return number of table
*/
int TableInfomation::getnumberTable()
{
    return numberTable;
}

/*
* Class: TableInfomation
* Function: setStatus
* Description: this function use for set status of a table
* Input: Dont have input parameter
* Output: none
*/
void TableInfomation::setStatus(bool status)
{
    TableInfomation::status = status;
}

/*
* Class: TableInfomation
* Function: getStatus
* Description: this function use for get status of a table
* Input: Dont have input parameter
* Output: return status of a table
*/
bool TableInfomation::getStatus()
{
    return status;
}
