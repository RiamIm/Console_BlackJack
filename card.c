#include <stdio.h>
#include "card.h"

void print_back_card()
{
    for (int i = 0; i < 2; i++) printf("忙式式式式式式式式式忖 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("弛〤〤〤〤〤〤〤〤〤弛 ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("戌式式式式式式式式式戎 ");
    printf("\n");
}

void print_card(char suit, int value, char face)
{
    printf("忙式式式式式式式式式忖\n");
    if (face == ' ')
    {
        printf("弛%2d       弛\n", value);
    }
    else
    {
        printf("弛%c        弛\n", face);
    }
    printf("弛         弛\n");
    printf("弛         弛\n");
    printf("弛    %c    弛\n", suit);
    printf("弛         弛\n");
    printf("弛         弛\n");
    if (face == ' ')
    {
        printf("弛       %2d弛\n", value);
    }
    else
    {
        printf("弛        %c弛\n", face);
    }
    printf("戌式式式式式式式式式戎\n");
}
