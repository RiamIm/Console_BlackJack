#include <stdio.h>
#include "card.h"

void print_back_card()
{
    for (int i = 0; i < 2; i++) printf("���������������������� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���ƢƢƢƢƢƢƢƢƦ� ");
    printf("\n");
    for (int i = 0; i < 2; i++) printf("���������������������� ");
    printf("\n");
}

void print_card(char suit, int value, char face)
{
    printf("����������������������\n");
    if (face == ' ')
    {
        printf("��%2d       ��\n", value);
    }
    else
    {
        printf("��%c        ��\n", face);
    }
    printf("��         ��\n");
    printf("��         ��\n");
    printf("��    %c    ��\n", suit);
    printf("��         ��\n");
    printf("��         ��\n");
    if (face == ' ')
    {
        printf("��       %2d��\n", value);
    }
    else
    {
        printf("��        %c��\n", face);
    }
    printf("����������������������\n");
}
