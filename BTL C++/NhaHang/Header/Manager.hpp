/*
* File: Manager.h
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a Manager.h file for manager set food information and table number
*/
#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "Dish.hpp"
#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

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

#endif
