
/*
* File: Manager.cpp
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a Manager.cpp file for restaurant management
*/

#include "Manager.hpp"
/*
* Class: Manager
* Description: choice methods
*/
Manager::Manager()
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
        addDish();
        break;
    case 2:
        fixDish();
        break;
    case 3:
        deleteDish();
        break;
    case 4:
        displayDishList();
        break;
    case 5:
        setTableNumber();
        break;
    case 0:
        Manager();
        break;
    }
}

/*
* Class: Manger
* Function: getDatabase
* Description: this function use for get database of dishes
* Input: Dont have input parameter
* Output: return database of dishes
*/
list<Dish> Manager::getDatabase()
{
    return this->Database;
}

/*
* Class: Manager
* Function: addDish
* Description: this function use for add dishes
* Input: Dont have input parameter
* Output: none
*/
void Manager::addDish()
{
    Dish dish;
    string name;
    cout << "--------------------------" << endl;
    cout << " Nhap ten mon la ";
    cin >> name;
    dish.setName(name);
    float price;
    cout << " Nhap gia = ";
    cin >> price;
    dish.setPrice(price);
    Database.push_back(dish);
    int type;
    cout << "    " << endl;
    cout << "    Lua chon" << endl;
    cout << " 1. Tiep thuc them mon" << endl;
    cout << " 0. Quay lai" << endl;
    cout << " Nhap lua chon: ";
    cin >> type;
    if (type == 1)
    {
        Manager::addDish();
    }
    else if (type == 0)
    {
        Manager::displayDishList();
        Manager();
    }
}

/*
* Class: Manager
* Function: displayDishList
* Description: this function use for display list of dishes
* Input: Dont have input parameter
* Output: none
*/
void Manager::displayDishList()
{
    int STT = 1;
    cout << "-----------------------" << endl;
    cout << "  STT   ID     Ten          Gia  " << endl;
    for (auto item : Database)
    {
        cout << "  " << STT << "  " << item.getID() << "      " << item.getName() << "     " << item.getPrice() << endl;
        STT++;
    }
}

/*
* Class: Manager
* Function: fixDish
* Description: this function use for fix of a dish includes: price or name
* Input: Dont have input parameter
* Output: none
*/
void Manager::fixDish()
{
    Manager::displayDishList();

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
                string changeName;
                cout << " Nhap ten thay doi: ";
                cin >> changeName;
                item.setName(changeName);
                cout << " Ban da doi ten thanh cong" << endl;
                Manager::displayDishList();
                Manager();
            }
        }
    }
    else if (index == 2)
    {
        for (auto item : Database)
        {
            if (item.getID() == ID)
            {
                float changePrice;
                cout << " Nhap gia thay doi: ";
                cin >> changePrice;
                item.setPrice(changePrice);
                cout << " Ban da doi gia thanh cong" << endl;
                Manager::displayDishList();
                Manager();
            }
        }
    }
    else if (index == 0)
    {
        Manager();
    }
}

/*
* Class: Manager
* Function: deleteDish
* Description: this function use for delete of a dish includes: price and name
* Input: Dont have input parameter
* Output: none
*/
void Manager::deleteDish()
{
    Manager::displayDishList();
    int ID;
    cout << "Nhap ID = ";
    cin >> ID;
    list<Dish>::iterator position = Database.begin();

    for (auto item : Database)
    {
        position++;
        if (item.getID() == ID)
        {
            Database.erase(position);
        }
    }
    Manager::displayDishList();
    Manager();
}

/*
* Class: Manager
* Function: setTableNumber
* Description: this function use for set the table number
* Input: Dont have input parameter
* Output: none
*/
void Manager::setTableNumber()
{
    cout << "" << endl;
    cout << " 1. Nhap so ban" << endl;
    cout << " 0. Quay lai" << endl;
    int tableNumber;
    cout << "Nhap lua chon: " << endl;
    cin >> tableNumber;
    if (tableNumber == 1)
    {
        cout << "Nhap so ban = " << endl;
        cin >> tableNumber;
        Manager();
    }
    else if (tableNumber == 0)
    {
        Manager();
    }
}

/*
* Class: Manager
* Function: getTableNumber
* Description: this function use for get number of a table
* Input: Dont have input parameter
* Output: return number of a table
*/
int Manager::getTableNumber()
{
    return tableNumber;
}
