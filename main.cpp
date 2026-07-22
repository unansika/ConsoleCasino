#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "blackjack.h"
#include "guessnumber.h"
#include "cardwalk.h"
#include "roulette.h"
#include "inputcasino.h"

using namespace std;

int main()
{
    int cash {100};

    cout << "welcome to the casino\n";

    this_thread::sleep_for(chrono::seconds(2));

    cout << "you need to make enough money for rent\n";

    this_thread::sleep_for(chrono::seconds(2));

    cout << "you have $100 to your name\n";

    this_thread::sleep_for(chrono::seconds(2));

    cout << "you need $1600 good luck\n";

    this_thread::sleep_for(chrono::seconds(3));

    cout << "you are loser lol";

    this_thread::sleep_for(chrono::seconds(1));

    while(true)
    {
        cout << "\033[2J\033[H";

        if(cash <= 0)
        {
            cout << "better luck next time\n";
            this_thread::sleep_for(chrono::seconds(1));
            cout << "you have lost everything\n";
            this_thread::sleep_for(chrono::seconds(1));
            cout << "bye bye home\n";
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }
        else if(cash >= 1600)
        {
            cout << "lets gooooo $16000\n";
            this_thread::sleep_for(chrono::seconds(1));
            cout << "you survived and are able to pay rent\n";
            this_thread::sleep_for(chrono::seconds(1));
            cout << "see you next month\n";
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }

        cout << "cash: $" << cash << "\n";
        cout << "1-blackjack\n" << "2-guess number\n" << "3-card walk\n" << "4-roulette\n" << "5-video poker(under construction)\n" << "6-baccarat(under construction)\n";
        cout << "7-three card poker(under construction)\n" << "8-slots(under construction)\n" << "9-lottery(under construction)\n" << "0-exit\n";

        int choice = input_number(0,4);

        switch(choice)
        {
            case 1:
                cout << "\033[2J\033[H";
                cash = blackjack(cash);
                break;
            case 2:
                cout << "\033[2J\033[H";
                cash = guess_number(cash);
                break;
            case 3:
                cout << "\033[2J\033[H";
                cash = card_walk(cash);
                break;
            case 4:
                cout << "\033[2J\033[H";
                cash = roulette(cash);
                break;
            case 0:
                cout << "\033[2J\033[H";
                cout << "better luck next time";
                this_thread::sleep_for(chrono::seconds(1));
                return 0;
        }
    }

    return 0;
}



    //completed
    //blackjack();
    //guess_number();
    //card_walk();
    //vid_poker();
    //baccarat();


    //more games
    //3cardpoker slots lottery

    //to do while on plane
    //roulette finish
    //video poker
    //baccarat
    //cash function to rest
    //main menu

    //general todo
    //roulette
    //payouts split 17-1, corner 8-1,5no 6-1,6no 5-1,column 2-1 ,


