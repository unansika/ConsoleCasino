#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "roulette.h"
#include "inputcasino.h"

using namespace std;

void roulette_map()
{
    /*cout << "   ┌───────────────────────────────────┐\n";
    cout << "   │\033[31m3\033[0m │6 │\033[31m9\033[0m │\033[31m12\033[0m│15│\033[31m18\033[0m│\033[31m21\033[0m│24│\033[31m27\033[0m│\033[31m30\033[0m│33│\033[31m36\033[0m│\n";
    cout << "┌──│──│──│──│──│──│──│──│──│──│──│──│──│\n";
    cout << "│\033[32m0\033[0m │2 │\033[31m5\033[0m │8 │11│\033[31m14\033[0m│17│20│\033[31m23\033[0m│26│29│\033[31m32\033[0m│35│\n";
    cout << "└──│──│──│──│──│──│──│──│──│──│──│──│──│\n";
    cout << "   │\033[31m1\033[0m │4 │\033[31m7\033[0m │10│13│\033[31m16\033[0m│\033[31m19\033[0m│22│\033[31m25\033[0m│28│31│\033[31m34\033[0m│\n";
    cout << "   └───────────────────────────────────┘\n";
    cout << "   │  \033[32m1st 12\033[0m   │  \033[32m2nd 12\033[0m   │  \033[32m3rd 12\033[0m   │\n";
    cout << "   └───────────────────────────────────┘\n";
    cout << "   │\033[32m1-18\033[0m │\033[32meven\033[0m │ \033[31mred\033[0m │black│ \033[32modd\033[0m │\033[32m19-36\033[0m│\n";
    cout << "   └───────────────────────────────────┘\n";*/

    cout << "   ┌───────────────────────────────────┐\n";
    cout << "   │3 │6 │9 │12│15│18│21│24│27│30│33│36│\n";
    cout << "┌──│──│──│──│──│──│──│──│──│──│──│──│──│\n";
    cout << "│0 │2 │5 │8 │11│14│17│20│23│26│29│32│35│\n";
    cout << "└──│──│──│──│──│──│──│──│──│──│──│──│──│\n";
    cout << "   │1 │4 │7 │10│13│16│19│22│25│28│31│34│\n";
    cout << "   └───────────────────────────────────┘\n";
    cout << "   │   1st 12  │  2nd 12   │  3rd 12   │\n";
    cout << "   └───────────────────────────────────┘\n";
    cout << "   │1-18 │even │ red │black│ odd │19-36│\n";
    cout << "   └───────────────────────────────────┘\n";
}

int straight_up_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console

    roulette_map();

    cout << "straight up bet, pays 35 to 1";
    cout << "enter number to bet on(0-36):\n";

    vector<int> bet;
    bet.push_back(input_number(0,36)); //input number that is bet on and add to bet vector

    bet.push_back(36); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int red_black_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "red or black bet, pays 1 to 1";
    cout << "enter red or black 'r' or 'b'):\n";

    string choice {};
    while(true)
    {
        cin >> choice;
        if(choice == "r" || choice == "b") break;
        else cout << "error please enter 'r' or 'b':\n";
    }

    vector<int> bet;

    if(choice == "r")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36});
    }
    else if(choice == "b")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35});
    }

    bet.push_back(2); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int even_odd_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "even or odd bet, pays 1 to 1";
    cout << "enter odd or even 'o' or 'e'):\n";

    string choice {};
    while(true)
    {
        cin >> choice;
        if(choice == "o" || choice == "e") break;
        else cout << "error please enter 'o' or 'e':\n";
    }

    vector<int> bet;

    if(choice == "o")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35});
    }
    else if(choice == "e")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36});
    }

    bet.push_back(2); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int dozen_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "dozen bet, pays 2 to 1";
    cout << "enter '1' for 1st 12(1-12)\n";
    cout << "enter '2' for 2nd 12(13-24)\n";
    cout << "enter '3' for 3rd 12(25-36):\n";

    string choice {};
    while(true)
    {
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3") break;
        else cout << "error please enter '1', '2' or '3':\n";
    }

    vector<int> bet;

    if(choice == "1")
    {
        bet.reserve(12);
        bet.insert(bet.end(), {1,2,3,4,5,6,7,8,9,10,11,12});
    }
    else if(choice == "2")
    {
        bet.reserve(12);
        bet.insert(bet.end(), {13,14,15,16,17,18,19,20,21,22,23,24});
    }
    else if(choice == "3")
    {
        bet.reserve(12);
        bet.insert(bet.end(), {25,26,27,28,29,30,31,32,33,34,35,36});
    }

    bet.push_back(3); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int row_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "row bet, pays 11 to 1\n";
    cout << "enter row number from 1 to 12\n";
    cout << "row 1 - 1,2,3  row 2 - 4,5,6 etc.\n";

    int choice = input_number(1, 12);

    vector<int> bet;

    bet.reserve(3);
    bet.insert(bet.end(), {choice*3-2,choice*3-1,choice*3});

    bet.push_back(12); //payout multiplier

    int bet_amount = input_cash(cash);

    bets.push_back(bet);

    return cash -= bet_amount;
}

int column_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "column bet, pays 2 to 1\n";
    cout << "enter column number 1 to 3\n";
    cout << "column 1 starts with 1 etc.\n";

    string choice {};

    while(true)
    {
        cin >> choice;
        if(choice == "1" || choice == "2" || choice == "3") break;
        cout << "error please enter '1', '2' or '3'\n";
    }

    vector<int> bet;

    if(choice == "1")
    {
        bet.reserve(12);
        bet.insert(bet.end(),{1,4,7,10,13,16,19,22,25,28,31,34});
    }
    else if(choice == "2")
    {
        bet.reserve(12);
        bet.insert(bet.end(),{2,5,8,11,14,17,20,23,26,29,32,35});
    }
    else if(choice == "3")
    {
        bet.reserve(12);
        bet.insert(bet.end(),{3,6,9,12,15,18,21,24,27,30,33,36});
    }

    bet.push_back(3); //payout multiplier

    int bet_amount = input_cash(cash);

    bets.push_back(bet);

    return cash -= bet_amount;
}

int four_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();


    vector<int> bet;

    bets.push_back(bet);

    return cash;
}

int six_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "row bet, pays 11 to 1\n";
    cout << "enter row number from 1 to 12\n";
    cout << "row 1 - 1,2,3  row 2 - 4,5,6 etc.\n";

    int choice = input_number(1, 12);

    vector<int> bet;

    bet.reserve(3);
    bet.insert(bet.end(), {choice*3-2,choice*3-1,choice*3});

    bet.push_back(12); //payout multiplier

    int bet_amount = input_cash(cash);

    bets.push_back(bet);

    return cash -= bet_amount;
}

int corner_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    vector<int> bet;

    bets.push_back(bet);

    return cash;
}

int high_low_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "high or low bet, pays 1 to 1";
    cout << "enter high or low 'h' or 'l'):\n";

    string choice {};
    while(true)
    {
        cin >> choice;
        if(choice == "h" || choice == "l") break;
        else cout << "error please enter 'h' or 'l':\n";
    }

    vector<int> bet;

    if(choice == "h")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {19,20,21,22,23,24,25,26,27,28,30,31,32,33,34,35,36});
    }
    else if(choice == "l")
    {
        bet.reserve(18);
        bet.insert(bet.end(), {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    }

    bet.push_back(2); //input payout multiplier into vector

    int bet_amount = input_cash(cash); //get bet amount

    bet.push_back(bet_amount); //add bet amount to vector

    bets.push_back(bet);

    return cash -= bet_amount; //return cash after
}

int split_bet(vector<vector<int>> &bets, int cash)
{
    if(cash == 0)
    {
        cout << "no cash left for bets\n";
        this_thread::sleep_for(chrono::seconds(1));
        return 0;
    }

    cout << "\033[2J\033[H"; //clears console
    roulette_map();

    cout << "split bet, pays 17 to 1\n";
    cout << "enter 2 numbers that are adjacent on the board\n";
    cout << "enter first number\n";

    int first_choice = input_number(1,36);

    cout << "enter second adjacent number\n";

    int second_choice {};

    string line;

    while(getline(cin, line)) //getting input as int
    {
        stringstream stream_input(line);
        if(stream_input >> second_choice)
        {
            if(stream_input.eof() && second_choice > 0 && second_choice <= 36)
            {
                if(first_choice > 3 && second_choice == first_choice - 3) break;
                else if(first_choice < 34 && second_choice == first_choice + 3) break;
                else if(first_choice % 3 == 0 && second_choice == first_choice - 1) break;
                else if((first_choice + 2) % 3 == 0 && second_choice == first_choice + 1) break;
                else if((first_choice + 1) % 3 == 0 && (second_choice == first_choice + 1 || second_choice == first_choice -1)) break;
            }
        }

        cout << "error please enter adjacent number\n";
    }

    vector<int> bet;

    bet.push_back(first_choice);
    bet.push_back(second_choice);

    bet.push_back(18); //payout multiplier

    int bet_amount = input_cash(cash);

    bet.push_back(bet_amount);

    bets.push_back(bet);

    return cash -= bet_amount;
}

int roulette_initial_bets(vector<vector<int>> &bets, int cash)
{
    while(true)
    {
        cout << "\033[2J\033[H"; //clears console
        cout << "ROULETTE\n";
        cout << "select bets\n";
        cout << "1-straight up" << "   " << "2-red or black\n";
        cout << "3-even or odd" << "   " << "4-dozen bet\n";
        cout << "5-row bet" << "       " << "6-column bet\n";
        cout << "7-the 4 numbers" << " " << "8-six numbers\n";
        cout << "9-corner bet" << "    " << "10-high or low\n";
        cout << "11-split bet" << "    " << "12-spin wheel\n";

        int choice = input_number(1,12);

        switch(choice)
        {
            case 1:
                cash = straight_up_bet(bets,cash);
                break;

            case 2:
                cash = red_black_bet(bets,cash);
                break;

            case 3:
                cash = even_odd_bet(bets,cash);
                break;

            case 4:
                cash = dozen_bet(bets,cash);
                break;

            case 5:
                cash = row_bet(bets,cash);
                break;

            case 6:
                cash = column_bet(bets,cash);
                break;

            case 7:
                cash = four_bet(bets,cash);
                break;

            case 8:
                cash = six_bet(bets,cash);
                break;

            case 9:
                cash = corner_bet(bets,cash);
                break;

            case 10:
                cash = high_low_bet(bets,cash);
                break;

            case 11:
                cash = split_bet(bets,cash);
                break;

            case 12:
                return cash;

            default:
                cout << "error invalid choice";
                break;
        }
    }
}

int roulette(int cash)
{
    vector<vector<int>> bets;
    //key for vector: vector of vector
    //each vector i in the vector vec contains ints
    //last int of each vector i is bet the bet amount
    //second last int is the payout multiplier;

    int initial_cash = cash;
    cash = roulette_initial_bets(bets, cash);

    mt19937 mt{ static_cast<mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };
    uniform_int_distribution random_index_shuffle{ 1, 36 };
    int roulette_number = random_index_shuffle(mt);

    if(cash == initial_cash)
    {
        cout << "no bets made going back to menu\n";
        return cash;
    }

    cout << "\033[2J\033[H"; //clears console
    cout << "bets are in\n";

    this_thread::sleep_for(chrono::seconds(1));

    cout << "dealer spins the wheel and throws in the ball!\n";

    this_thread::sleep_for(chrono::seconds(1));

    for(size_t i = 0; i < 4; i++)
    {
        cout << "rolling...\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "looks like it could be a " << rand() % 37 << "!\n";
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\033[2J\033[H"; //clears console
    cout << "the ball lands on the " << roulette_number << "!\n";

    int prepayout_cash = cash;

    roulette_map();

    for(size_t i = 0; i < bets.size(); i++)
    {
        for(size_t j = 0; j < bets[i].size()-2; j++)
        {
            if(bets[i][j] == roulette_number)
            {
                this_thread::sleep_for(chrono::seconds(1));
                cout << "bet hits with a " << bets[i][bets.size()-2] << "x payout!\n";
                int winnings = bets[i][bets.size()-2]*bets[i][bets.size()-1];
                cout << "you win " << winnings << "\n";
                cash += winnings;
                break;
            }
        }
    }

    if(cash == prepayout_cash)
    {
        cout << "you won no bets :( going back to menu";
        this_thread::sleep_for(chrono::seconds(1));
        return cash;
    }

    cout << "you won: " << cash - prepayout_cash << "! going back to menu\n";
    this_thread::sleep_for(chrono::seconds(1));
    return cash;
}
