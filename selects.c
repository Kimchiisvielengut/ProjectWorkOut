#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define COUNT 0

typedef struct _worktype{
	char plus_work[20];// 추가된 운동 저장하는 변수
	int sets;// 운동 종목당 세트수 설정 변수
} worktype;
worktype weight[11];

int num = 0; // 운동 종목의 순서를 정해주는 변수
int knt; // 운동 세트의 순서를 정해주는 변수
int plusminus = 0;
int copy[11];
int paste[11];
int nummer;

void cycling() // 운동 추가시 운동 종목을 출력해주는 함수
{
	for (int cnt = 0; cnt < num; cnt++)
	{
		printf("\n%d. %s   %d세트\n", cnt + 1, weight[cnt].plus_work, weight[cnt].sets);
	}
}

void delete_sets()
{
	printf("\n삭제할 운동의 번호를 입력 :");
	scanf("%d", &nummer);
	printf("%s %d세트 삭제", weight[nummer - 1].plus_work, weight[nummer - 1].sets);
	Sleep(1000);
	for (int i = 0; i < 10; i++)
	{
		if (i < nummer)
		{
			copy[i] = weight[i].sets;
		}
		if (i = nummer) return;
		if (i > nummer)
		{
			copy[i - 1] = weight[i].sets;
		}
		weight[i].sets = paste[i];
		weight[i].sets = copy[i];
	 }
	return;
}

void delete_wk()// 운동 삭제 함수
{
	int is_found = 0;

	while (1)
	{
		if (nummer == 0) return;
		for (int i = 0; i < num; i++)
		{
			if (i == nummer - 1)
			{
				is_found = 1;
			}
			if (is_found == 1)
			{
				for (int j = 0; j < 20; j++)
				weight[i].plus_work[j] = weight[i + 1].plus_work[j];
			}
		}
		if (is_found == 1)
		{
			num -= 1;
			return;
		}
		if (is_found == 0)
		{
			printf("잘못된 입력");
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
				system("cls");
				cycling();
				printf("\n운동을 추가하려면 '11', 삭제하려면 '12'를 입력 :");
				
				scanf("%d", &plusminus);

				if (plusminus == 11)
					system("cls");
				else if (plusminus == 12)
				{
					delete_sets();
					delete_wk();
				}
				else if ((plusminus != 11) || (plusminus != 12))
					break;

			}

	}
}
