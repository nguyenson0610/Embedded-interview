/*
* File: NhaHang.h
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a NhaHang.h file for restaurant management
*/
#ifndef __NHAHANG_H__
#define __NHAHANG_H__
#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

/************************************Class Dish**************************************/
/*
* Class: Dish
* Description: include properties and methods of class Dish
*/
class Dish
{
private:
    int ID;
    string Name;
    float Price;

public:
    Dish();
    void setName(string name);
    void setPrice(float price);
    int getID();
    string getName();
    float getPrice();
    void Display();
};

/************************************Class Manager**************************************/
/*
* Class: Manager
* Description: include properties and methods of class Manager
*/
class Manager
{
private:
    int choose;
    string NAME;
    float PRICE;
    int tableNumber;
    list<Dish> Database;
    void Perform();
    void addDish();
    void fixDish();
    void displayDishList();
    void deleteDish();
    void setTableNumber();

public:
    Manager();
    int getTableNumber();
    list<Dish> getDatabase();
};

/************************************Class TableInfomation**************************************/
/*
* Class: TableInfomation
* Description: include properties and methods of class TableInfomation
*/
class TableInfomation
{
private:
    int numberTable;
    bool status;
    typedef struct
    {
        Dish dish;
        int quantity;

    } TypeDish;
    list<TypeDish> Database_Dish;

public:
    TableInfomation(int numberTable, bool status);
    int getnumberTable();
    void setStatus(bool TrangThai);
    bool getStatus();
    void DishList();
    void addDish();
    void fixDish();
    void deleteDish();
    void Pay();
};

/************************************Class Staff**************************************/
/*
* Class: Staff
* Description: include properties and methods of class Staff
*/
class Staff
{
private:
    list<Dish> DATABASE_DISH;
    list<TableInfomation> DATABASE_TABLE;
    void addDish();
    void fixDish();
    void deleteDish();
    void Pay();
    void choiceTable();

public:
    Staff(list<Dish> database, int tableNumber);
};

#endif
