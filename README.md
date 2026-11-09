# ConsoleCasino

A terminal casino written in C++17. Start with $100, reach $1,600 to pay rent before you go broke. Six games share one cash balance, so a bad run at roulette carries over to blackjack.

Built as a practice project for modern C++ (standard library containers, `<random>`, header/source separation) and for implementing real game rules and payout tables correctly.

## Games

| Game | Notes |
|---|---|
| Blackjack | Dealer stands on 17; hit/stand; ace handling (soft/hard totals) |
| Roulette | European single-zero wheel; 11 bet types (straight, split, street, corner, six line, first four, dozen, column, red/black, odd/even, high/low) at standard payouts |
| Video poker | Jacks-or-better, hold/redraw, 9-tier pay table up to a royal flush |
| Baccarat | Player / banker / tie bets, natural and third-card drawing rules |
| Card walk | Call red/black three times in a row, 6 to 1 |
| Guess the number | 1 to 10, 8 to 1 |

## Build and run

Requires a C++17 compiler (g++ 9+, clang 10+, MSVC 2019+) and CMake 3.15+.

```bash
cmake -S . -B build
cmake --build build
./build/consolecasino        # Windows (MSVC): build\Debug\consolecasino.exe
```

The game uses ANSI escape codes to clear the screen, so on Windows use Windows Terminal or a recent Windows 10+ console.

## Project layout

```
main.cpp          game loop, menu, win/lose conditions
inputcasino.*     validated input helpers (bet amount, menu choice)
blackjack.*       one game per .cpp/.h pair
roulette.*
videopoker.*
baccarat.*
cardwalk.*
guessnumber.*
```

Each game is a function `int game(int cash)` that takes the player's balance and returns the new one.

## Possible extensions

- Three card poker and slots (listed in the menu, not implemented)
- Seeded RNG option for reproducible tests
- Save/load balance
