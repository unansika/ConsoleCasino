#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "roulette.h"

using namespace std;

void roulette_map()
{
    cout << "   ┌───────────────────────────────────┐\n";
    cout << "   │\033[31m3\033[0m │6 │\033[31m9\033[0m │\033[31m12\033[0m│15│\033[31m18\033[0m│\033[31m21\033[0m│24│\033[31m27\033[0m│\033[31m30\033[0m│33│\033[31m36\033[0m│\n";
    cout << "┌──│──│──│──│──│──│──│──│──│──│──│──│──│\n";
    cout << "│\033[32m0\033[0m │2 │\033[31m5\033[0m │8 │11│\033[31m14\033[0m│17│20│\033[31m23\033[0m│26│29│\033[31m32\033[0m│35│\n";
    cout << "└──│──│──│──│──│──│──│──│──│──│──│──│──│\n";
    cout << "   │\033[31m1\033[0m │4 │\033[31m7\033[0m │10│13│\033[31m16\033[0m│\033[31m19\033[0m│22│\033[31m25\033[0m│28│31│\033[31m34\033[0m│\n";
    cout << "   └───────────────────────────────────┘\n";
    cout << "   │  \033[32m1st 12\033[0m   │  \033[32m2nd 12\033[0m   │  \033[32m3rd 12\033[0m   │\n";
    cout << "   └───────────────────────────────────┘\n";
    cout << "   │\033[32m1-18\033[0m │\033[32meven\033[0m │ \033[31mred\033[0m │black│ \033[32modd\033[0m │\033[32m19-36\033[0m│\n";
    cout << "   └───────────────────────────────────┘\n";
}

int input_cash(int cash)
{
    roulette_map();

    string line;
    int bet_amount;
    cout << "enter bet amount " << "max:(" << cash << ")" << ":\n";

    while(getline(cin, line)) //getting choice as int
    {
        stringstream stream_input(line);
        if(stream_input >> choice)
        {
            if(stream_input.eof())
            {
                if(choice >= 0 && choice <= cash) break;
            }
        }

        cout << "\n" << "error please enter number (0-36):\n";
    }

    return bet_amount;
}

int input_number(int minimum, int maximum)
{
    string line;
    int input;

    while(getline(cin, line)) //getting choice as int
    {
        stringstream stream_input(line);
        if(stream_input >> choice)
        {
            if(stream_input.eof())
            {
                if(input >= minimum && choice <= maximum) break;
            }
        }

        cout << "error please enter number (" << minimum << "-" << maximum << "):\n";
    }

    return input;
}

int straight_up_bet(vector<vector<int>> &bets, int cash)
{
    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "straight up bet, pays 35 to 1"
    cout << "enter number to bet on(0-36):\n";

    vector<int> bet;
    bet.push_back(input_number(0,36)); //input number that is bet on and add to bet vector

    bet.push_back(35); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    return cash -= bet_amount; //return cash after
}

void red_black_bet()
{

}

void even_odd_bet()
{

}

void dozen_bet()
{

}

void row_bet()
{

}

void column_bet()
{

}

void five_bet()
{

}

void six_bet()
{

}

void corner_bet()
{

}

void high_low_bet()
{
    cout << "\033[2J\033[H"; //clears console
}

void split_bet()
{
    cout << "\033[2J\033[H"; //clears console

}

void bet_checker(vector<int> &bet)
{

}

int roulette_initial_bets(vector<vector<int>> &bets, int cash)
{
    string choice {};
    while(true)
    {
        cout << "\033[2J\033[H"; //clears console
        cout << "ROULETTE\n";
        cout << "select bets\n";
        cout << "1-straight up" << "   " << "2-red or black\n";
        cout << "3-even or odd" << "   " << "4-dozen bet\n";
        cout << "5-row bet" << "       " << "6-column bet\n";
        cout << "7-five numbers" << "  " << "8-six numbers\n";
        cout << "9-corner bet" << "    " << "10-high or low\n";
        cout << "11-split bet" << "    " << "f-spin wheel\n";

        cin >> choice;

        switch(choice)
        {
            case "1":
                straight_up_bet();
                //do bet stuff
            case "2":
                red_black_bet();
                //do bet stuff
            case "3":
                even_odd_bet();
            case "4":
                dozen_bet();
            case "5":

            case "6":

            case "7":

            case "8":

            case "9":

            case "10":

            case "11":

            case "f":
                return cash;

            default:
                cout << "error invalid choice";
                break;
        }
    }
}

int roulette(int cash)
{
    vector<vector<int>> bets;
    //key for vector: vector of vector, each vector i in the vector vec contains ints, last int of each vector i is bet the bet amount, second last int is the payout multiplier;

    cash = roulette_initial_bets(cash);

    srand(time(0));
    int rand_no = rand() % 37;





}
