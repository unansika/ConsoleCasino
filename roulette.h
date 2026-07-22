#ifndef ROULETTE_H

#define ROULETTE_H

#include <vector>

void roulette_map();
int input_cash(int cash);
int input_number(int minimum, int maximum);

int straight_up_bet(std::vector<std::vector<int>> &bets, int cash);
int red_black_bet(std::vector<std::vector<int>> &bets, int cash);
int even_odd_bet(std::vector<std::vector<int>> &bets, int cash);
int row_bet(std::vector<std::vector<int>> &bets, int cash);
int column_bet(std::vector<std::vector<int>> &bets, int cash);
int four_bet(std::vector<std::vector<int>> &bets, int cash);
int six_bet(std::vector<std::vector<int>> &bets, int cash);
int corner_bet(std::vector<std::vector<int>> &bets, int cash);
int high_low_bet(std::vector<std::vector<int>> &bets, int cash);
int split_bet(std::vector<std::vector<int>> &bets, int cash);

int roulette_initial_bets(std::vector<std::vector<int>> &bets, int cash);
int roulette(int cash);

#endif // ROULETTE_H

