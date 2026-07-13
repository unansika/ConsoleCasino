#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "guessnumber.h"

using namespace std;

void guess_number()
{
    string line;
    int choice;
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

    srand(time(0));
    int rand_no = rand() % 10 + 1;

    cout << "the number is . . . \n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << rand_no << "\n";
    this_thread::sleep_for(chrono::seconds(1));

    if(rand_no == choice)
    {
        cout << "you win";
        //more win stuff
        return;
    }
    else
    {
        cout << "you lose";
        //more lose stuff
        return;
    }
}
