#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <random>

#include "guessnumber.h"
#include "inputcasino.h"

using namespace std;

int guess_number(int cash)
{
    string line;
    int choice;
    cout << "GUESS THE NUMBER\n";

    int bet_amount = input_cash(cash);

    cout << "guess the number (1-10):\n";

    while(getline(cin, line)) //getting choice as int
    {
        stringstream stream_input(line);
        if(stream_input >> choice)
        {
            if(stream_input.eof())
            {
                if(choice > 0 && choice <= 10) break;
            }
        }

        cout << "\n" << "error please enter number (1-10):\n";
    }

    mt19937 mt{ static_cast<mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };
    uniform_int_distribution random_no_dist{ 1, 10 };
    int rand_no = random_no_dist(mt);

    cout << "the number is . . . \n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << rand_no << "\n";
    this_thread::sleep_for(chrono::seconds(1));

    if(rand_no == choice)
    {
        cout << "you win!";
        cout << "+$" << bet_amount * 9;
        this_thread::sleep_for(chrono::seconds(1));
        return cash + bet_amount * 8;
    }
    else
    {
        cout << "you lose!\n";
        cout << "-$" << bet_amount;
        this_thread::sleep_for(chrono::seconds(1));
        return cash - bet_amount;
    }
}
