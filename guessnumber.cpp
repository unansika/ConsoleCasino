#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <random>

#include "guessnumber.h"
#include "inputcasino.h"

int guess_number(int cash)
{
    std::string line;
    int choice;
    std::cout << "GUESS THE NUMBER\n";
    std::cout << "pays 8 to 1\n";
    std::cout << "guess the number (1-10):";

    while(getline(std::cin, line)) //getting choice as int
    {
        std::stringstream stream_input(line);
        if(stream_input >> choice)
        {
            if(stream_input.eof())
            {
                if(choice > 0 && choice <= 10) break;
            }
        }

        std::cout << "\n" << "error please enter number (1-10):\n";
    }

    int bet_amount = input_cash(cash);

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };
    std::uniform_int_distribution random_no_dist{ 1, 10 };
    int rand_no = random_no_dist(mt);

    std::cout << "the number is ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << rand_no << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if(rand_no == choice)
    {
        std::cout << "you win!\n";
        std::cout << "+$" << bet_amount * 9;
        get_enter();
        return cash + bet_amount * 8;
    }
    else
    {
        std::cout << "you lose!\n";
        std::cout << "-$" << bet_amount;
        get_enter();
        return cash - bet_amount;
    }
}
