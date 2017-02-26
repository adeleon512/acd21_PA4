//
// Created by Adam on 2/26/2017.
//

#ifndef ACD21_PA4_CASHREG_H
#define ACD21_PA4_CASHREG_H

/*
 * CashReg.h
 *
 *  Created on: Mar 14, 2014
 *      Author: Adam C. De Leon
 *      Class: CS2308
 *      Section: 1
 *      Roster: 6
 *      Program: 4
 */

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister(); //sets the cash in register to 500.
    cashRegister(int); //sets the cash in register to specific amount.
    int getCurrentBalance(); //returns value of cash on hand.
    void acceptAmount(int); //receives the amount deposited by customer.
};

class dispenserType {
private:
    int numOfItems;
    int costOfItems;
public:
    dispenserType(); //sets cost and num of items to 50.
    dispenserType(int, int); //sets num and cost of items to values by user.
    int getNoOfItems(); //returns the value of the number of items.
    int getCost(); //returns the value of cost.
    void makeSale(int); //to reduce num of items by one.
};

#endif //ACD21_PA4_CASHREG_H
