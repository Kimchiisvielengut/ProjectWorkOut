#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define COUNT 0

typedef struct _worktype{
	char plus_work[20];// 추가된 운동 저장하는 변수
	int sets;// 운동 종목당 세트수 설정 변수
} worktype;
worktype weight[10];

int num; // 운동 종목의 순서를 정해주는 변수
int knt; // 운동 세트의 순서를 정해주는 변수

void cycling() // 운동 추가시 운동 종목을 출력해주는 함수
{
	for (int cnt = 0; cnt < num; cnt++)
	{
		printf("\n%s\n", weight[cnt].plus_work);
	}
}

void delete_wk(int index)// 운동 삭제 함수
{
	for (int i = index; i < COUNT; i++)
	{
		*plus_work[i] = plus_work[i + 1];
	}
}

int selects(int a)
{

	int plus = 0; // 운동 추가 할 시 리턴값을 반환할 변수 

	if (a == 1) // 개인운동 -> 운동 종목, 세트 수, 갯 수를 임의로 정하는 선택지
	{
		
			while (1) 
			{
				if (plus_work == 0)
				{
					printf("\n추가된 운동 없음\n");
					printf("\n추가할 운동을 입력 :");
				}
				else
				{
					cycling();
					printf("\n추가할 운동을 입력 :");
				}
				scanf("%s", plus_work[num]);
				printf("\n%s의 세트 수를 입력 :\n", plus_work[num]);
				scanf("%d", &sets[knt]);
				system("cls");
				printf("%s %d세트\n", plus_work[num], sets[knt]);
				num++;
				knt++;
				printf("\n운동 추가 완료\n");
				Sleep(1000);
				printf("\n운동 추가하려면 1을, 운동을 시작하려면 아무 숫자를 입력 :");
				scanf("%d", &plus);
				if (plus == 1) 
				{
					system("cls");
					continue;
				}
				else
				{
					return 3;
					break;
				}
			}
	}

}
