#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <list>
#include <random>
#include <iterator>

#include "baccarat.h"
#include "inputcasino.h"

int card_value(char c)
{
    switch(c)
    {
        case '2':
            return 2;

        case '3':
            return 3;

        case '4':
            return 4;

        case '5':
            return 5;

        case '6':
            return 6;

        case '7':
            return 7;

        case '8':
            return 8;

        case '9':
            return 9;

        case 'A':
            return 1;

        default:
            return 0;
    }
}

int hand_value(std::vector<std::string> &hand)
{
    int sum_of_cards {};
    for(std::size_t i = 0; i < hand.size(); i++)
    {
        sum_of_cards += card_value(hand[i][0]);
    }

    return sum_of_cards % 10;
}



int baccarat(int cash)
{
    std::list<std::string> card_deck = {"Ace of Spades","2 of Spades","3 of Spades","4 of Spades","5 of Spades","6 of Spades",
                              "7 of Spades","8 of Spades","9 of Spades","Ten of Spades","Jack of Spades","Queen of Spades","King of Spades",

                              "Ace of Clubs","2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs","6 of Clubs",
                              "7 of Clubs","8 of Clubs","9 of Clubs","Ten of Clubs","Jack of Clubs","Queen of Clubs","King of Clubs",

                              "Ace of Diamonds","2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds","6 of Diamonds",
                              "7 of Diamonds","8 of Diamonds","9 of Diamonds","Ten of Diamonds","Jack of Diamonds","Queen of Diamonds","King of Diamonds",

                              "Ace of Hearts","2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts","6 of Hearts",
                              "7 of Hearts","8 of Hearts","9 of Hearts","Ten of Hearts","Jack of Hearts","Queen of Hearts","King of Hearts"};

    std::vector<std::string> bankers_cards;
    std::vector<std::string> players_cards;
    int bankers_score {};
    int players_score {};

    std::cout << "BACCARAT\n";
    std::cout << "1 - player bet, pays 1 to 1\n";
    std::cout << "2 - dealer bet, pays 0.95 to 1\n";
    std::cout << "3 - tie bet, pays 8-1\n";

    int bet_choice = input_number(1,3);

    int bet_amount = input_cash(cash);

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };
    int cards_in_deck {51};

    std::uniform_int_distribution random_it_shuffle{ 0, cards_in_deck };
    int random_card = random_it_shuffle(mt);

    auto it = card_deck.begin();
    advance(it, random_card);

    players_cards.push_back(*it);
    card_deck.erase(it);
    cards_in_deck--;

    random_it_shuffle = std::uniform_int_distribution { 0, cards_in_deck };
    random_card = random_it_shuffle(mt);
    it = card_deck.begin();
    advance(it, random_card);

    bankers_cards.push_back(*it);
    card_deck.erase(it);
    cards_in_deck--;

    random_it_shuffle = std::uniform_int_distribution { 0, cards_in_deck };
    random_card = random_it_shuffle(mt);
    it = card_deck.begin();
    advance(it, random_card);

    players_cards.push_back(*it);
    card_deck.erase(it);
    cards_in_deck--;

    random_it_shuffle = std::uniform_int_distribution { 0, cards_in_deck };
    random_card = random_it_shuffle(mt);
    it = card_deck.begin();
    advance(it, random_card);

    bankers_cards.push_back(*it);
    card_deck.erase(it);
    cards_in_deck--;

    bankers_score = hand_value(bankers_cards);
    players_score = hand_value(players_cards);

    std::cout << "player draws...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << players_cards[0] << "\n" << players_cards[1] << "\n";
    std::cout << "players score: " << players_score << "\n\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "banker draws...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << bankers_cards[0] << "\n" << bankers_cards[1] << "\n";
    std::cout << "bankers score: " << bankers_score << "\n";

    if(bankers_score > 7 && players_score > 7)
    {
        std::cout << "both hands are naturals\n";
        if(bankers_score == players_score)
        {
            std::cout << "scores are equal, it is a tie!\n";
            if(bet_choice == 3)
            {
                std::cout << "you win +$" << 9 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + 8 * bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 2)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
        else if(bankers_score > players_score)
        {
            std::cout << "banker score is higher, banker wins!\n";
            if(bet_choice == 2)
            {
                std::cout << "you win +$" << 2 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 3)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
        else if(bankers_score < players_score)
        {
            std::cout << "player score is higher, player wins!\n";
            if(bet_choice == 1)
            {
                std::cout << "you win +$" << 2 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 2)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
    }
    else if(bankers_score > 7)
    {
        std::cout << "bankers hand is a natural, banker wins!\n";
        if(bet_choice == 2)
        {
            std::cout << "you win +$" << 2 * bet_amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            get_enter();
            return cash + 2 * bet_amount;
        }
        else if(bet_choice == 1 || bet_choice == 3)
        {
            std::cout << "you lose -$" << bet_amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            get_enter();
            return cash - bet_amount;
        }
    }
    else if(players_score > 7)
    {
        std::cout << "players hand is a natural, banker wins!\n";
        if(bet_choice == 1)
        {
            std::cout << "you win +$" << 2 * bet_amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            get_enter();
            return cash + bet_amount;
        }
        else if(bet_choice == 1 || bet_choice == 2)
        {
            std::cout << "you lose -$" << bet_amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            get_enter();
            return cash - bet_amount;
        }
    }

    if(players_score >= 6 && players_score <= 7)
    {
        std::cout << "players score is between 6-7\n";
        std::cout << "player stands\n";
        if(bankers_score == players_score)
        {
            std::cout << "scores are equal, it is a tie!\n";
            if(bet_choice == 3)
            {
                std::cout << "you win +$" << 9 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + 8 * bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 2)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
        else if(bankers_score > players_score)
        {
            std::cout << "banker score is higher, banker wins!\n";
            if(bet_choice == 2)
            {
                std::cout << "you win +$" << 2 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 3)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
        else if(bankers_score < players_score)
        {
            std::cout << "player score is higher, player wins!\n";
            if(bet_choice == 1)
            {
                std::cout << "you win +$" << 2 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 2)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
    }

    if(players_score >= 0 && players_score <= 5)
    {
        std::cout << "players score is between 0-5 \n";
        std::cout << "player draws a 3rd card...\n";

        random_it_shuffle = std::uniform_int_distribution { 0, cards_in_deck };
        random_card = random_it_shuffle(mt);
        it = card_deck.begin();
        advance(it, random_card);

        players_cards.push_back(*it);
        card_deck.erase(it);
        cards_in_deck--;

        std::this_thread::sleep_for(std::chrono::seconds(2));

        players_score = hand_value(players_cards);
        std::cout << players_cards[2] << "\n";
        std::cout << "players score: " << players_score << "\n";

        if(bankers_score <= 2
           || (bankers_score == 3 && card_value(players_cards[2][0]) != 8)
           || (bankers_score == 4 && card_value(players_cards[2][0]) >= 2 && card_value(players_cards[2][0]) <= 7)
           || (bankers_score == 5 && card_value(players_cards[2][0]) >= 4 && card_value(players_cards[2][0]) <= 7)
           || (bankers_score == 6 && card_value(players_cards[2][0]) >= 6 && card_value(players_cards[2][0]) <= 7))
        {
            std::cout << "banker draws a 3rd card...\n";

            random_it_shuffle = std::uniform_int_distribution { 0, cards_in_deck };
            random_card = random_it_shuffle(mt);
            it = card_deck.begin();
            advance(it, random_card);

            bankers_cards.push_back(*it);
            card_deck.erase(it);
            cards_in_deck--;

            std::this_thread::sleep_for(std::chrono::seconds(2));

            bankers_score = hand_value(bankers_cards);
            std::cout << bankers_cards[2] << "\n";
            std::cout << "bankers score: " << players_score << "\n";
        }


        if(bankers_score == players_score)
        {
            std::cout << "scores are equal, it is a tie!\n";
            if(bet_choice == 3)
            {
                std::cout << "you win +$" << 9 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + 8 * bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 2)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
        else if(bankers_score > players_score)
        {
            std::cout << "banker score is higher, banker wins!\n";
            if(bet_choice == 2)
            {
                std::cout << "you win +$" << 2 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + 2 * bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 3)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
        else if(bankers_score < players_score)
        {
            std::cout << "player score is higher, player wins!\n";
            if(bet_choice == 1)
            {
                std::cout << "you win +$" << 2 * bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash + bet_amount;
            }
            else if(bet_choice == 1 || bet_choice == 2)
            {
                std::cout << "you lose -$" << bet_amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                get_enter();
                return cash - bet_amount;
            }
        }
    }

    std::cout << "error";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    get_enter();
    return cash;
}
