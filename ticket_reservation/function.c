#include"All.h"

//제일 처음 랜덤 테이블을 만든다.
//제일 처음에는 메인에서 이중포인터 변수를 선언하고 함수 안으로 3중포인터로 들어왔으나 뭔가의 오류 때문에 해결이 불가능 했다
//어제 수업시간의 피드백을 듣고 코드를 수정
//*Table = (Ticket_Info **)malloc(row * sizeof(Ticket_Info*));행 메모리 할당
//*Table[i] = (Ticket_Info*)malloc(col * sizeof(Ticket_Info));열 메모리 할당
//Table[i][j]->flag = TRUE;멤버 참조 삼중포인터에서 이중포인터 메모리에 할당된 멤버 참조
Ticket_Info ** make_random_table( int row, int col)
{
	Ticket_Info **Table;
	double royal_row;
	int i, j;


	royal_row = row / (double)3;

	//모든 위치에 메모리 할당을 하지 않고 만들 수 도 있는가?
	Table = (Ticket_Info **)malloc(row * sizeof(Ticket_Info*));//row할당하고 col할당해야하는데 잘못한듯?
																//*Table = (Ticket_Info **)malloc(row * col * sizeof(Ticket_Info*));

	for (i = 0; i < row; i < i++)
	{
		Table[i] = (Ticket_Info*)malloc(col * sizeof(Ticket_Info));
		for (j = 0; j < col; j++)
		{
			if ((i >= (int)royal_row)&&(i < (int)(row - royal_row)))
			{
				//Table[i][j] = (Ticket_Info*)malloc(sizeof(Ticket_Info)); 제일 처음에 한 실수
				Table[i][j].flag = TRUE;//테이블이 배치된 후에는 정보를 판매 가능 상태로 업데이트
				Table[i][j].ticket_rate = 'R';
				Table[i][j].ticket_price = 120000;

			}
			else
			{
				//Table[i][j] = (Ticket_Info*)malloc(sizeof(Ticket_Info));
				Table[i][j].flag = TRUE;//테이블이 배치된 후에는 정보를 판매 가능 상태로 업데이트
				Table[i][j].ticket_rate = 'N';
				Table[i][j].ticket_price = 40000;
			}
		}
	}

	return Table;

}

//판매 유무를 확인해서 OX* 로 표시 상단과 좌측에는 행열 숫자 표시
void show_table(Ticket_Info**Table, int row, int col)
{
	int i, j;

	//상단과 좌측에 행 열 정보를 표시해준다.
	/*
	표시 예
	a는 빈칸
	O일반석(구매가능) *로얄석(구매가능) X매진
	aaa01a02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20
	01aOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaaOaa
	02 
	03 
	04 
	05 
	06 
	07 
	08 
	09 
	10 
	*/
	printf("O일반석(구매가능) *로얄석(구매가능) X매진\n\n");
	for (j = 0; j < col; j++)
	{
		if (j == 0)
			printf("   ");//빈칸 3개 추가

		printf("%2d ", j + 1);
	}
	printf("\n");

	//일단 판매 가능/불가 를 가지고 OX를 가른다
	//그중 R등급의 표는 *로 표시
	//O일반석(구매가능) *로얄석(구매가능) X매진
	for (i = 0; i < row; i < i++)
	{
		printf("%2d ",i + 1);

		for (j = 0; j < col; j++)
		{
			if (Table[i][j].flag == FALSE)//판매 완료
				printf("X  ");
			else//판매 가능
			{
				if (Table[i][j].ticket_rate=='N')//일반
					printf("O  ");
				else//로얄
					printf("*  ");
			}
		}
		printf("\n");
	}

}

//티켓 정보를 출력한다. (예매번호, 예약자 이름, 티켓 등급, 티켓 가격
//https://wepplication.github.io/tools/charMap/ 특수문자

void show_ticket_info(Ticket_Info**Table, int row, int col)
{
	printf("┏━━ 예약정보━━━━━━\n");
	printf("┃예매번호: %s\n",Table[row][col].ticket_num);//예매번호
	printf("┃좌석번호: %d행 %d열\n", row + 1, col + 1);
	printf("┃예약이름: %s\n",Table[row][col].reservation_name);//예약자 이름
	printf("┃티켓등급: %c\n",Table[row][col].ticket_rate);//티켓 등급
	printf("┃티켓가격: %d\n",Table[row][col].ticket_price);//티켓 가격
	printf("┗━━━━━━━━━━━━━━━\n");
}

//함수 내부의 임시 변수에 입력받고 메모리를 리턴//예약 가능한 좌석을 보여주고 이미 예약된 좌석이면 예약이 불가능하게 통상의 예약 과정
//시간 정보 다루기
//https://korbillgates.tistory.com/100

int reservation_ticket(Ticket_Info***Table, int row, int col)
{
	int s_row, s_col;
	int sel = 0;
	Ticket_Info *temp;

	///////////////////////////////////////////////
	int year, month, day, sec;
	unsigned int ticket_num;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	///////////////////////////////////////////////
	temp = (Ticket_Info*)malloc(sizeof(Ticket_Info));//임시 변수에 저장하고 완벽하게 예약 확정이 난 경우에 대입해준다.
	year = (tm.tm_year + 1900)*1000000;
	month = (tm.tm_mon + 1)*10000;
	day = (tm.tm_mday)*100;
	sec = (tm.tm_sec);
	ticket_num = year + month + day + sec;
	itoa(ticket_num, temp->ticket_num, 10);//Table[s_row - 1][s_col - 1]->ticket_num
	///////////////////////////////////////////////

	//https://dojang.io/mod/forum/discuss.php?d=719
	//https://dojang.io/mod/forum/discuss.php?d=699&parent=1577
	show_table(*Table, row, col);//현재 예약 현황을 한번 보여줌

	while (1)
	{
		printf("자리를 선택해주세요.\n");
		scanf("%d %d", &s_row, &s_col);

		temp->ticket_rate	= (*Table)[s_row - 1][s_col - 1].ticket_rate;
		temp->ticket_price	= (*Table)[s_row - 1][s_col - 1].ticket_price;

		//temp->ticket_rate	= (*Table)[s_row - 1][s_col - 1]->ticket_rate;
		//temp->ticket_price = (*Table)[s_row - 1][s_col - 1]->ticket_price;
		
		printf("\n");
		printf("┏━━ 예약정보━━━━━━\n");
		printf("┃좌석위치: %d행 %d열\n",s_row,s_col);
		printf("┃티켓등급: %c\n", temp->ticket_rate);//티켓 등급
		printf("┃티켓가격: %d\n", temp->ticket_price);//티켓 가격
		printf("┗━━━━━━━━━━━━━━━\n");
		printf("위의 정보로 예약하면 되겠습니까?\n");
		printf("1.예 2.아니오 3.이전 메뉴로 돌아가기\n");
		scanf("%d", &sel);

		if (sel == 1)
			break;
		else if (sel == 2)
			;
		else
			break;
	}

	if (sel == 3)
	{
		free(temp);
		return 0;//리턴이 너무 많음
	}

	sel = 0;

	while (1)
	{
		printf("┏━━ 예약자정보입력━━━━━━\n");
		printf("┃이름(최대 11자): ");
		scanf("%s", temp->reservation_name);//Table[s_row - 1][s_col - 1]->reservation_name
		printf("┃패스워드(최대 20자): ");
		scanf("%s", temp->password);//Table[s_row - 1][s_col - 1]->password
		printf("┗━━━━━━━━━━━━━━━━━━━━━\n");
		printf("위의 정보로 예약하면 되겠습니까?\n");
		printf("1.예 2.아니오 3.이전 메뉴로 돌아가기\n");
		scanf("%d", &sel);

		if (sel == 1)
			break;
		else if (sel == 2)
			;
		else
			break;


	}

	if (sel == 3)
	{
		free(temp);
		return 0;
	}
		

	//명확하게 예약을 한다는 뜻이므로
	temp->flag = FALSE;//Table[s_row - 1][s_col - 1]->flag
	temp->enter_info = TRUE;//Table[s_row - 1][s_col - 1]->enter_info

	//temp의 정보를 대입하는 과정
	memcpy((*Table)[s_row - 1][s_col - 1].ticket_num, temp->ticket_num, TICKET_NUM);//예매번호
	memcpy((*Table)[s_row - 1][s_col - 1].reservation_name, temp->reservation_name, NAME_MAX);//예약자 이름
	memcpy((*Table)[s_row - 1][s_col - 1].password, temp->password, PW_MAX);//비밀번호

	printf("┏━━ 예매정보━━━━━━\n");
	printf("┃예매번호: %s\n", (*Table)[s_row - 1][s_col - 1].ticket_num);//예매번호
	printf("┃예약이름: %s\n", (*Table)[s_row - 1][s_col - 1].reservation_name);//예약자 이름
	printf("┃티켓등급: %c\n", (*Table)[s_row - 1][s_col - 1].ticket_rate);//티켓 등급
	printf("┃티켓가격: %d\n", (*Table)[s_row - 1][s_col - 1].ticket_price);//티켓 가격
	printf("┗━━━━━━━━━━━━━━━\n");

	free(temp);
	return 0;
}

//예약번호, 비밀번호를 입력후 입장 가능
void start(Ticket_Info ***Table, int row, int col)
{
	int i, j;
	int enter_row, enter_col;
	int sel;
	char re_num_temp[TICKET_NUM] = { 0 };
	char pw_temp[PW_MAX] = {0};
	char re_num_check=-1, pw_check=-1;//TRUE FALSE
	//먼저 예약번호를 잘 입력해야하는 상황
	

	while (1)//while의 조건이 확실하면  조건으로 명시한다.
	{
		printf("예약번호를 입력해주세요:\n");
		scanf("%s", re_num_temp);
		printf("비밀번호를 입력해주세요:\n");
		scanf("%s", pw_temp);

		//전체 배열을 돌면서 해당 예약번호가 있는지 먼저 찾고
		//같은 예약번호를 발견하면 비밀번호가 맞는지 체크한다.
		for (i = 0; i < row; i < i++)
		{
			for (j = 0; j < col; j++)
			{
				if (strcmp((*Table)[i][j].ticket_num, re_num_temp) == 0)
				{
					re_num_check = TRUE;
					if (strcmp((*Table)[i][j].password, pw_temp) == 0)
					{
						pw_check = TRUE;//TT
						enter_row = i;
						enter_col = j;
						break;
					}
					else
					{
						pw_check = FALSE;//TF
					}
				}
				else
					re_num_check = FALSE;//F*

			}
			if (re_num_check == TRUE&&pw_check == TRUE)
				break;
		}
		//아이디랑 비밀번호중 뭐가 틀렸는지 알려줄 필요가 없다 둘중에 하나가 틀렸으면 그냥 끝나게
		// re_num_check||pw_check
		//            T||T  입장 가능
		//            T||F  비밀번호를 다시 확인해주세요
		//            F||T	예약번호를 확인해주세요
		//            F||F	예약번호를 확인해주세요
		if (re_num_check == TRUE&&pw_check == TRUE)
		{
			printf("입장 가능\n");
			printf("갑사합니다.\n");
			(*Table)[enter_row][enter_col].enter_info = FALSE;
			break;
		}

		if (re_num_check == FALSE)
		{
			printf("예약번호를 확인해주세요.\n");
			printf("1.예약번호 재입력 2.이전 메뉴로 돌아간다.\n");
			scanf("%d", &sel);

			if (sel == 2)
				break;
		}


	}
	

}

//예약번호, 비밀번호를 입력후 퇴장, 퇴장후에는 재입장 및 조회 불가
void end(Ticket_Info***Table, int row, int col)//삼중 포인터일떄는 -> //이중 포인터일떄는 .?
{
	int i, j;
	int exit_row, exit_col;
	int sel;
	char re_num_temp[TICKET_NUM] = { 0 };
	char pw_temp[PW_MAX] = { 0 };
	char re_num_check = -1, pw_check = -1;//TRUE FALSE
										  //먼저 예약번호를 잘 입력해야하는 상황

	//free 하면안되고 그냥 초기 값을 넣어줘야한다

	//조회 알고리즘 만들떄 if else가 있는것은 않좋다 if만
	while (1)
	{
		printf("예약번호를 입력해주세요:\n");
		scanf("%s", re_num_temp);
		printf("비밀번호를 입력해주세요:\n");
		scanf("%s", pw_temp);

		//전체 배열을 돌면서 해당 예약번호가 있는지 먼저 찾고
		//같은 예약번호를 발견하면 비밀번호가 맞는지 체크한다.
		for (i = 0; i < row; i < i++)
		{
			for (j = 0; j < col; j++)
			{
				if (strcmp((*Table)[i][j].ticket_num, re_num_temp) == 0)
				{
					re_num_check = TRUE;
					if (strcmp((*Table)[i][j].password, pw_temp) == 0)
					{
						pw_check = TRUE;//TT
						exit_row = i;
						exit_col = j;
						break;
					}
					else
					{
						pw_check = FALSE;//TF
					}
				}
				else
					re_num_check = FALSE;//F*

			}
			if (re_num_check == TRUE&&pw_check == TRUE)
				break;
		}

		// re_num_check||pw_check
		//            T||T  퇴장 가능
		//            T||F  비밀번호를 다시 확인해주세요
		//            F||T	예약번호를 확인해주세요
		//            F||F	예약번호를 확인해주세요
		if (re_num_check == TRUE&&pw_check == TRUE&&(*Table)[exit_row][exit_col].enter_info == FALSE)
		{
			printf("퇴장 가능\n");
			printf("갑사합니다.\n");
			(*Table)[exit_row][exit_col].flag = FALSE;
			(*Table)[exit_row][exit_col].ticket_num[0] = "\0";
			(*Table)[exit_row][exit_col].reservation_name[0] = "\0";
			(*Table)[exit_row][exit_col].password[0] = "\0";

			break;
		}

		if (re_num_check == FALSE)
		{
			printf("예약번호를 확인해주세요.\n");
			printf("1.예약번호 재입력 2.이전 메뉴로 돌아간다.\n");
			scanf("%d", &sel);

			if (sel == 2)
				break;
		}


	}




}

//1.이름으로 조회하기, 2.예약번호로 조회하기
void check_info(Ticket_Info **Table, int row, int col)
{
	int i, j;
	int re_num_row, re_num_col;
	int sel;
	char re_num_temp[TICKET_NUM] = { 0 };
	char name_temp[NAME_MAX] = { 0 };
	char re_num_check = -1, name_check = -1;//TRUE FALSE
										
	printf("조회 방법을 선택해주세요.\n");
	printf("1.예약번호로 조회 2.이름으로 조회");
	scanf("%d", &sel);

	switch (sel)
	{

	case 1:
		sel = 0;
		while (1)
		{
			printf("예약번호를 입력해주세요:\n");
			scanf("%s", re_num_temp);

			for (i = 0; i < row; i < i++)
			{
				for (j = 0; j < col; j++)
				{
					if (strcmp(Table[i][j].ticket_num, re_num_temp) == 0)
					{
						re_num_check = TRUE;
						re_num_row = i;
						re_num_col = j;
						break;
					}
					else
						re_num_check = FALSE;//F*

				}
				if (re_num_check == TRUE)
					break;
			}

			if (re_num_check == TRUE)
			{
				show_ticket_info(Table, re_num_row, re_num_col);
				break;
			}
			else
			{
				printf("예약번호를 확인해주세요.\n");
				printf("1.예약번호 재입력 2.이전 메뉴로 돌아간다.\n");
				scanf("%d", &sel);

				if (sel == 2)
					break;
			}
		}
		break;

	case 2:
		sel = 0;
		while (1)
		{
			printf("이름 입력해주세요:\n");
			scanf("%s", name_temp);

			//전체 배열을 돌면서 해당 예약번호가 있는지 먼저 찾고
			//같은 예약번호를 발견하면 비밀번호가 맞는지 체크한다.
			for (i = 0; i < row; i < i++)
			{
				for (j = 0; j < col; j++)
				{
					if (strcmp(Table[i][j].reservation_name, name_temp) == 0)
					{
						show_ticket_info(Table,i, j);
					}	
				}
			
			}


			printf("예약번호를 확인해주세요.\n");
			printf("1.다시 검색 2.이전 메뉴로 돌아간다.\n");
			scanf("%d", &sel);

			if (sel == 2)
				break;
		}
		break;
	}
}


void record_table(FILE *fp_w, Ticket_Info ** Table, int row, int col)
{
	int i, j;

	fprintf(fp_w, "%d %d\n", row, col);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fprintf(fp_w, "%d %d %d %d %c %d %s %s %s\n", i,j,Table[i][j].flag, Table[i][j].enter_info, Table[i][j].ticket_rate, Table[i][j].ticket_price, Table[i][j].ticket_num, Table[i][j].reservation_name, Table[i][j].password);// i j flag enter

		}
	}

}
void read_table(FILE * fp_r, Ticket_Info *** Table, int * row, int * col)
{
	int i, j;
	int scan_i, scan_j;
	int scan_row, scan_col;

	//EOF??
	fscanf(fp_r, "%d%d",&scan_row,&scan_col);
	*row = scan_row;
	*col = scan_col;

	for (i = 0; i < scan_row; i++)
	{
		for (j = 0; j < scan_col; j++)
		{
			//문자열은 &를 붙일 필요가 없다.
			fscanf(fp_r, "%d%d%d%d%c%d%s%s%s", &scan_i, &scan_j, &(*Table)[i][j].flag, &(*Table)[i][j].enter_info, &(*Table)[i][j].ticket_rate, &(*Table)[i][j].ticket_price, (*Table)[i][j].ticket_num, (*Table)[i][j].reservation_name, (*Table)[i][j].password);
		}
	}


}



#ifdef GO

void main()
{
	//기존에 생성된 테이블이 있는지 확인
	//있으면 정보를 읽어와서 그 순서로 파일 처리(제일 처음에 필요한 정보 테이블있는지 없는지 확인, 테이블 사이즈)
	//파일의 유무 확인은 파일포인터로 확인 가능! 있다고 하면 읽어오고 없다고 하면 생성
	
	/*파일이 있다고 생각했을때
	제일 첫줄에  쓰여있을 정보는 테이블의 사이즈

	//http://blog.naver.com/PostView.nhn?blogId=sharonichoya&logNo=220502134809
	//https://12bme.tistory.com/214
	//https://araikuma.tistory.com/593
	//https://kldp.org/node/80909
	//파일 입출력에 관해서 참고한 자료
	*/

	/*파일이 없다고 생각했을때
	파일을 생성하고 랜덤으로 테이블을 생성한다
	테이블을 생성하고 거기에 맞춰서 메모리를 할당한다.

	메모리를 할당하고 판매 가능 플래그를 1로 초기화 한다
	*/

	// 
}


while (1)
{
	printf("이름 입력해주세요:\n");
	scanf("%s", name_temp);

	//전체 배열을 돌면서 해당 예약번호가 있는지 먼저 찾고
	//같은 예약번호를 발견하면 비밀번호가 맞는지 체크한다.
	for (i = 0; i < row; i < i++)
	{
		for (j = 0; j < col; j++)
		{
			if (strcmp(Table[i][j].reservation_name, name_temp) == 0)
			{
				name_check = TRUE;
				name_row = i;
				name_col = j;
				break;
			}
			else
				name_check = FALSE;//F*

		}
		if (name_check == TRUE)
			break;
	}

	if (name_check == TRUE)
	{
		show_ticket_info(Table, name_row, name_col);
		break;
	}
	else
	{
		printf("예약번호를 확인해주세요.\n");
		printf("1.예약번호 재입력 2.이전 메뉴로 돌아간다.\n");
		scanf("%d", &sel);

		if (sel == 2)
			break;
	}
}


#endif