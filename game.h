#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <process.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

extern int g_cash;
extern int g_won;
extern int g_lost;
extern int g_player_total;
extern int g_dealer_total;
extern int card[10];
extern char ch[3];

extern char player_cards[10];
extern int player_card_count;
extern char dealer_cards[10];
extern int dealer_card_count;

void init();
void quit_game();
void print_title();
void print_rule();
void print_menu();
void betting_money();
void play();
void deal_initial_cards();
void hit();
void print_money();
void dealer_cards_open();
void totalscore_calculate_nonAce(int score, int* who);
void totalscore_calculate_Ace_for_dealer(int* dealer);
void totalscore_calculate_Ace_for_player(int* player);

#endif