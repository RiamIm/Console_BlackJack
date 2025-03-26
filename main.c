#include "game.h"
#include "card.h"

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
    printf("					 �����ϰ� �ִ� ��: %d\n", g_cash);
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
        quit_game();
        break;
    }
}

void quit_game()
{
    system("cls");
    printf("������ �����մϴ�.\n");
    // ���� �� ��� ���
    system("pause");
    exit(0);
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
    betting_money();
    system("cls");
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

void betting_money()
{
    int bet_money;
    print_money();
    printf("\n\n\n ������ �ݾ��� �Է��ϼ���.: ");
    scanf_s(" %d", &bet_money);
    g_bet_money = bet_money;
    g_cash -= bet_money;
}

void deal_initial_cards()
{
    print_money();
    printf("\n���� ������ �ݾ�: %d\n", g_bet_money);
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
            totalscore_calculate_Ace_for_dealer(&g_dealer_total);
        }
        else
        {
            dealer_cards[dealer_card_count++] = card[random] + '0'; // ���ڸ� ���ڷ� ��ȯ
            totalscore_calculate_nonAce(random + 1, &g_dealer_total);
        }
    }
    print_dealer_back_cards();
    printf("���� ���� ����: ??\n");
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
            system("cls");
            player_cards[player_card_count++] = 'A';
            totalscore_calculate_Ace_for_player(&g_player_total);
            print_money();
            printf("\n���� ������ �ݾ�: %d\n", g_bet_money);
            printf("\n������ ī��\n");
            print_dealer_back_cards();
            printf("���� ���� ����: ??\n");
        }
        else
        {
            player_cards[player_card_count++] = card[random] + '0'; // ���ڸ� ���ڷ� ��ȯ
            totalscore_calculate_nonAce(random + 1, &g_player_total);
        }
    }
    print_player_cards();
    printf("�÷��̾� ���� ����: %d\n", g_player_total);
}

void hit()
{
    system("cls");
    print_money();
    printf("\n���� ������ �ݾ�: %d\n", g_bet_money);
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
        totalscore_calculate_Ace_for_player(&g_player_total);
        print_money();
    }
    else
    {
        player_cards[player_card_count++] = card[random] + '0';
        totalscore_calculate_nonAce(random + 1, &g_player_total);
    }
    printf("\n������ ī��\n");
    print_dealer_back_cards();
    printf("���� ���� ����: ??\n");
    printf("\n�÷��̾��� ī��\n");
    print_player_cards();
    printf("�÷��̾� ���� ����: %d\n", g_player_total);
}

void print_money()
{
    printf("��������������������������������������������������������������������������\n");
    printf("��           ���� �Ӵ� : %3d         ��\n", g_cash);
    printf("��������������������������������������������������������������������������\n");
}

#ifdef _WIN32
#include <Windows.h> // Windows ȯ�濡�� Sleep �Լ��� ����ϱ� ����
#else
#include <unistd.h>  // Unix-like ȯ�濡�� sleep �Լ��� ����ϱ� ����
#endif

void dealer_cards_open()
{
    system("cls");
    print_money();
    printf("\n���� ������ �ݾ�: %d\n", g_bet_money);
    printf("������ ī�带 �޾ҽ��ϴ�...\n");
    print_dealer_cards();
    printf("���� ����: %d\n", g_dealer_total);
    printf("\n�÷��̾��� ī��\n");
    print_player_cards();
    printf("�÷��̾� ����: %d\n", g_player_total);
    // ������ ī�� ���� ��, 17 �̸��̸� ��� ī�� �̱�
    while (g_dealer_total <= 16)
    {
#ifdef _WIN32
        Sleep(1000);       // 1�� ���
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
        printf("\n���� ������ �ݾ�: %d\n", g_bet_money);
        printf("������ ī�带 �޾ҽ��ϴ�...\n");
        print_dealer_cards();
        printf("���� ����: %d\n", g_dealer_total);
        printf("\n�÷��̾��� ī��\n");
        print_player_cards();
        printf("�÷��̾� ����: %d\n", g_player_total);
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
        printf("\n���� ������ �ݾ�: %d\n", g_bet_money);
        printf("\n������ ī��\n");
        print_dealer_back_cards();
        printf("���� ���� ����: ??\n");
        printf("\n�÷��̾��� ī��\n");
        print_player_cards();
        printf("�÷��̾� ���� ����: %d\n", *player);
        printf("Ace ī�带 1������ �Ͻðڽ��ϱ�? (Y: 1�� / N: 11��): ");
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
            printf("Y �Ǵ� N�� �Է����ּ���.\n");
        }
    }
    system("cls");
}
