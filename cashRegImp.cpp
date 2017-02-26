//
// Created by Adam on 2/26/2017.
//

/*
 * cashRegImp.cpp
 *
 *  Created on: Mar 14, 2014
 *      Author: Adam C. De Leon
 *      Class: CS2308
 *      Section: 1
 *      Roster: 6
 */
# include <iostream>
# include "CashReg.h"

using namespace std;

//Function Prototypes
//Default constructor.
cashRegister::cashRegister() {
    cashOnHand = 500;
}

//Constructor for specified amount.
cashRegister::cashRegister(int specified) {
    cashOnHand = specified;
}

//returns value of cash on hand.
int cashRegister::getCurrentBalance() {
    return cashOnHand;
}

//receives the amount deposited.
void cashRegister::acceptAmount(int deposit) {
    cashOnHand += deposit;
}

//sets cost and num of items to 50.
dispenserType::dispenserType() {
    numOfItems = 50;
    costOfItems = 50;
}

//sets num and cost of items to values by user.
dispenserType::dispenserType(int quantity, int price) {
    numOfItems = quantity;
    costOfItems = price;
}

//returns the value of the number of items.
int dispenserType::getNoOfItems() {
    return numOfItems;
}

//returns the value of cost.
int dispenserType::getCost() {
    return costOfItems;
}

//to reduce num of items by one.
void dispenserType::makeSale(int purchase) {
    purchase = 1;
    numOfItems -= purchase;
}
