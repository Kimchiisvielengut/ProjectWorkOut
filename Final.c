#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define COUNT 0
#define worksize 20
//char exer(int pp);

typedef struct _worktype {
    char plus_work[worksize];// �߰��� � �����ϴ� ����
    int sets;// � ����� ��Ʈ�� ���� ����
    int kg;
    int getsu;
    int rest;
} worktype;
worktype weight[11];

struct save_set {
    int sets[10];
    int kg[10];
    int getsu[10];
    int rest[10];
};
struct save_set saveall[11];

int num = 0; // � ������ ������ �����ִ� ����
//int knt; // � ��Ʈ�� ������ �����ִ� ���� //�� �ִ��� �𸣰���
int plusminus = 0;
int number;            //tlqkf ���ƾ� ���Ͼ��� ���� number �� ����� ���µ� �򰥸��ݾ�
int next_wk;
int times;

struct time_wk {
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;
};

struct time_wk start;
struct time_wk end;

int start_screen()
{
    while (1)
    {
        int work = 0, shutdown = 0;
        printf("1. ���ο ����\n");
        printf("\n2. �Ǹ�� ��ƾ\n");
        printf("\n3. ����� ��ƾ\n");
        printf("\n4. �� � ��ƾ\n");
        printf("\n5. ��ü� ��ƾ\n");
        printf("\n6. ����\n\n");

        scanf("%d", &work);

        switch (work) {
        case 1:
            printf("���ο�� �����ϼ̽��ϴ�.\n");
            return 1;
            break;
        case 2:
            printf("�Ǹ���� �����ϼ̽��ϴ�.\n");
            return 2;
            break;
        case 3:
            printf("������� �����ϼ̽��ϴ�.\n");
            return 3;
            break;
        case 4:
            printf("���� �����ϼ̽��ϴ�.\n");
            return 4;
            break;
        case 5:
            printf("��ü��� �����ϼ̽��ϴ�.\n");
            return 5;
            break;
        case 6:
            printf("�����Ͻðڽ��ϱ�?\n");
            printf("�´ٸ� 1��, �ƴ϶�� �ƹ� ���ڳ� �����ּ���.\n");
            scanf("%d", &shutdown);
            if (shutdown == 1) {
                exit(1);
            }
            else
            {
                system("cls");
                continue;
            }
        default:
            printf("�����Ͻðڽ��ϱ�?\n");
            printf("�´ٸ� 1��, �ƴ϶�� �ƹ� ���ڳ� �����ּ���.\n");
            scanf("%d", &shutdown);
            if (shutdown == 1) {
                exit(1);
            }
            else
            {
                system("cls");
                continue;
            }
        }
    }
}

void end_work()
{
    system("cls");
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);
    printf("%d�� %d�� %d�� %d�� %d��\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
    end.year = t->tm_year + 1900, end.mon = t->tm_mon + 1, end.day = t->tm_mday, end.hour = t->tm_hour, end.min = t->tm_min, end.sec = t->tm_sec;
    printf("�� ��ð�: %d�ð� %d�� %d�� \n", abs(start.hour - end.hour), abs(start.min - end.min), abs(start.sec - end.sec));
    printf("� ����\n\n\n");
    for (int i = 0; i < next_wk; i++)
    {
        printf("\n%s\n", weight[i].plus_work);
        for (int x = 0; x < weight[i].sets; x++)
        {
            printf("  \n%d��Ʈ - %dkg %dȸ", x + 1, saveall[i].kg[x], saveall[i].getsu[x]);
        }
        printf("\n����\n\n");
    }
}

void start_work() // ���� ���� ����
{
    system("cls");
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);
    
    printf("\n%d�� %d�� %d�� %d�� %d�� �����", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
    start.year = t->tm_year + 1900, start.mon = t->tm_mon + 1, start.day = t->tm_mday, start.hour = t->tm_hour, start.min = t->tm_min, start.sec = t->tm_sec;
    for (int x = 0; x < next_wk; x++)
    {
        for (int i = 0; i < weight[x].sets; i++)
        {
            saveall[x].sets[i] = i + 1;
            printf("\n%s, %d��Ʈ ����\n", weight[x].plus_work, i + 1);
            fflush(stdin);
            printf("\n��Ʈ�� ���� �� ����: \n");
            printf("\n\n\n�߷�(kg) �Է�: ");
            scanf("%d", &weight[x].kg);
            saveall[x].kg[i] = weight[x].kg;
            printf("\n���� �Է�: ");
            scanf("%d", &weight[x].getsu);
            saveall[x].getsu[i] = weight[x].getsu;
            printf("\n�޽Ľð�(sec) �Է�: ");
            scanf("%d", &weight[x].rest);
            saveall[x].rest[i] = weight[x].rest;
            for (int k = weight[x].rest; k > 0; k--) // 
            {
                printf("%d\n", k);
                Sleep(1000);
            } //1. ���帮��Ʈ 1��Ʈ 60kg 5��\n ���帮��Ʈ 2��Ʈ 70 3��\n ......
            printf("%s %d��Ʈ ��\n", weight[x].plus_work, i + 1);
            printf("\n�߷�: %dkg, %d����ŭ ����", saveall[x].kg[i], saveall[x].getsu[i]);
            Sleep(3000);
            system("cls");
            printf("\n");
        }
    }
    end_work();
}

void cycling() // � �߰��� � ������ ������ִ� �Լ�
{
    int cnt;
    for (cnt = 0; cnt < num; cnt++)
    {
        printf("\n%d. %s   \n", cnt + 1, weight[cnt].plus_work);
    }
    next_wk = cnt;
}

void delete_wk()// � ���� �Լ�
{
    int is_found = 0;

    printf("\n������ ��� ��ȣ�� �Է� :");
    scanf("%d", &number);

    if (number == 0 || number > num)
    {
        printf("�߸��� �Է�");
        Sleep(1000);
        return;
    }

    printf("%s %d��Ʈ ����", weight[number - 1].plus_work, weight[number - 1].sets);
    Sleep(1000);

    while (1)
    {
        for (int i = 0; i < num; i++)         //��Ͽ� �ִ� ����ŭ �ݺ��ؼ� ������ ��ȣ ã��
        {
            if (i == number - 1)
                is_found = 1;

            if (is_found == 1)
            {
                for (int j = 0; j < worksize; j++)            //���ڿ� �ϳ� �ϳ� �Ű��ִ°�
                {
                    weight[i].plus_work[j] = weight[i + 1].plus_work[j];
                }
                weight[i].sets = weight[i + 1].sets;         // ��Ʈ �� �Ű��ֱ�
            }
        }

        if (is_found == 1)                              //��� ������� ������ � �� �ϳ� �ٿ��ֱ�
        {
            num--;
            return;
        }
    }
}

int selects(int a)
{

    if (a == 1) // ���ο -> � ����, ��Ʈ ��, �� ���� ���Ƿ� ���ϴ� ������
    {
        while (1)
        {
            system("cls");
            cycling();
            printf("\n\n�߰��� ��� �Է� :");
            scanf("%s", weight[num].plus_work);
            printf("\n%s�� ��Ʈ ���� �Է� :\n", weight[num].plus_work);
            scanf("%d", &weight[num].sets);
            system("cls");
            printf("%s %d��Ʈ\n", weight[num].plus_work, weight[num].sets);
            num++;
            printf("\n� �߰� �Ϸ�\n");
            Sleep(1500);
        nre:
            system("cls");
            cycling();
            printf("\n��� �߰��Ϸ��� '11', �����Ϸ��� '12', �����Ϸ��� �ƹ� ���ڳ� �Է� :");
            scanf("%d", &plusminus);

            if (plusminus == 11)
            {
                system("cls");
                continue;
            }
            else if (plusminus == 12)
            {
                delete_wk();
                goto nre;
            }
            else if ((plusminus != 11) || (plusminus != 12))
                start_work();
            break;
        }
    }
}

int main(void)
{
    FILE* fp;
    char c[9];
    fp = fopen("exercise.txt", "w");

    if (fp == NULL)
    {
        printf("File open�� ���� �߻�");
        exit(1);
    }

    int A;
    int sets;
    A = start_screen();               //� ����â

    if (A == 1)                     //�ؽ�Ʈ ���Ͽ� � �Է�
        fputs("���ο ", fp);
    else if (A == 2)
        fputs("�Ǹ�� ", fp);
    else if (A == 3)
        fputs("����� ", fp);
    else if (A == 4)
        fputs("�� ", fp);
    else if (A == 5)
        fputs("��ü� ", fp);

    sets = selects(A);               //��Ʈ ����â

    fprintf(fp, "%d��", sets);            //���� if �Ἥ �� �ѹ��� �Է� �ϰԲ� �ϸ� ���ҵ�

    //printf("%d", sets);

    fclose(fp);

    return 0;
}