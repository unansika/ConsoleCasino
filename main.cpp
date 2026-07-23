#include <iostream>
#include <chrono>
#include <thread>

#include "blackjack.h"
#include "guessnumber.h"
#include "cardwalk.h"
#include "roulette.h"
#include "inputcasino.h"

int main()
{
    int cash {100};

    std::cout << "welcome to the casino\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "you need to make enough money for rent\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "you have $100 to your name\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "you need $1600 good luck\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "you are loser lol";

    std::this_thread::sleep_for(std::chrono::seconds(2));

    while(true)
    {
        std::cout << "\033[2J\033[H";

        if(cash <= 0)
        {
            std::cout << "better luck next time\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "you have lost everything\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "bye bye home\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
        else if(cash >= 1600)
        {
            std::cout << "lets gooooo $16000\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "you survived and are able to pay rent\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "see you next month\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }

        std::cout << "cash: $" << cash << "\n";
        std::cout << "1-blackjack\n" << "2-guess number\n" << "3-card walk\n" << "4-roulette\n" << "5-video poker(under construction)\n" << "6-baccarat(under construction)\n";
        std::cout << "7-three card poker(under construction)\n" << "8-slots(under construction)\n" << "9-lottery(under construction)\n" << "0-exit\n";

        int choice = input_number(0,4);

        switch(choice)
        {
            case 1:
                std::cout << "\033[2J\033[H";
                cash = blackjack(cash);
                break;
            case 2:
                std::cout << "\033[2J\033[H";
                cash = guess_number(cash);
                break;
            case 3:
                std::cout << "\033[2J\033[H";
                cash = card_walk(cash);
                break;
            case 4:
                std::cout << "\033[2J\033[H";
                cash = roulette(cash);
                break;
            case 0:
                std::cout << "\033[2J\033[H";
                std::cout << "better luck next time";
                std::this_thread::sleep_for(std::chrono::seconds(2));
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


