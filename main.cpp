/*
 * cashRegDriver.cpp
 *
 *  Created on: Mar 14, 2014
 *      Author: Adam C. De Leon
 *      Class: CS2308
 *      Section number: 1
 *      Roster number: 6
 *      Program number 4
 *      Program description: This program uses two other files one header file
 *      cashReg.h and an implementation file cashRegImp.cpp which create and
 *      define abstract data types and that are used in this file. The program
 *      in itself is designed to be a program for a vending machine. It
 *      prompts the customer with a menu. After a valid option has been chosen
 *      the program asks the customer to deposit the amount that corresponds
 *      to the choice entered. The program then uses logic to determine what
 *      to do with the input provided by the customer. After the transaction
 *      has been completed the menu is again displayed until the option 9 has
 *      been chosen to abort the program.
 */
# include<iostream>
# include<iomanip>
# include "CashReg.h"              //Header file CashReg.h needed for classes.

using namespace std;

void showSelection();                          //Function for displaying menu.
void sellProduct(dispenserType &, cashRegister);    //Function for making sale.
int main() {
    cashRegister register1(500);             //Instance of cashRegister class.
    dispenserType candy(100, 50);//Instance of items with cost and quantities.
    dispenserType chips(100, 65);
    dispenserType gum(2, 45);
    dispenserType cookies(50, 85);
    int choice;                                //Variable for customer choice.
    int balance;                       //Variable for holding initial balance.
    balance = register1.getCurrentBalance();  //Class defines initial balance.

    //Initiate menu sequence.
    do {
        showSelection();                                       //Display menu.
        cin >> choice;                           //Receive choice from customer.

        //Logic for invalid choice.
        if (choice < 1 || choice > 9 && !(choice >= 5 && choice <= 8)) {
            cout << "Please enter a choice in the range of 1 through 4, or "
                    "enter 9 to exit.";
            cin >> choice;              //Allow customer to re-enter choice.
        }
        //Cases for choice.
        switch (choice) {
            case 1:
                sellProduct(candy, register1);                 //Case for candy.
                break;
            case 2:
                sellProduct(chips, register1);             //Case for chips.
                break;
            case 3:
                sellProduct(gum, register1);                   //Case for gum.
                break;
            case 4:
                sellProduct(cookies, register1);           //Case for cookies.
                break;
            case 9:
                cout << "Collect your change at the bottom and enjoy" << endl;
                break;
            default:
                cout << "Invalid entry." << endl;
                break;
        }
    } while (choice != 9);                                     //Exit menu loop.
    return 0;
}

/*****************************************************************************
 * showSelection - This function displays the menu for the customer.
 */
void showSelection() {
    cout << "*** Welcome to Adam C. De Leon's Candy Store ***" << endl;
    cout << endl;
    cout << "   Select One of the following" << endl;
    cout << endl;
    cout << "      1 for Candy" << endl;
    cout << "      2 for Chips" << endl;
    cout << "      3 for Gum" << endl;
    cout << "      4 for Cookies" << endl;
    cout << "      9 to exit" << endl;
}

/*****************************************************************************
 * sellItem - performs the functions to make the sale.
*/
void sellProduct(dispenserType &vend, cashRegister cashreg) {
    int cost;                                          //Variable to hold cost.
    int deposit;                               //Variable for initial deposit.
    int deposit2;                   //Variable for second deposit to meet cost.
    int difference;                //Variable for determining surplus or deficit.
    int change;                 //Variable for holding deposit that exceeds cost.
    int change2;                        //Variable for second deposit surplus.
    int purchase;       //Variable for deducting purchased item from inventory.


    cost = vend.getCost();               //Class and member to determine cost.
    cashreg.getCurrentBalance();      //Class and member to determine balance.
    vend.getNoOfItems();      //Class and member to determine number of items.

    //Initiate transaction.
    if (vend.getNoOfItems() > 0) {
        cout << "Please deposit " << cost << " cents." << endl;
        cin >> deposit;                    //Allow customer to deposit money.
        difference = cost - deposit;             //Determine possible deficit.
        change = deposit - cost;                 //Determine possible surplus.
        cashreg.acceptAmount(deposit);                //Accept deposited amount.

        //Logic for amount less than item price.
        if (deposit < cost) {
            cout << "Please deposit " << difference << " more cents.";
            cin >> deposit2;
            cout << endl;

            //Stop sale if deposit remains deficit.
            if (deposit2 < difference) {
                cout << "The amount is not enough. Please collect what you "
                        "have deposited." << endl;
            } else if (deposit2 == difference) {
                //Logic for correct deposit.
                vend.makeSale(purchase); //Class and member for reducing item.
                cout << "Please take you item at the bottom and enjoy."
                     << endl;
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            } else if (deposit2 > difference) {
                //Logic for surplus second deposit.
                change2 = deposit2 - difference;         //Determine surplus.
                vend.makeSale(purchase);             //Reduce item inventory.
                cout << "Please take you item at the bottom and enjoy."
                     << endl;
                cout << "Collect your change " << change2 << endl;
                cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
            }
        } else if (deposit > cost) {
            //Logic for deposit surplus.
            vend.makeSale(purchase);                 //Reduce item inventory.
            cout << "The number of candy items is now " << vend.getNoOfItems()
                 << endl;
            cout << "Please take you item at the bottom and enjoy." << endl;
            cout << "Collect your change " << change << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        } else if (deposit == cost) {
            //Logic for exact deposit.
            vend.makeSale(purchase);                //Reduce item inventory.
            cout << "Please take you item at the bottom and enjoy." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        }
    } else {
        //Message for 0 item inventory.
        cout << "Sorry this item is sold out." << endl;
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    }
}

