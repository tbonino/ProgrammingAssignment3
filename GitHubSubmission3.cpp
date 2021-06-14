// ProgrammingAssignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//pull in all the header files we need
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

//declare constant variables to be used in calculating shipping cost
const double USA_TIER1 = 6.00;
const double USA_TIER1_FRAGILE = USA_TIER1 + 2.00;
const double USA_TIER2 = 9.00;
const double USA_TIER2_FRAGILE = USA_TIER2 + 2.00;
const double USA_TIER3 = 12.00;
const double USA_TIER3_FRAGILE = USA_TIER3 + 2.00;
const double CAN_TIER1 = 8.00;
const double CAN_TIER1_FRAGILE = CAN_TIER1 + 2.00;
const double CAN_TIER2 = 12.00;
const double CAN_TIER2_FRAGILE = CAN_TIER2 + 2.00;
const double CAN_TIER3 = 15.00;
const double CAN_TIER3_FRAGILE = CAN_TIER3 + 2.00;
const double AUS_TIER1 = 10.00;
const double AUS_TIER1_FRAGILE = AUS_TIER1 + 2.00;
const double AUS_TIER2 = 14.00;
const double AUS_TIER2_FRAGILE = AUS_TIER2 + 2.00;
const double AUS_TIER3 = 17.00;
const double AUS_TIER3_FRAGILE = AUS_TIER3 + 2.00;
const double MOON_TIER1 = 99.00;
const double MOON_TIER1_FRAGILE = MOON_TIER1 + 2.00;
const double MOON_TIER2 = 109.00;
const double MOON_TIER2_FRAGILE = MOON_TIER2 + 2.00;
const double MOON_TIER3 = 119.00;
const double MOON_TIER3_FRAGILE = MOON_TIER3 + 2.00;
const double MOON_TIER4 = 89.00;
const double MOON_TIER4_FRAGILE = MOON_TIER4 + 2.00;

int main()
{
    //declare user input variables
    string item_name;
    string fragile;
    double order_total = 0.0;
    string destination;

    // initialize file variable to output to file
    fstream file;

    // initialize file stream object to write to file
    file.open("Order.txt", ios::out);

    //initialize header of program
    cout << left << setw(60) << setfill('*') << "" << endl;
    cout << left << setw(6) << setfill('*') << "Elon Musk's SPACEX Delivery Service by Tom Bonino" << setw(6) << setfill('*') << endl;
    cout << left << setw(60) << setfill('*') << "" << endl;

    cout << endl; // spacer

    // following is a thoroughly nested "if...else" structure that validates each user entry and terminates on that entry if it is incorrectly entered.

    // get item name from user
    cout << "Please enter the item name (no spaces)" << setw(21) << setfill('.') << "" << ":";
    if (cin >> item_name)
    { // if item name is valid, continue
        // get if item is fragile or not from user
        cout << "Is the item fragile? (y=yes/n=no)" << setw(26) << setfill('.') << "" << ":";

        if (cin >> fragile)
        {// if fragile entry is a string, continue

            // convert the value in fragile to upper case to streamline checking the value
            transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper);

            // check the value of fragile. continue if it is y/Y or n/N
            if (fragile == "Y" || fragile == "N")
            {

                // get the order total from the user
                cout << "Please enter your order total" << setw(30) << setfill('.') << "" << ":";

                if ((cin >> order_total) && (order_total > 0.0))
                {// if order_total entry is valid, continue

                    // get the destination from the user
                    cout << "Please enter destination. (usa/can/aus/moon)" << setw(15) << setfill('.') << "" << ":";
                    if (cin >> destination)
                    {

                        // capitalize the value of destination to streamline validation
                        transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

                        // if value is valid, continue
                        if (destination == "USA" || destination == "CAN" || destination == "AUS" || destination == "MOON")
                        {
                            cout << "" << endl; // space the user entries from the result output
                        }

                        // fail program if the content of destination is anything other than USA, CAN or AUS
                        else
                        {
                            cout << "Please enter a valid destination.";
                            return 1;
                        }
                    }

                    // fail program if a string is not entered
                    else
                    {
                        cout << "Please enter a valid destination.";
                        return 1;
                    }
                }

                // fail program if order_total entry invalid
                else
                {
                    cout << "Please enter a valid Order Total amount." << endl;
                    return 1;
                }
            }

            // if the value of fragile is not Y or N, fail the program
            else
            {
                cout << "Please enter either y or n." << endl;
                return 1;
            }
        }

        // fail program if fragile entry invalid
        else
        {
            cout << "Please enter either y or n." << endl;
            return 1;
        }
    }

    // fail program if item_name entry invalid
    else
    {
        cout << "Please enter a valid string." << endl;
        return 1;
    }

    // pick up here if everything validates correctly. Time to calculate!

    // initialize output area in both console and file
    cout << "Your item is" << left << setw(33) << setfill('.') << "" << item_name << endl;
    file << "Your item is" << left << setw(33) << setfill('.') << "" << item_name << endl;

    // set how totals will be displayed
    cout << fixed << setprecision(2);

    // itemize calculations based on the value of fragile

    // package is not fragile
    if (fragile == "N")
    {
        // nested if structure then selects by destination isn't fragile (tried a switch before remembering/realizing switches won't work with strings)
        if (destination == "USA")
        {
            // nested if to get USA pricing tier

            // USA_TIER1 result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER1 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER1 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER1 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER1 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // USA_TIER2 result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER2 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER2 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER2 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER2 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // USA_TIER3 result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER3 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER3 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER3 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER3 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // order_total greater than 150 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }

        if (destination == "CAN")
        {
            // nested if to get CAN pricing tier

            // CAN_TIER1 result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER1 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER1 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER1 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER1 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // CAN_TIER2 result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER2 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER2 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER2 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER2 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // CAN_TIER3 result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER3 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER3 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER3 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER3 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // order_total greater than 150 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }

        if (destination == "MOON")
        {
            // nested if to get MOON pricing tier

            // MOON_TIER1 result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER1 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER1 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER1 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER1 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // MOON_TIER2 result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER2 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER2 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER2 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER2 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // MOON_TIER3 result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER3 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER3 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER3 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER3 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // MOON_TIER4 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "No Free rides to the moon! $" << MOON_TIER4 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER4 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "No Free rides to the moon! $" << MOON_TIER4 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER4 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }

        else
        {
            // nested if to get AUS pricing tier

            // AUS_TIER1 result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER1 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER1 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER1 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER1 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // AUS_TIER2 result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER2 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER2 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER2 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER2 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // AUS_TIER3 result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER3 << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER3 + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER3 << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER3 + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // order_total greater than 150 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }
    }

    // if the package is fragile, jump here
    else
    {
        // nested if structure then selects by destination if item is fragile
        if (destination == "USA")
        {
            // nested if to get fragile USA pricing tier

            // USA_TIER1_FRAGILE result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER1_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER1_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER1_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER1_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // USA_TIER2_FRAGILE result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER2_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER2_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER2_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER2_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // USA_TIER3_FRAGILE result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER3_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER3_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << USA_TIER3_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << USA_TIER3_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // order_total greater than 150 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }

        if (destination == "CAN")
        {
            // nested if to get fragile CAN pricing tier

            // CAN_TIER1_FRAGILE result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER1_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER1_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER1_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER1_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // CAN_TIER2_FRAGILE result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER2_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "" << "$" << CAN_TIER2_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "" << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER2_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "" << "$" << CAN_TIER2_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "" << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // CAN_TIER3_FRAGILE result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER3_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER3_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << CAN_TIER3_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << CAN_TIER3_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // order_total greater than 150 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }

        if (destination == "MOON")
        {
            // nested if to get MOON pricing tier

            // MOON_TIER1_FRAGILE result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER1_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER1_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER1_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER1_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // MOON_TIER2_FRAGILE result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER2_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER2_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER2_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER2_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // MOON_TIER3_FRAGILE result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER3_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER3_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << MOON_TIER3_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER3_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // MOON_TIER4_FRAGILE result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "No Free rides to the moon! $" << MOON_TIER4_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER4_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "No Free rides to the moon! $" << MOON_TIER4_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << MOON_TIER4_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }

        else
        {
            // nested if to get fragile AUS pricing tier

            // AUS_TIER1_FRAGILE result
            if (order_total < 50.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER1_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER1_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER1_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER1_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // AUS_TIER2_FRAGILE result
            if (order_total >= 50.00 && order_total < 100.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER2_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER2_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER2_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER2_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // AUS_TIER3_FRAGILE result
            if (order_total >= 100.00 && order_total < 150.00)
            {
                cout << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER3_FRAGILE << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER3_FRAGILE + order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(25) << setfill('.') << "$" << AUS_TIER3_FRAGILE << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << AUS_TIER3_FRAGILE + order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }

            // order_total greater than 150 result
            else
            {
                cout << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                cout << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                cout << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                cout << endl; // spacer
                cout << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // write results to file
                file << "Your shipping cost is" << right << setw(29) << setfill('.') << "Free!" << endl;
                file << "You are shipping to" << right << setw(26) << setfill('.') << "" << destination << endl;
                file << "Your total shipping costs are" << right << setw(17) << setfill('.') << "$" << order_total << endl;
                file << endl; // spacer
                file << right << setw(55) << setfill('-') << "Thank You!" << endl;

                // pause to let you view results before terminating program successfully
                system("pause");
                return 0;
            }
        }
    }


}
