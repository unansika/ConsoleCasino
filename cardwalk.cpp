#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <iterator>
#include <thread>
#include <chrono>

#include "cardwalk.h"
#include "inputcasino.h"

std::string red_or_black(std::string card)
{
    char suit = card[card.size()-2];
    if(suit == 'd' || suit == 't') return "r";
    else return "b";
}

int card_walk(int cash)
{
    std::list<std::string> card_deck = {"Ace of Spades","2 of Spades","3 of Spades","4 of Spades","5 of Spades","6 of Spades",
                              "7 of Spades","8 of Spades","9 of Spades","Ten of Spades","Jack of Spades","Queen of Spades","King of Spades",

                              "Ace of Clubs","2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs","6 of Clubs",
                              "7 of Clubs","8 of Clubs","9 of Clubs","Ten of Clubs","Jack of Clubs","Queen of Clubs","King of Clubs",

                              "Ace of Diamonds","2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds","6 of Diamonds",
                              "7 of Diamonds","8 of Diamonds","9 of Diamonds","Ten of Diamonds","Jack of Diamonds","Queen of Diamonds","King of Diamonds",

                              "Ace of Hearts","2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts","6 of Hearts",
                              "7 of Hearts","8 of Hearts","9 of Hearts","Ten of Hearts","Jack of Hearts","Queen of Hearts","King of Hearts"};

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };

    int no_of_cards {52};

    std::uniform_int_distribution random_index_shuffle{ 1, no_of_cards };
    int random_card = random_index_shuffle(mt);

    std::cout << "CARDWALK\n";

    int bet_amount = input_cash(cash);

    size_t counter {0};

    while(counter <= 2)
    {
        std::cout << "red or black('r' or 'b'):\n";
        std::string choice {};
        while(true)
        {
            std::cin >> choice;
            if(choice == "r" || choice == "b") break;
            else std::cout << "error please enter 'r' or 'b':\n";
        }

        random_index_shuffle = std::uniform_int_distribution{ 1, no_of_cards };
        random_card = random_index_shuffle(mt);
        auto it = card_deck.begin();
        advance(it, random_card);

        card_deck.erase(it);

        std::cout << "you draw:\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << *it << "\n";

        if(choice == red_or_black(*it)) std::cout << "correct!\n";
        else
        {
            std::cout << "you lose!\n";
            std::cout << "-$" << bet_amount;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return cash - bet_amount;
        }
        no_of_cards--;
        counter++;
    }

    std::cout << "you win!";
    std::cout << "+$" << bet_amount * 7;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return cash + bet_amount * 6;

}
