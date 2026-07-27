#ifndef VIDEOPOKER_H

#define VIDEOPOKER_H

#include <string>
#include <array>

void payouts_show();

int vid_poker(int cash);
bool flush_check(std::array<std::string,5> &hand);
bool straight_check(std::array<int,14> &hand_structure);
std::string hand_name(int multiplier);


#endif // VIDEOPOKER_H
