//typedef로 별명을 붙이는데 구조체 ticket 번호,시간만, 예약자 명, 금액, 좌석종류(R, 일반) 2차원 배열 
//몇행 몇열 5이상 10이하 행, 10이상 20이하 열 
//예약자 비밀번호도 구조체에 들어가있어야함
//파일 처리를 해야함
//제일 처음 구매, 2번 예약정보 확인하는 기능

//파일에 읽고 쓴 정보를 가지고 무언가를 한다고 생각하는게 편하다.

#include"All.h"


int main()
{
	FILE *fp_r,*fp_w;
	char file_flag = FALSE;//파일이 없는 초기 상태 F, 파일이 존재하면 T
	Ticket_Info**Table;
	int row, col;
	int sel;

	fp_r = fopen("C:\\Users\\songd\\temporary_visual_file_IO\\ticket_list.txt", "rt");//열리지 않은것을 닫게되면 오류가 생긴다

	if (fp_r == NULL)
	{
		fp_w = fopen("C:\\Users\\songd\\temporary_visual_file_IO\\ticket_list.txt","wt");
		if (fp_w == NULL)
		{
			printf("파일 개방에 실패 했습니다\n");
			return 0;
		}
	}
	else
		file_flag = TRUE;

	if (file_flag == FALSE)
	{
		srand((unsigned int)time(NULL));
		//파일이 없어서 처음 생성했을 경우
		row = (rand() % 6) + 5;//5~10행
		col = (rand() % 11) + 10;//10~20열

		Table = make_random_table(row, col);
	}
	else
		read_table(fp_r, &Table, &row, &col);

	while (1)
	{
		printf("예매 시스템\n");
		printf("1. 예약하기\n");
		printf("2. 조회하기\n");
		printf("3. 입장하기\n");
		printf("4. 퇴장하기\n");
		printf("5. 종료하기\n");
		printf("메뉴를 선택하세요:\n");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
			system("cls");
			reservation_ticket(&Table, row, col);
			break;
		case 2:
			system("cls");
			check_info(Table, row, col);
			break;
		case 3:
			system("cls");
			start(&Table, row, col);
			break;
		case 4:
			system("cls");
			end(&Table, row, col);
			break;
		case 5:
			if (fp_r != NULL)
			{
				fp_w = fopen("ticket_list.txt", "wt");
				if (fp_w == NULL)
				{
					printf("파일 개방에 실패 했습니다\n");
					return 0;
				}
			}
			record_table(fp_w, Table, row, col);
			fclose(fp_w);
			if (fp_r != NULL)
			{
				fclose(fp_r);
			}
			
			return 0;
		}




	}


}