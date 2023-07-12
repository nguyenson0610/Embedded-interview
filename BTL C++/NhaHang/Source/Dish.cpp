/*
 * File: Dish.cpp
 * Author: Nguyen Hoang Son
 * Date: 11/07/2023
 * Description: This is a Dish.cpp file for create a dish list include: ID, name, price
 */
#include "Dish.hpp"

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
