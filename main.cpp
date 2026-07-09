#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

using namespace std;

int blackjack_hand_calc(vector<string>& cards)
{
    size_t length = cards.size();
    int score {0};
    int ace_counter (0);

    for(size_t i = 0; i < length; i++)
    {
        if(cards[i][0] == 'T' || cards[i][0] == 'J' || cards[i][0] == 'Q' || cards[i][0] == 'K') score += 10;
        else if(cards[i][0] == 'A') ace_counter++;
        else if(cards[i][0] == '9') score += 9;
        else if(cards[i][0] == '8') score += 8; //im sorry had a smart way but casting was being weird
        else if(cards[i][0] == '7') score += 7;
        else if(cards[i][0] == '6') score += 6;
        else if(cards[i][0] == '5') score += 5;
        else if(cards[i][0] == '4') score += 4;
        else if(cards[i][0] == '3') score += 3;
        else score += 2;
    }

    while(score < 22 && ace_counter > 0)
    {
        if(score + 11 > 21)
        {
            score += 1;
            ace_counter--;
        }
        else
        {
            score += 11;
            ace_counter--;
        }
    }

    return score;
}

void blackjack()
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

    string dealer_faceup {};
    string dealer_facedown {};

    vector<string> dealer_cards;
    vector<string> players_cards;

    int cards_in_deck {52};
    srand(time(0));

    int random_card = rand() % cards_in_deck;
    auto it = card_deck.begin();
    advance(it, random_card);

    cards_drawn.push_back(*it); //draw dealer face up card
    dealer_cards.push_back(*it);
    dealer_faceup = *it;
    card_deck.erase(it);
    cards_in_deck--;

    random_card = rand() % cards_in_deck;
    it = card_deck.begin();
    advance(it, random_card);

    cards_drawn.push_back(*it); //draw players first card
    players_cards.push_back(*it);
    card_deck.erase(it);
    cards_in_deck--;

    random_card = rand() % cards_in_deck;
    it = card_deck.begin();
    advance(it, random_card);

    cards_drawn.push_back(*it); //draw dealer face down card
    dealer_cards.push_back(*it);
    dealer_facedown = *it;
    card_deck.erase(it);
    cards_in_deck--;

    random_card = rand() % cards_in_deck;
    it = card_deck.begin();
    advance(it, random_card);

    cards_drawn.push_back(*it); //draw players second card
    players_cards.push_back(*it);
    card_deck.erase(it);
    cards_in_deck--;

    cout << "dealers face up card: " << dealer_faceup << "\n";
    cout << "your cards:\n";
    cout << players_cards[0] << "\n"; //test cases
    cout << players_cards[1] << "\n";
    cout << "your score: " << blackjack_hand_calc(players_cards) << "\n";
    cout << "computer score: " << blackjack_hand_calc(dealer_cards) << "\n";
    cout << dealer_facedown << "\n";

    //gameplay loop
    while(blackjack_hand_calc(player_cards) >= 21)
    {
        //ask to stand or draw
        //if stand break out of this
        //if hit add card
        //if over run lose and reveal dealers cards
    }

    //dealer draw algo and reveal

    //calculate winner

    //based on that winnings or losses which will be returned
    //return goes back to menu still need to sort out that loop
}

int main()
{
    //var here to hold money

    //menu to select game and bet amount

    //loop

    //currently just incomplete blackjack
    blackjack();
    return 0;

    //more games
    //guessnumber 3cardpoker roulette slots lottery cardwalk videopoker baccarat
}
