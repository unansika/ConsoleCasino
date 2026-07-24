#ifndef ROULETTE_H

#define ROULETTE_H

#include <vector>

void roulette_map();

int straight_up_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int red_black_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int even_odd_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int row_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int column_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int four_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int six_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int corner_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int high_low_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int split_bet(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);

int roulette_initial_bets(std::vector<std::vector<int>> &bets, int cash, std::vector<std::string> &bets_names);
int roulette(int cash);

#endif // ROULETTE_H

