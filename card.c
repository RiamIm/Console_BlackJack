#include "card.h"
#include <stdio.h>
#include <stdlib.h>

extern char player_cards[10];
extern int player_card_count;
extern char dealer_cards[10];
extern int dealer_card_count;

void print_player_cards()
{
    for (int line = 0; line < 9; line++)
    {
        for (int i = 0; i < player_card_count; i++)
        {
            switch (line)
            {
            case 0: printf("忙式式式式式式式式式忖 "); break;
            case 1: printf("弛%2c       弛 ", player_cards[i]); break;
            case 2: printf("弛         弛 "); break;
            case 3: printf("弛         弛 "); break;
            case 4: printf("弛         弛 "); break;
            case 5: printf("弛         弛 "); break;
            case 6: printf("弛         弛 "); break;
            case 7: printf("弛       %2c弛 ", player_cards[i]); break;
            case 8: printf("戌式式式式式式式式式戎 "); break;
            }
        }
        printf("\n");
    }
}

void print_dealer_cards()
{
    for (int line = 0; line < 9; line++)
    {
        for (int i = 0; i < dealer_card_count; i++)
        {
            switch (line)
            {
            case 0: printf("忙式式式式式式式式式忖 "); break;
            case 1: printf("弛%2c       弛 ", dealer_cards[i]); break;
            case 2: printf("弛         弛 "); break;
            case 3: printf("弛         弛 "); break;
            case 4: printf("弛         弛 "); break;
            case 5: printf("弛         弛 "); break;
            case 6: printf("弛         弛 "); break;
            case 7: printf("弛       %2c弛 ", dealer_cards[i]); break;
            case 8: printf("戌式式式式式式式式式戎 "); break;
            }
        }
        printf("\n");
    }
}

void print_dealer_back_cards()
{
    for (int line = 0; line < 9; line++)
    {
        for (int i = 0; i < dealer_card_count; i++)
        {
            switch (line)
            {
            case 0: printf("忙式式式式式式式式式忖 "); break;
            case 1: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 2: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 3: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 4: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 5: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 6: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 7: printf("弛〤〤〤〤〤〤〤〤〤弛 "); break;
            case 8: printf("戌式式式式式式式式式戎 "); break;
            }
        }
        printf("\n");
    }
}

