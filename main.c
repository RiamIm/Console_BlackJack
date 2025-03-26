#include "game.h"
#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int is_bust = 0;
int g_cash = 100;
int g_bet_money;
int g_player_total;
int g_dealer_total;
int card[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
char ch[3] = { 'J', 'Q', 'K' };

char player_cards[10];
int player_card_count = 0;
char dealer_cards[10];
int dealer_card_count = 0;

int main(void)
{
    srand(time(NULL));
    init();
    print_title();

    system("pause");

    return 0;
}

