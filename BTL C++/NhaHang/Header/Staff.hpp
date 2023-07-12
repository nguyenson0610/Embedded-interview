/*
* File: Staff.h
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a Staff.h file for staff
*/

#ifndef __STAFF_H__
#define __STAFF_H__

#include "Dish.hpp"
#include "Table.hpp"
#include <list>
using namespace std;

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
