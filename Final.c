#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define COUNT 0
#define worksize 20
//char exer(int pp);

typedef struct _worktype {
    char plus_work[worksize];// 추가된 운동 저장하는 변수
    int sets;// 운동 종목당 세트수 설정 변수
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

int num = 0; // 운동 종목의 순서를 정해주는 변수
//int knt; // 운동 세트의 순서를 정해주는 변수 //왜 있는지 모르겠음
int plusminus = 0;
int number;            //tlqkf 동훈아 독일어좀 빼봐 number 다 영어로 적는데 헷갈리잖아
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
        printf("1. 개인운동 시작\n");
        printf("\n2. 맨몸운동 루틴\n");
        printf("\n3. 가슴운동 루틴\n");
        printf("\n4. 등 운동 루틴\n");
        printf("\n5. 하체운동 루틴\n");
        printf("\n6. 종료\n\n");

        scanf("%d", &work);

        switch (work) {
        case 1:
            printf("개인운동을 선택하셨습니다.\n");
            return 1;
            break;
        case 2:
            printf("맨몸운동을 선택하셨습니다.\n");
            return 2;
            break;
        case 3:
            printf("가슴운동을 선택하셨습니다.\n");
            return 3;
            break;
        case 4:
            printf("등운동을 선택하셨습니다.\n");
            return 4;
            break;
        case 5:
            printf("하체운동을 선택하셨습니다.\n");
            return 5;
            break;
        case 6:
            printf("종료하시겠습니까?\n");
            printf("맞다면 1번, 아니라면 아무 숫자나 눌러주세요.\n");
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
            printf("종료하시겠습니까?\n");
            printf("맞다면 1번, 아니라면 아무 숫자나 눌러주세요.\n");
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
    printf("%d년 %d월 %d일 %d시 %d분\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
    end.year = t->tm_year + 1900, end.mon = t->tm_mon + 1, end.day = t->tm_mday, end.hour = t->tm_hour, end.min = t->tm_min, end.sec = t->tm_sec;
    printf("총 운동시간: %d시간 %d분 %d초 \n", abs(start.hour - end.hour), abs(start.min - end.min), abs(start.sec - end.sec));
    printf("운동 종료\n\n\n");
    for (int i = 0; i < next_wk; i++)
    {
        printf("\n%s\n", weight[i].plus_work);
        for (int x = 0; x < weight[i].sets; x++)
        {
            printf("  \n%d세트 - %dkg %d회", x + 1, saveall[i].kg[x], saveall[i].getsu[x]);
        }
        printf("\n수행\n\n");
    }
}

void start_work() // 오전 오후 생각
{
    system("cls");
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);
    
    printf("\n%d년 %d월 %d일 %d시 %d분 운동시작", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);
    start.year = t->tm_year + 1900, start.mon = t->tm_mon + 1, start.day = t->tm_mday, start.hour = t->tm_hour, start.min = t->tm_min, start.sec = t->tm_sec;
    for (int x = 0; x < next_wk; x++)
    {
        for (int i = 0; i < weight[x].sets; i++)
        {
            saveall[x].sets[i] = i + 1;
            printf("\n%s, %d세트 시작\n", weight[x].plus_work, i + 1);
            fflush(stdin);
            printf("\n세트가 끝날 시 엔터: \n");
            printf("\n\n\n중량(kg) 입력: ");
            scanf("%d", &weight[x].kg);
            saveall[x].kg[i] = weight[x].kg;
            printf("\n갯수 입력: ");
            scanf("%d", &weight[x].getsu);
            saveall[x].getsu[i] = weight[x].getsu;
            printf("\n휴식시간(sec) 입력: ");
            scanf("%d", &weight[x].rest);
            saveall[x].rest[i] = weight[x].rest;
            for (int k = weight[x].rest; k > 0; k--) // 
            {
                printf("%d\n", k);
                Sleep(1000);
            } //1. 데드리프트 1세트 60kg 5개\n 데드리프트 2세트 70 3개\n ......
            printf("%s %d세트 끝\n", weight[x].plus_work, i + 1);
            printf("\n중량: %dkg, %d개만큼 수행", saveall[x].kg[i], saveall[x].getsu[i]);
            Sleep(3000);
            system("cls");
            printf("\n");
        }
    }
    end_work();
}

void cycling() // 운동 추가시 운동 종목을 출력해주는 함수
{
    int cnt;
    for (cnt = 0; cnt < num; cnt++)
    {
        printf("\n%d. %s   \n", cnt + 1, weight[cnt].plus_work);
    }
    next_wk = cnt;
}

void delete_wk()// 운동 삭제 함수
{
    int is_found = 0;

    printf("\n삭제할 운동의 번호를 입력 :");
    scanf("%d", &number);

    if (number == 0 || number > num)
    {
        printf("잘못된 입력");
        Sleep(1000);
        return;
    }

    printf("%s %d세트 삭제", weight[number - 1].plus_work, weight[number - 1].sets);
    Sleep(1000);

    while (1)
    {
        for (int i = 0; i < num; i++)         //목록에 있는 수만큼 반복해서 제거할 번호 찾기
        {
            if (i == number - 1)
                is_found = 1;

            if (is_found == 1)
            {
                for (int j = 0; j < worksize; j++)            //문자열 하나 하나 옮겨주는거
                {
                    weight[i].plus_work[j] = weight[i + 1].plus_work[j];
                }
                weight[i].sets = weight[i + 1].sets;         // 세트 수 옮겨주기
            }
        }

        if (is_found == 1)                              //운동을 지워줬기 때문에 운동 수 하나 줄여주기
        {
            num--;
            return;
        }
    }
}

int selects(int a)
{

    if (a == 1) // 개인운동 -> 운동 종목, 세트 수, 갯 수를 임의로 정하는 선택지
    {
        while (1)
        {
            system("cls");
            cycling();
            printf("\n\n추가할 운동을 입력 :");
            scanf("%s", weight[num].plus_work);
            printf("\n%s의 세트 수를 입력 :\n", weight[num].plus_work);
            scanf("%d", &weight[num].sets);
            system("cls");
            printf("%s %d세트\n", weight[num].plus_work, weight[num].sets);
            num++;
            printf("\n운동 추가 완료\n");
            Sleep(1500);
        nre:
            system("cls");
            cycling();
            printf("\n운동을 추가하려면 '11', 삭제하려면 '12', 시작하려면 아무 숫자나 입력 :");
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
        printf("File open에 오류 발생");
        exit(1);
    }

    int A;
    int sets;
    A = start_screen();               //운동 선택창

    if (A == 1)                     //텍스트 파일에 운동 입력
        fputs("개인운동 ", fp);
    else if (A == 2)
        fputs("맨몸운동 ", fp);
    else if (A == 3)
        fputs("가슴운동 ", fp);
    else if (A == 4)
        fputs("등운동 ", fp);
    else if (A == 5)
        fputs("하체운동 ", fp);

    sets = selects(A);               //세트 선택창

    fprintf(fp, "%d개", sets);            //이중 if 써서 걍 한번에 입력 하게끔 하면 편할듯

    //printf("%d", sets);

    fclose(fp);

    return 0;
}