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
		printf("File open에 오류 발생");
		exit(1);
	}

	int A;					
	int sets;				
	A = start_screen();					//운동 선택창
	
	if (A == 1)							//텍스트 파일에 운동 입력
		fputs("개인운동 ", fp);
	else if (A == 2)
		fputs("맨몸운동 ", fp);
	else if (A == 3)
		fputs("가슴운동 ", fp);
	else if (A == 4)
		fputs("등운동 ", fp);
	else if (A == 5)
		fputs("하체운동 ", fp);

	sets = selects(A);					//세트 선택창

	fprintf(fp, "%d개", sets);				//이중 if 써서 걍 한번에 입력 하게끔 하면 편할듯

	//printf("%d", sets);

	fclose(fp);

	return 0;
}

//char exer(int pp, int sets)
//{
//	if (pp == 1)
//		fputs("개인운동 %d세트\n", fp); 
//	else if (pp == 2)
//		return "맨몸운동";
//	else if (pp == 3)
//		return "가슴운동";
//	else if (pp == 4)
//		return "등운동";
//	else if (pp == 5)
//		return "하체운동";
//}