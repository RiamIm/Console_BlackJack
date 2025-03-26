#ifndef GAME_H
#define GAME_H

extern int is_bust;
extern int g_cash;
extern int g_bet_money;
extern int g_player_total;
extern int g_dealer_total;
extern int card[10];
extern char ch[3];
extern char player_cards[10];
extern int player_card_count;
extern char dealer_cards[10];
extern int dealer_card_count;

void init();
void print_title();
void print_menu();
void quit_game();
void print_rule();
void play();
void player_bust();
void betting_money();
void deal_initial_cards();
void hit();
void print_money();
void dealer_cards_open();
void totalscore_calculate_nonAce(int score, int* who);
void totalscore_calculate_Ace_for_dealer(int* who);
void totalscore_calculate_Ace_for_player(int* player);

#endif // GAME_H
