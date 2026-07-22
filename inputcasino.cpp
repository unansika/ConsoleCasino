#include <iostream>
#include <string>
#include <sstream>

#include "inputcasino.h"

using namespace std;

int input_cash(int cash)
{
    string line;
    int bet_amount;
    cout << "enter bet amount " << "max $" << cash << ":\n";

    while(getline(cin, line)) //getting bet amount as int
    {
        stringstream stream_input(line);
        if(stream_input >> bet_amount)
        {
            if(stream_input.eof())
            {
                if(bet_amount > 0 && bet_amount <= cash) break;
            }
        }

        cout << "\n" << "error please enter valid bet:\n";
    }

    return bet_amount;
}

int input_number(int minimum, int maximum)
{
    string line;
    int input;

    while(getline(cin, line)) //getting input as int
    {
        stringstream stream_input(line);
        if(stream_input >> input)
        {
            if(stream_input.eof())
            {
                if(input >= minimum && input <= maximum) break;
            }
        }

        cout << "error please enter number (" << minimum << "-" << maximum << "):\n";
    }

    return input;
}
