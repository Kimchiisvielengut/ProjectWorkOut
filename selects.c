#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define COUNT 0

typedef struct _worktype{
	char plus_work[20];// �߰��� � �����ϴ� ����
	int sets;// � ����� ��Ʈ�� ���� ����
} worktype;
worktype weight[10];

int num; // � ������ ������ �����ִ� ����
int knt; // � ��Ʈ�� ������ �����ִ� ����

void cycling() // � �߰��� � ������ ������ִ� �Լ�
{
	for (int cnt = 0; cnt < num; cnt++)
	{
		printf("\n%s\n", weight[cnt].plus_work);
	}
}

void delete_wk(int index)// � ���� �Լ�
{
	for (int i = index; i < COUNT; i++)
	{
		*plus_work[i] = plus_work[i + 1];
	}
}

int selects(int a)
{

	int plus = 0; // � �߰� �� �� ���ϰ��� ��ȯ�� ���� 

	if (a == 1) // ���ο -> � ����, ��Ʈ ��, �� ���� ���Ƿ� ���ϴ� ������
	{
		
			while (1) 
			{
				if (plus_work == 0)
				{
					printf("\n�߰��� � ����\n");
					printf("\n�߰��� ��� �Է� :");
				}
				else
				{
					cycling();
					printf("\n�߰��� ��� �Է� :");
				}
				scanf("%s", plus_work[num]);
				printf("\n%s�� ��Ʈ ���� �Է� :\n", plus_work[num]);
				scanf("%d", &sets[knt]);
				system("cls");
				printf("%s %d��Ʈ\n", plus_work[num], sets[knt]);
				num++;
				knt++;
				printf("\n� �߰� �Ϸ�\n");
				Sleep(1000);
				printf("\n� �߰��Ϸ��� 1��, ��� �����Ϸ��� �ƹ� ���ڸ� �Է� :");
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
