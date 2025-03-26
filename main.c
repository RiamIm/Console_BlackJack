#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <process.h>
#include <windows.h>
#include "card.h"

#define SPADE   '♠'
#define CLUB    '♣'
#define HEART   '♥'
#define DIAMOND '◆'
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
    printf("					   시작 하시겠습니까?\n");
    printf("					  ------------------\n");
    printf("					         (Y/N)\n                         \n");
    ch = _getch();

    while (!(ch == 89 || ch == 121 || ch == 78 || ch == 110))
    {
        printf("\n");
        printf("잘못된 키를 누르셨습니다. Y 또는 N 을 눌러주세요.\n");
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
    printf("		메뉴\n");
    printf("1. 게임 시작\n");
    printf("2. 룰 보기\n");
    printf("3. 게임 종료\n");
    printf("숫자를 입력해주세요.: ");
    scanf_s("%d", &choice);

    while (choice < 1 || choice > 3)
    {
        printf("잘못된 숫자를 입력하셨습니다. 1 ~ 3 중에서 선택해 주세요.\n");
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
    printf("		게임 룰\n");
    printf("1. 이 게임은 블랙잭입니다.\n");
    printf("2. 목표는 카드의 합이 21에 최대한 가깝게 만드는 것입니다.\n");
    printf("3. 각 카드는 다음과 같은 값을 가집니다:\n");
    printf("   - 숫자 카드: 해당 숫자 값\n");
    printf("   - J, Q, K: 10\n");
    printf("   - A: 1 또는 11 (플레이어의 선택에 따라)\n");
    printf("4. 플레이어와 딜러는 각각 두 장의 카드를 받습니다.\n");
    printf("5. 플레이어는 추가 카드를 요청할 수 있습니다 ('Hit').\n");
    printf("6. 플레이어가 'Stand'를 선택하면 딜러의 차례가 됩니다.\n");
    printf("7. 딜러는 카드의 합이 17 이상이 될 때까지 카드를 받습니다.\n");
    printf("8. 플레이어의 카드 합이 21을 초과하면 패배합니다 ('Bust').\n");
    printf("9. 딜러의 카드 합이 21을 초과하면 플레이어가 승리합니다.\n");
    printf("10. 플레이어의 카드 합이 딜러의 카드 합보다 높으면 승리합니다.\n");
    printf("11. 딜러의 카드 합이 플레이어의 카드 합보다 높으면 패배합니다.\n");
    printf("12. 카드 합이 같으면 무승부입니다.\n");
    printf("\n게임을 시작하려면 아무 키나 누르세요.\n");
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
        printf("히트 하시겠습니까? (Y/N): ");
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
            printf("\n잘못된 입력입니다. Y 또는 N을 눌러주세요.\n");
        }
    }
}

void deal_initial_cards()
{
    printf("딜러의 카드:\n");
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
            dealer_cards[dealer_card_count++] = card[random] + '0'; // 숫자를 문자로 변환
            totalscore_calculate_nonAce(random + 1, &g_dealer_total);
        }
    }
    print_dealer_back_cards();

    printf("\n플레이어의 카드:\n");
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
            player_cards[player_card_count++] = card[random] + '0'; // 숫자를 문자로 변환
            totalscore_calculate_nonAce(random + 1, &g_player_total);
        }
    }
    print_player_cards();
}

void hit()
{
    system("cls"); // 콘솔 창을 지웁니다.
    printf("\n플레이어가 카드를 받았습니다\n");
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
    printf("\n딜러의 카드\n");
    print_dealer_back_cards(); // 딜러의 카드를 다시 출력합니다.
    printf("\n플레이어의 카드\n");
    print_player_cards(); // 플레이어의 카드를 다시 출력합니다.
}

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
            case 4: printf("│    %c    │ ", SPADE); break;
            case 5: printf("│         │ "); break;
            case 6: printf("│         │ "); break;
            case 7: printf("│       %2c│ ", player_cards[i]); break;
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
            case 4: printf("│    %c    │ ", SPADE); break;
            case 5: printf("│         │ "); break;
            case 6: printf("│         │ "); break;
            case 7: printf("│       %2c│ ", dealer_cards[i]); break;
            case 8: printf("└─────────┘ "); break;
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
            case 0: printf("┌─────────┐ "); break;
            case 1: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 2: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 3: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 4: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 5: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 6: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 7: printf("│▒▒▒▒▒▒▒▒▒│ "); break;
            case 8: printf("└─────────┘ "); break;
            }
        }
        printf("\n");
    }
}

void dealer_cards_open()
{
    system("cls");
    printf("\n딜러의 카드\n");
    print_dealer_cards();
    printf("\n플레이어의 카드\n");
    print_player_cards();
    printf("플레이어 점수: %d\n", g_player_total);
}

void totalscore_calculate_nonAce(int score, int* who)
{
    *who += score;
}

//void totalscore_calculate_Ace(int score, int* who)
//{
//    if ()
//}