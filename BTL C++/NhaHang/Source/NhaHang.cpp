/*
* File: NhaHang.cpp
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a NhaHang.cpp file for restaurant management
*/
#include "NhaHang.h"

/*
* Class: Dish
* Description: initialize ID value and increment when initialized
*/
Dish::Dish()
{
    static int id = 100;
    ID = id;
    id++;
}

/*
* Class: Dish
* Function: getID
* Description: this function use for get ID value of a dish
* Input: Dont have input parameter
* Output: return the ID value of a dish
*/
int Dish::getID()
{
    return ID;
}

/*
* Class: Dish
* Function: setName
* Description: this function use for set name of a dish
* Input: name - name of dish
* Output: none
*/
void Dish::setName(string name)
{
    Dish::Name = name;
}

/*
* Class: Dish
* Function: getName
* Description: this function use for get name of a dish
* Input: Dont have input parameter
* Output: return name of a dish
*/
string Dish::getName()
{
    return Dish::Name;
}

/*
* Class: Dish
* Function: setPrice
* Description: this function use for set price of a dish
* Input: price - price of a dish
* Output: none
*/
void Dish::setPrice(float price)
{
    Dish::Price = price;
}

/*
* Class: Dish
* Function: getPrice
* Description: this function use for get price of a dish
* Input: Dont have input parameter
* Output: return price of a dish
*/
float Dish::getPrice()
{
    return Dish::Price;
}

/*
* Class: Dish
* Function: Display
* Description: this function use for display list of dishes
* Input: Dont have input parameter
* Output: none
*/
void Dish::Display()
{
    cout << "-----------------------" << endl;
    cout << " ID     Ten          Gia  " << endl;
    cout << " " << Dish::getID() << "      " << Dish::getName() << "     " << Dish::getPrice() << endl;
}

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
        if (item.getnumberTable() == num_put)
        {
            
            item.DishList();
            item.Pay();
        }
    }
}
