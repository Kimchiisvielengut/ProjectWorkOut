#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define COUNT 0

typedef struct _worktype{
	char plus_work[20];// �߰��� � �����ϴ� ����
	int sets;// � ����� ��Ʈ�� ���� ����
} worktype;
worktype weight[11];

int num = 0; // � ������ ������ �����ִ� ����
int knt; // � ��Ʈ�� ������ �����ִ� ����
int plusminus = 0;
int copy[11];
int paste[11];
int nummer;

void cycling() // � �߰��� � ������ ������ִ� �Լ�
{
	for (int cnt = 0; cnt < num; cnt++)
	{
		printf("\n%d. %s   %d��Ʈ\n", cnt + 1, weight[cnt].plus_work, weight[cnt].sets);
	}
}

void delete_sets()
{
	printf("\n������ ��� ��ȣ�� �Է� :");
	scanf("%d", &nummer);
	printf("%s %d��Ʈ ����", weight[nummer - 1].plus_work, weight[nummer - 1].sets);
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

void delete_wk()// � ���� �Լ�
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
			printf("�߸��� �Է�");
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
				system("cls");
				cycling();
				printf("\n��� �߰��Ϸ��� '11', �����Ϸ��� '12'�� �Է� :");
				
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
