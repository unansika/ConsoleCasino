#ifndef ROULETTE_H

#define ROULETTE_H

#include <vector>

void roulette_map();
int input_cash(int cash);
int input_number(int minimum, int maximum);
int straight_up_bet(vector<vector<int>> &bets, int cash);
int red_black_bet(vector<vector<int>> &bets, int cash);
int even_odd_bet(vector<vector<int>> &bets, int cash);
int roulette_initial_bets(vector<vector<int>> &bets, int cash)
int roulette(int cash);

#endif

