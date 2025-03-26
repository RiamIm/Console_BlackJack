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
            case 0: printf("┌─────────┐ "); break;
            case 1: printf("│%2c       │ ", player_cards[i]); break;
            case 2: printf("│         │ "); break;
            case 3: printf("│         │ "); break;
            case 4: printf("│         │ "); break;
            case 5: printf("│         │ "); break;
            case 6: printf("│         │ "); break;
            case 7: printf("│       %c │ ", player_cards[i]); break;
            case 8: printf("└─────────┘ "); break;
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
            case 0: printf("┌─────────┐ "); break;
            case 1: printf("│%2c       │ ", dealer_cards[i]); break;
            case 2: printf("│         │ "); break;
            case 3: printf("│         │ "); break;
            case 4: printf("│         │ "); break;
            case 5: printf("│         │ "); break;
            case 6: printf("│         │ "); break;
            case 7: printf("│       %c │ ", dealer_cards[i]); break;
            case 8: printf("└─────────┘ "); break;
            }
        }
        printf("\n");
    }
}

void print_dealer_back_cards()
{
    printf("┌─────────┐ ┌─────────┐\n");
    printf("│ %c       │ │▒▒▒▒▒▒▒▒▒│\n", dealer_cards[0]);
    printf("│         │ │▒▒▒▒▒▒▒▒▒│\n");
    printf("│         │ │▒▒▒▒▒▒▒▒▒│\n");
    printf("│         │ │▒▒▒▒▒▒▒▒▒│\n");
    printf("│         │ │▒▒▒▒▒▒▒▒▒│\n");
    printf("│         │ │▒▒▒▒▒▒▒▒▒│\n");
    printf("│       %c │ │▒▒▒▒▒▒▒▒▒│\n", dealer_cards[0]);
    printf("└─────────┘ └─────────┘\n");
}

