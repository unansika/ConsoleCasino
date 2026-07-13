#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <thread>
#include <chrono>

#include "cardwalk.h"

using namespace std;

//error with clubs right now

string red_or_black(string card)
{
    if(card[card.size()-1] == 'e') return "b";
    else if(card[card.size()-1] == 'b') return "b";
    else return "r";
}

void card_walk()
{
    list<string> card_deck = {"Ace of Spades","2 of Spades","3 of Spades","4 of Spades","5 of Spades","6 of Spades",
                              "7 of Spades","8 of Spades","9 of Spades","Ten of Spades","Jack of Spades","Queen of Spades","King of Spades",

                              "Ace of Clubs","2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs","6 of Clubs",
                              "7 of Clubs","8 of Clubs","9 of Clubs","Ten of Clubs","Jack of Clubs","Queen of Clubs","King of Clubs",

                              "Ace of Diamonds","2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds","6 of Diamonds",
                              "7 of Diamonds","8 of Diamonds","9 of Diamonds","Ten of Diamonds","Jack of Diamonds","Queen of Diamonds","King of Diamonds",

                              "Ace of Hearts","2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts","6 of Hearts",
                              "7 of Hearts","8 of Hearts","9 of Hearts","Ten of Hearts","Jack of Hearts","Queen of Hearts","King of Hearts"};

    vector<string> cards_drawn;

    srand(time(0));

    cout << "CARDWALK\n";

    string choice {};
    int no_of_cards {52};
    size_t counter {0};
    choice = "";

    while(counter <= 2)
    {
        cout << "red or black('r' or 'b'):\n";
        choice = "";
        while(true)
        {
            cin >> choice;
            if(choice == "r" || choice == "b") break;
            else cout << "error please enter 'r' or 'b':\n";
        }

        int random_card = rand() % no_of_cards;
        auto it = card_deck.begin();
        advance(it, random_card);

        cards_drawn.push_back(*it); //draw card
        card_deck.erase(it);

        cout << "you draw:\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << *it << "\n";

        if(choice == red_or_black(*it)) cout << "correct!\n";
        else
        {

            cout << "you lose!\n";
            //lose stuff
            return;
        }
        no_of_cards--;
        counter++;
    }

    cout << "you win!";
    return;
}
