#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <process.h>
#include <windows.h>
#include "card.h"

#define SPADE   '��'
#define CLUB    '��'
#define HEART   '��'
#define DIAMOND '��'
#define TRUE 1
#define FALSE 0

int g_cash = 500;
int g_won;
int g_lost;
int g_player_total;
int g_dealer_total;
int card[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
char ch[3] = { 'J', 'Q', 'K' };

char player_cards[10];
int player_card_count = 0;
char dealer_cards[10];
int dealer_card_count = 0;

void init();
void print_title();
void print_rule();
void print_menu();
void play();
void deal_initial_cards();
void hit();
void print_player_cards();
void print_dealer_cards();
void print_dealer_back_cards();
void dealer_cards_open();
void totalscore_calculate_nonAce(int score, int* who);

int main(void)
{
    srand(time(NULL));
    init();
    print_title();

    return 0;
}

void init()
{
    g_player_total = 0;
    g_dealer_total = 0;
}

void print_title()
{
    int ch;
    printf(" ____       ___                         __          _____                       __         \n");
    printf("/\\  _`\\    /\\_ \\                       /\\ \\        /\\___ \\                     /\\ \\        \n");
    printf("\\ \\ \\L\\ \\  \\//\\ \\       __       ___   \\ \\ \\'\\    \\/__\\/\\ \\     __       ___   \\ \\ \\'\\    \n");
    printf(" \\ \\  _ <'   \\ \\ \\    /'__`\\    /'___\\  \\ \\ , <       _\\ \\ \\  /'__`\\    /'___\\  \\ \\ , <    \n");
    printf("  \\ \\ \\L\\ \\   \\_\\ \\_ /\\ \\L\\._/ /\\ \\__/   \\ \\ \\\\`\\    /\\ \\_\\ \\/\\ \\L\\._/ /\\ \\__/   \\ \\ \\\\`\\  \n");
    printf("   \\ \\____/   /\\____\\\\ \\__/\\_\\\\ \\____\\    \\ \\_\\ \\_\\  \\ \\____/\\ \\__/\\_\\\\ \\____\\    \\ \\_\\ \\_\\\n");
    printf("    \\/___/    \\/____/ \\/__/\\/_/ \\/____/    \\/_/\\/_/   \\/___/  \\/__/\\/_/ \\/____/    \\/_/\\/_/\n");
    printf("\n\n");
    printf("					   ���� �Ͻðڽ��ϱ�?\n");
    printf("					  ------------------\n");
    printf("					         (Y/N)\n                         \n");
    ch = _getch();

    while (!(ch == 89 || ch == 121 || ch == 78 || ch == 110))
    {
        printf("\n");
        printf("�߸��� Ű�� �����̽��ϴ�. Y �Ǵ� N �� �����ּ���.\n");
        ch = _getch();
    }

    if (ch == 89 || ch == 121)
    {
        print_menu();
    }
}

void print_menu()
{
    int choice;
    system("cls");
    printf("		�޴�\n");
    printf("1. ���� ����\n");
    printf("2. �� ����\n");
    printf("3. ���� ����\n");
    printf("���ڸ� �Է����ּ���.: ");
    scanf_s("%d", &choice);

    while (choice < 1 || choice > 3)
    {
        printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�. 1 ~ 3 �߿��� ������ �ּ���.\n");
        scanf_s("%d", &choice);
    }
    switch (choice)
    {
    case 1:
        system("cls");
        play();
        break;
    case 2:
        system("cls");
        print_rule();
        break;
    case 3:
        break;
    }
}

void print_rule()
{
    printf("		���� ��\n");
    printf("1. �� ������ �����Դϴ�.\n");
    printf("2. ��ǥ�� ī���� ���� 21�� �ִ��� ������ ����� ���Դϴ�.\n");
    printf("3. �� ī��� ������ ���� ���� �����ϴ�:\n");
    printf("   - ���� ī��: �ش� ���� ��\n");
    printf("   - J, Q, K: 10\n");
    printf("   - A: 1 �Ǵ� 11 (�÷��̾��� ���ÿ� ����)\n");
    printf("4. �÷��̾�� ������ ���� �� ���� ī�带 �޽��ϴ�.\n");
    printf("5. �÷��̾�� �߰� ī�带 ��û�� �� �ֽ��ϴ� ('Hit').\n");
    printf("6. �÷��̾ 'Stand'�� �����ϸ� ������ ���ʰ� �˴ϴ�.\n");
    printf("7. ������ ī���� ���� 17 �̻��� �� ������ ī�带 �޽��ϴ�.\n");
    printf("8. �÷��̾��� ī�� ���� 21�� �ʰ��ϸ� �й��մϴ� ('Bust').\n");
    printf("9. ������ ī�� ���� 21�� �ʰ��ϸ� �÷��̾ �¸��մϴ�.\n");
    printf("10. �÷��̾��� ī�� ���� ������ ī�� �պ��� ������ �¸��մϴ�.\n");
    printf("11. ������ ī�� ���� �÷��̾��� ī�� �պ��� ������ �й��մϴ�.\n");
    printf("12. ī�� ���� ������ ���º��Դϴ�.\n");
    printf("\n������ �����Ϸ��� �ƹ� Ű�� ��������.\n");
    _getch();
    system("cls");
    print_menu();
}

void play()
{
    deal_initial_cards();

    char choice;
    while (TRUE)
    {
        printf("��Ʈ �Ͻðڽ��ϱ�? (Y/N): ");
        choice = _getch();
        if (choice == 'Y' || choice == 'y')
        {
            hit();
        }
        else if (choice == 'N' || choice == 'n')
        {
            dealer_cards_open();
            break;
        }
        else
        {
            printf("\n�߸��� �Է��Դϴ�. Y �Ǵ� N�� �����ּ���.\n");
        }
    }
}

void deal_initial_cards()
{
    printf("������ ī��:\n");
    for (int i = 0; i < 2; i++)
    {
        int random = rand() % 10;
        if (random == 9)
        {
            int ch_random = rand() % 3;
            dealer_cards[dealer_card_count++] = ch[ch_random];
            totalscore_calculate_nonAce(10, &g_dealer_total);
        }
        else if (random == 0)
        {
            dealer_cards[dealer_card_count++] = 'A';
        }
        else
        {
            dealer_cards[dealer_card_count++] = card[random] + '0'; // ���ڸ� ���ڷ� ��ȯ
            totalscore_calculate_nonAce(random + 1, &g_dealer_total);
        }
    }
    print_dealer_back_cards();

    printf("\n�÷��̾��� ī��:\n");
    for (int i = 0; i < 2; i++)
    {
        int random = rand() % 10;
        if (random == 9)
        {
            int ch_random = rand() % 3;
            player_cards[player_card_count++] = ch[ch_random];
            totalscore_calculate_nonAce(10, &g_player_total);
        }
        else if (random == 0)
        {
            player_cards[player_card_count++] = 'A';
        }
        else
        {
            player_cards[player_card_count++] = card[random] + '0'; // ���ڸ� ���ڷ� ��ȯ
            totalscore_calculate_nonAce(random + 1, &g_player_total);
        }
    }
    print_player_cards();
}

void hit()
{
    system("cls"); // �ܼ� â�� ����ϴ�.
    printf("\n�÷��̾ ī�带 �޾ҽ��ϴ�\n");
    int random = rand() % 10;
    if (random == 9)
    {
        int ch_random = rand() % 3;
        player_cards[player_card_count++] = ch[ch_random];
        totalscore_calculate_nonAce(10, &g_player_total);
    }
    else if (random == 0)
    {
        player_cards[player_card_count++] = 'A';
    }
    else
    {
        player_cards[player_card_count++] = card[random] + '0';
        totalscore_calculate_nonAce(random + 1, &g_player_total);
    }
    printf("\n������ ī��\n");
    print_dealer_back_cards(); // ������ ī�带 �ٽ� ����մϴ�.
    printf("\n�÷��̾��� ī��\n");
    print_player_cards(); // �÷��̾��� ī�带 �ٽ� ����մϴ�.
}

void print_player_cards()
{
    for (int line = 0; line < 9; line++)
    {
        for (int i = 0; i < player_card_count; i++)
        {
            switch (line)
            {
            case 0: printf("���������������������� "); break;
            case 1: printf("��%2c       �� ", player_cards[i]); break;
            case 2: printf("��         �� "); break;
            case 3: printf("��         �� "); break;
            case 4: printf("��    %c    �� ", SPADE); break;
            case 5: printf("��         �� "); break;
            case 6: printf("��         �� "); break;
            case 7: printf("��       %2c�� ", player_cards[i]); break;
            case 8: printf("���������������������� "); break;
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
            case 0: printf("���������������������� "); break;
            case 1: printf("��%2c       �� ", dealer_cards[i]); break;
            case 2: printf("��         �� "); break;
            case 3: printf("��         �� "); break;
            case 4: printf("��    %c    �� ", SPADE); break;
            case 5: printf("��         �� "); break;
            case 6: printf("��         �� "); break;
            case 7: printf("��       %2c�� ", dealer_cards[i]); break;
            case 8: printf("���������������������� "); break;
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
            case 0: printf("���������������������� "); break;
            case 1: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 2: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 3: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 4: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 5: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 6: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 7: printf("���ƢƢƢƢƢƢƢƢƦ� "); break;
            case 8: printf("���������������������� "); break;
            }
        }
        printf("\n");
    }
}

void dealer_cards_open()
{
    system("cls");
    printf("\n������ ī��\n");
    print_dealer_cards();
    printf("\n�÷��̾��� ī��\n");
    print_player_cards();
    printf("�÷��̾� ����: %d\n", g_player_total);
}

void totalscore_calculate_nonAce(int score, int* who)
{
    *who += score;
}

//void totalscore_calculate_Ace(int score, int* who)
//{
//    if ()
//}