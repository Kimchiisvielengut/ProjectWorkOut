#include <stdio.h>
#include <Windows.h>

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