#include <stdio.h>
#include <Windows.h>

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