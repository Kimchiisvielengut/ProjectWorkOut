#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

//char exer(int pp);

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
	A = start_screen();					//� ����â
	
	if (A == 1)							//�ؽ�Ʈ ���Ͽ� � �Է�
		fputs("���ο ", fp);
	else if (A == 2)
		fputs("�Ǹ�� ", fp);
	else if (A == 3)
		fputs("����� ", fp);
	else if (A == 4)
		fputs("�� ", fp);
	else if (A == 5)
		fputs("��ü� ", fp);

	sets = selects(A);					//��Ʈ ����â

	fprintf(fp, "%d��", sets);				//���� if �Ἥ �� �ѹ��� �Է� �ϰԲ� �ϸ� ���ҵ�

	//printf("%d", sets);

	fclose(fp);

	return 0;
}

//char exer(int pp, int sets)
//{
//	if (pp == 1)
//		fputs("���ο %d��Ʈ\n", fp); 
//	else if (pp == 2)
//		return "�Ǹ��";
//	else if (pp == 3)
//		return "�����";
//	else if (pp == 4)
//		return "��";
//	else if (pp == 5)
//		return "��ü�";
//}