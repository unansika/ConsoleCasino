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

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int red_black_bet(vector<vector<int>> &bets, int cash)
{
    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "red or black bet, pays 2 to 1"
    cout << "enter red or black 'r' or 'b'):\n";

    string choice {};
    while(true)
    {
        cin >> choice;
        if(choice == "r" || choice == "b") break;
        else cout << "error please enter 'r' or 'b':\n";
    }

    vector<int> bet;

    if(choice == "r")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36});
    }
    else if(choice == "b")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35});
    }

    bet.push_back(2); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int even_odd_bet(vector<vector<int>> &bets, int cash)
{
    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "even or odd bet, pays 2 to 1"
    cout << "enter odd or even 'o' or 'e'):\n";

    string choice {};
    while(true)
    {
        cin >> choice;
        if(choice == "o" || choice == "e") break;
        else cout << "error please enter 'o' or 'e':\n";
    }

    vector<int> bet;

    if(choice == "o")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35});
    }
    else if(choice == "e")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36});
    }

    bet.push_back(2); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
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
                cash = straight_up_bet(bets,cash);
                break;

            case "2":
                cash = red_black_bet(bets,cash);
                break;

            case "3":
                cash = even_odd_bet();
                break;

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
