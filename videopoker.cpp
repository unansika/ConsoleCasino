#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <list>
#include <array>
#include <iterator>
#include <random>

#include "videopoker.h"
#include "inputcasino.h"

void payouts_show()
{
    std::cout << "royal flush:   250 to 1" << " " << "straight flush: 50 to 1\n";
    std::cout << "four of a kind: 25 to 1" << " " << "full house:      9 to 1\n";
    std::cout << "flush:           6 to 1" << " " << "straight:        4 to 1\n";
    std::cout << "three of kind:   3 to 1" << " " << "two pair:        2 to 1\n";
    std::cout << "pair of jacks and better: 1 to 1\n";
}

bool flush_check(std::array<std::string,5> &hand)
{
    char suit = hand[0][hand[0].size()-2];

    for(std::size_t i = 1; i < 5; i++)
    {
        if(suit != hand[i][hand[i].size()-2]) return false;
    }

    return true;
}

bool straight_check(std::array<int,14> &hand_structure)
{
    for(std::size_t i = 0; i < 10; i++)
    {
        if(hand_structure[i] == 1)
        {
            for(std::size_t j = i+1; j < i+5; j++)
            {
                if(hand_structure[j] != 1 && i != 0)
                {
                    if(i == 0) break;
                    else return false;
                }

            }
        }

        else if(hand_structure[i] != 0) return false;
    }

    return true;
}

int hand_evaluation(std::array<std::string,5> &hand)
{
    std::array<int,14> hand_structure {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //key:
    //amount of cards
    //position 0:amount of cards that are Aces
    //position 1:amount of cards that are 2's
    //position 12:amount of cards that are kings etc
    //position 13: also aces

    bool is_flush {false};
    bool is_straight {false};
    bool is_3_of_kind {false};

    is_flush = flush_check(hand);

    for(std::size_t i = 0; i < 5; i++)
    {
        switch(hand[i][0])
        {
            case '2':
                hand_structure[1]++;
                break;

            case '3':
                hand_structure[2]++;
                break;

            case '4':
                hand_structure[3]++;
                break;

            case '5':
                hand_structure[4]++;
                break;

            case '6':
                hand_structure[5]++;
                break;

            case '7':
                hand_structure[6]++;
                break;

            case '8':
                hand_structure[7]++;
                break;

            case '9':
                hand_structure[8]++;
                break;

            case 'T':
                hand_structure[9]++;
                break;

            case 'J':
                hand_structure[10]++;
                break;

            case 'Q':
                hand_structure[11]++;
                break;

            case 'K':
                hand_structure[12]++;
                break;

            case 'A':
                hand_structure[0]++;
                hand_structure[13]++;
                break;
        }
    }

    is_straight = straight_check(hand_structure);

    if(is_straight && is_flush)
    {
        if(hand_structure[13] == 1 && hand_structure[12] == 1) return 250;
        else return 50;
    }
    else if(is_straight)
    {
        return 4;
    }
    else if(is_flush)
    {
        return 6;
    }

    int pair_count {};
    int pair_jack_up_count {};


    for(std::size_t i = 1; i < 14; i++)
    {
        if(hand_structure[i] == 0) continue;
        if(hand_structure[i] == 4)
        {
            return 25;
        }
        else if(hand_structure[i] == 3)
        {
            if(pair_count == 1)
            {
                return 9;
            }
            else is_3_of_kind = true;
        }
        else if(hand_structure[i] == 2)
        {
            pair_count++;
            if(pair_count == 2) return 2;
            else if(is_3_of_kind) return 9;
            else if(i > 9) pair_jack_up_count++;
        }
    }

    if(is_3_of_kind) return 3;
    else if(pair_jack_up_count == 1) return 1;
    else return 0;
}

std::string hand_name(int multiplier)
{
    switch(multiplier)
    {
        case 0:
            return "nothing";
        case 1:
            return "pair";
        case 2:
            return "2 pair";
        case 3:
            return "3 of a kind";
        case 4:
            return "straight";
        case 6:
            return "flush";
        case 9:
            return "full house";
        case 25:
            return "four of a kind";
        case 50:
            return "straight flush";
        case 250:
            return "royal flush";
        default:
            return "error";
    }
}

int vid_poker(int cash)
{
    std::cout << "VIDEO POKER\n";
    std::cout << "payouts\n";
    payouts_show();

    int multiplier {};

    std::list<std::string> card_deck = {"Ace of Spades","2 of Spades","3 of Spades","4 of Spades","5 of Spades","6 of Spades",
                              "7 of Spades","8 of Spades","9 of Spades","Ten of Spades","Jack of Spades","Queen of Spades","King of Spades",

                              "Ace of Clubs","2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs","6 of Clubs",
                              "7 of Clubs","8 of Clubs","9 of Clubs","Ten of Clubs","Jack of Clubs","Queen of Clubs","King of Clubs",

                              "Ace of Diamonds","2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds","6 of Diamonds",
                              "7 of Diamonds","8 of Diamonds","9 of Diamonds","Ten of Diamonds","Jack of Diamonds","Queen of Diamonds","King of Diamonds",

                              "Ace of Hearts","2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts","6 of Hearts",
                              "7 of Hearts","8 of Hearts","9 of Hearts","Ten of Hearts","Jack of Hearts","Queen of Hearts","King of Hearts"};

    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };
    std::uniform_int_distribution random_index_shuffle{};
    int no_of_cards {51};

    std::array<std::string,5> hand;
    std::array<bool,5> card_hold {true,true,true,true,true};

    int bet_amount = input_cash(cash);

    for(std::size_t i = 0; i < 5; i++)
    {
        random_index_shuffle = std::uniform_int_distribution{ 0, no_of_cards };
        int random_card = random_index_shuffle(mt);

        auto it = card_deck.begin();
        advance(it, random_card);

        hand[i] = *it;
        card_deck.erase(it);
        no_of_cards--;
    }

    std::cout << "you draw...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    while(true)
    {
        std::cout << "\033[2J\033[H";
        payouts_show();

        for(std::size_t i = 0; i < 5; i++)
        {
            std::cout << "card " << i+1 << ": " << hand[i];
            if(card_hold[i]) std::cout << " - hold\n";
            else std::cout << " - redraw\n";
        }

        multiplier = hand_evaluation(hand);

        std::cout << "current hand: " << hand_name(multiplier) << "\n";

        std::cout << "enter card number to switch card from hold to redraw and enter 0 to redraw/stand\n";

        int choice = input_number(0,5);

        if(choice == 0)break;
        else
        {
            auto it = card_hold.begin();
            std::advance(it, choice-1);
            *it = !*it;
        }
    }

    bool second_draw {false};

    for(std::size_t i = 0; i < 5; i++)
    {
        if(!card_hold[i])
        {
            second_draw = true;
            random_index_shuffle = std::uniform_int_distribution{ 0, no_of_cards };
            int random_card = random_index_shuffle(mt);

            auto it = card_deck.begin();
            advance(it, random_card);

            hand[i] = *it;
            card_deck.erase(it);
            no_of_cards--;
        }
    }

    std::cout << "\033[2J\033[H";

    if(second_draw)
    {
        std::cout << "you draw...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "\033[2J\033[H";
    }

    payouts_show();

    for(std::size_t i = 0; i < 5; i++)
    {
        std::cout << "card " << i+1 << ": " << hand[i] << "\n";
    }

    multiplier = hand_evaluation(hand);

    std::cout << "final hand: " << hand_name(multiplier) << "\n";

    if(multiplier > 0)
    {
        std::cout << "you win!\n";
        std::cout << "+$" << bet_amount * multiplier;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        get_enter();
        return cash + bet_amount * multiplier;
    }

    else
    {
        std::cout << "you lose!\n";
        std::cout << "-$" << bet_amount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        get_enter();
        return cash - bet_amount;
    }
}
