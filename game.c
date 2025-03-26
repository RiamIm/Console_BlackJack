#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#ifdef _WIN32
#include <Windows.h> // Windows 환경에서 Sleep 함수를 사용하기 위함
#else
#include <unistd.h>  // Unix-like 환경에서 sleep 함수를 사용하기 위함
#endif

void init()
{
    g_player_total = 0;
    g_dealer_total = 0;
    player_card_count = 0;
    dealer_card_count = 0;
    for (int i = 0; i < 10; i++)
    {
        player_cards[i] = '\0';
        dealer_cards[i] = '\0';
    }
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

    if (ch == 78 || ch == 110)
    {
        quit_game();
    }
}

void print_menu()
{
    int choice;
    system("cls");
    print_money();
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("        메뉴\n");
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
        quit_game();
        break;
    }
}

void quit_game()
{
    system("cls");
    printf("게임을 종료합니다.\n");
    // 종료 전 잠시 대기
    system("pause");
    exit(0);
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
    if (_getch())
    {
        system("cls");
        print_menu();
    }
}

void play()
{
    is_bust = 0;
    betting_money();
    system("cls");
    deal_initial_cards();
    char choice;
    while (TRUE)
    {
        printf("히트 하시겠습니까? (Y/N): ");
        choice = _getch();
        if (choice == 'Y' || choice == 'y')
        {
            hit();
            if (is_bust)
            {
                printf("다시 하시겠습니까? (Y/N): ");
                choice = _getch();
                if (choice == 'Y' || choice == 'y')
                {
                    system("cls");
                    init();
                    play();
                }
                else if (choice == 'N' || choice == 'n')
                {
                    print_menu();
                }
                break;
            }
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

void player_bust()
{
    printf("플레이어 버스트!!!\n");
#ifdef _WIN32
    Sleep(3000);       // 3초 대기
#else
    sleep(1);
#endif

    printf("배팅한 금액을 잃었습니다.....\n");
    is_bust = 1;
}

void betting_money()
{
    int bet_money;
    print_money();
    printf("\n\n\n 배팅할 금액을 입력하세요.: ");
    scanf_s(" %d", &bet_money);
    g_bet_money = bet_money;
    g_cash -= bet_money;
}

void deal_initial_cards()
{
    print_money();
    printf("\n현재 배팅한 금액: %d\n", g_bet_money);
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
            totalscore_calculate_Ace_for_dealer(&g_dealer_total);
        }
        else
        {
            dealer_cards[dealer_card_count++] = card[random] + '0'; // 숫자를 문자로 변환
            totalscore_calculate_nonAce(random + 1, &g_dealer_total);
        }
    }
    print_dealer_back_cards();
    printf("딜러 현재 점수: ??\n");
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
            system("cls");
            player_cards[player_card_count++] = 'A';
            totalscore_calculate_Ace_for_player(&g_player_total);
            print_money();
            printf("\n현재 배팅한 금액: %d\n", g_bet_money);
            printf("\n딜러의 카드\n");
            print_dealer_back_cards();
            printf("딜러 현재 점수: ??\n");
        }
        else
        {
            player_cards[player_card_count++] = card[random] + '0'; // 숫자를 문자로 변환
            totalscore_calculate_nonAce(random + 1, &g_player_total);
        }
    }
    print_player_cards();
    printf("플레이어 현재 점수: %d\n", g_player_total);
}

void hit()
{
    system("cls");
    print_money();
    printf("\n현재 배팅한 금액: %d\n", g_bet_money);
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
        totalscore_calculate_Ace_for_player(&g_player_total);
        print_money();
    }
    else
    {
        player_cards[player_card_count++] = card[random] + '0';
        totalscore_calculate_nonAce(random + 1, &g_player_total);
    }
    printf("\n딜러의 카드\n");
    print_dealer_back_cards();
    printf("딜러 현재 점수: ??\n");
    printf("\n플레이어의 카드\n");
    print_player_cards();
    printf("플레이어 현재 점수: %d\n", g_player_total);
    if (g_player_total > 21)
    {
        player_bust();
    }
}

void print_money()
{
    printf("┌───────────────────────────────────┐\n");
    printf("│           현재 머니 : %3d         │\n", g_cash);
    printf("└───────────────────────────────────┘\n");
}

void dealer_cards_open()
{
    system("cls");
    print_money();
    printf("\n현재 배팅한 금액: %d\n", g_bet_money);
    printf("딜러가 카드를 받았습니다...\n");
    print_dealer_cards();
    printf("딜러 점수: %d\n", g_dealer_total);
    printf("\n플레이어의 카드\n");
    print_player_cards();
    printf("플레이어 점수: %d\n", g_player_total);
    // 딜러의 카드 오픈 전, 17 미만이면 계속 카드 뽑기
    while (g_dealer_total <= 16)
    {
#ifdef _WIN32
        Sleep(1000);       // 1초 대기
#else
        sleep(1);
#endif
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
            totalscore_calculate_Ace_for_dealer(&g_dealer_total);
        }
        else
        {
            dealer_cards[dealer_card_count++] = card[random] + '0';
            totalscore_calculate_nonAce(random + 1, &g_dealer_total);
        }

        system("cls");
        print_money();
        printf("\n현재 배팅한 금액: %d\n", g_bet_money);
        printf("딜러가 카드를 받았습니다...\n");
        print_dealer_cards();
        printf("딜러 점수: %d\n", g_dealer_total);
        printf("\n플레이어의 카드\n");
        print_player_cards();
        printf("플레이어 점수: %d\n", g_player_total);
    }
}

void totalscore_calculate_nonAce(int score, int* who)
{
    *who += score;
}

void totalscore_calculate_Ace_for_dealer(int* who)
{
    if (*who + 11 > 21)
    {
        *who += 1;
    }
    else
    {
        *who += 11;
    }
}

void totalscore_calculate_Ace_for_player(int* player)
{
    char ch;
    while (TRUE)
    {
        system("cls");
        print_money();
        printf("\n현재 배팅한 금액: %d\n", g_bet_money);
        printf("\n딜러의 카드\n");
        print_dealer_back_cards();
        printf("딜러 현재 점수: ??\n");
        printf("\n플레이어의 카드\n");
        print_player_cards();
        printf("플레이어 현재 점수: %d\n", *player);
        printf("Ace 카드를 1점으로 하시겠습니까? (Y: 1점 / N: 11점): ");
        ch = _getch();
        if (ch == 89 || ch == 121)
        {
            *player += 1;
            break;
        }
        else if (ch == 78 || ch == 110)
        {
            *player += 11;
            break;
        }
        else
        {
            printf("Y 또는 N을 입력해주세요.\n");
        }
    }
    system("cls");
}
