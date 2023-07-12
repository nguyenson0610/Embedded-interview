/*
* File: Table.h
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a table.h file for table information
*/

#ifndef __TABLE_H__
#define __TABLE_H__

#include "Dish.hpp"
#include <list>
#include <string>
using namespace std;

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


#endif
