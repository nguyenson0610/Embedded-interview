/*
* File: Dish.h
* Author: Nguyen Hoang Son
* Date: 11/07/2023
* Description: This is a Dish.h file for set food information
*/
#ifndef __DISH_H__
#define __DISH_H__
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

#endif
