#include <iostream>
#include <chrono>
#include <thread>

#include "blackjack.h"
#include "guessnumber.h"
#include "cardwalk.h"
#include "roulette.h"
#include "videopoker.h"
#include "baccarat.h"
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

    get_enter();

    while(true)
    {
        std::cout << "\033[2J\033[H";

        if(cash <= 0)
        {
            std::cout << "better luck next time\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "you have lost everything\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "bye bye home\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }
        else if(cash >= 1600)
        {
            std::cout << "lets gooooo $16000\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "you survived and are able to pay rent\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "see you next month\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }

        std::cout << "cash: $" << cash << "\n";
        std::cout << "1-blackjack\n" << "2-guess number\n" << "3-card walk\n" << "4-roulette\n" << "5-video poker\n" << "6-baccarat\n";
        std::cout << "7-three card poker(under construction)\n" << "8-slots(under construction)\n" << "0-exit\n";

        int choice = input_number(0,6);

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
            case 5:
                std::cout << "\033[2J\033[H";
                cash = vid_poker(cash);
                break;
            case 6:
                std::cout << "\033[2J\033[H";
                cash = baccarat(cash);
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



