#ifndef BACCARAT_H

#define BACCARAT_H

#include <vector>
#include <string>

int card_value(char c);
int hand_value(std::vector<std::string> &hand);
int baccarat(int cash);

#endif // BACCARAT_H
