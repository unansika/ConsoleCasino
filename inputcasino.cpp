#include <iostream>
#include <string>
#include <sstream>

#include "inputcasino.h"

int input_cash(int cash)
{
    std::string line;
    int bet_amount;
    std::cout << "enter bet amount " << "max $" << cash << ":\n";

    while(getline(std::cin, line)) //getting bet amount as int
    {
        std::stringstream stream_input(line);
        if(stream_input >> bet_amount)
        {
            if(stream_input.eof())
            {
                if(bet_amount > 0 && bet_amount <= cash) break;
            }
        }

        std::cout << "\n" << "error please enter valid bet:\n";
    }

    return bet_amount;
}

int input_number(int minimum, int maximum)
{
    std::string line;
    int input;

    while(getline(std::cin, line)) //getting input as int
    {
        std::stringstream stream_input(line);
        if(stream_input >> input)
        {
            if(stream_input.eof())
            {
                if(input >= minimum && input <= maximum) break;
            }
        }

        std::cout << "error please enter number (" << minimum << "-" << maximum << "):\n";
    }

    return input;
}
