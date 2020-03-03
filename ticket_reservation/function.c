#include"All.h"

//���� ó�� ���� ���̺��� �����.
//���� ó������ ���ο��� ���������� ������ �����ϰ� �Լ� ������ 3�������ͷ� �������� ������ ���� ������ �ذ��� �Ұ��� �ߴ�
//���� �����ð��� �ǵ���� ��� �ڵ带 ����
//*Table = (Ticket_Info **)malloc(row * sizeof(Ticket_Info*));�� �޸� �Ҵ�
//*Table[i] = (Ticket_Info*)malloc(col * sizeof(Ticket_Info));�� �޸� �Ҵ�
//Table[i][j]->flag = TRUE;��� ���� ���������Ϳ��� ���������� �޸𸮿� �Ҵ�� ��� ����
Ticket_Info ** make_random_table( int row, int col)
{
	Ticket_Info **Table;
	double royal_row;
	int i, j;


	royal_row = row / (double)3;

	//��� ��ġ�� �޸� �Ҵ��� ���� �ʰ� ���� �� �� �ִ°�?
	Table = (Ticket_Info **)malloc(row * sizeof(Ticket_Info*));//row�Ҵ��ϰ� col�Ҵ��ؾ��ϴµ� �߸��ѵ�?
																//*Table = (Ticket_Info **)malloc(row * col * sizeof(Ticket_Info*));

	for (i = 0; i < row; i < i++)
	{
		Table[i] = (Ticket_Info*)malloc(col * sizeof(Ticket_Info));
		for (j = 0; j < col; j++)
		{
			if ((i >= (int)royal_row)&&(i < (int)(row - royal_row)))
			{
				//Table[i][j] = (Ticket_Info*)malloc(sizeof(Ticket_Info)); ���� ó���� �� �Ǽ�
				Table[i][j].flag = TRUE;//���̺��� ��ġ�� �Ŀ��� ������ �Ǹ� ���� ���·� ������Ʈ
				Table[i][j].ticket_rate = 'R';
				Table[i][j].ticket_price = 120000;

			}
			else
			{
				//Table[i][j] = (Ticket_Info*)malloc(sizeof(Ticket_Info));
				Table[i][j].flag = TRUE;//���̺��� ��ġ�� �Ŀ��� ������ �Ǹ� ���� ���·� ������Ʈ
				Table[i][j].ticket_rate = 'N';
				Table[i][j].ticket_price = 40000;
			}
		}
	}

	return Table;

}

//�Ǹ� ������ Ȯ���ؼ� OX* �� ǥ�� ��ܰ� �������� �࿭ ���� ǥ��
void show_table(Ticket_Info**Table, int row, int col)
{
	int i, j;

	//��ܰ� ������ �� �� ������ ǥ�����ش�.
	/*
	ǥ�� ��
	a�� ��ĭ
	O�Ϲݼ�(���Ű���) *�ξ⼮(���Ű���) X����
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
	printf("O�Ϲݼ�(���Ű���) *�ξ⼮(���Ű���) X����\n\n");
	for (j = 0; j < col; j++)
	{
		if (j == 0)
			printf("   ");//��ĭ 3�� �߰�

		printf("%2d ", j + 1);
	}
	printf("\n");

	//�ϴ� �Ǹ� ����/�Ұ� �� ������ OX�� ������
	//���� R����� ǥ�� *�� ǥ��
	//O�Ϲݼ�(���Ű���) *�ξ⼮(���Ű���) X����
	for (i = 0; i < row; i < i++)
	{
		printf("%2d ",i + 1);

		for (j = 0; j < col; j++)
		{
			if (Table[i][j].flag == FALSE)//�Ǹ� �Ϸ�
				printf("X  ");
			else//�Ǹ� ����
			{
				if (Table[i][j].ticket_rate=='N')//�Ϲ�
					printf("O  ");
				else//�ξ�
					printf("*  ");
			}
		}
		printf("\n");
	}

}

//Ƽ�� ������ ����Ѵ�. (���Ź�ȣ, ������ �̸�, Ƽ�� ���, Ƽ�� ����
//https://wepplication.github.io/tools/charMap/ Ư������

void show_ticket_info(Ticket_Info**Table, int row, int col)
{
	printf("������ ��������������������\n");
	printf("�����Ź�ȣ: %s\n",Table[row][col].ticket_num);//���Ź�ȣ
	printf("���¼���ȣ: %d�� %d��\n", row + 1, col + 1);
	printf("�������̸�: %s\n",Table[row][col].reservation_name);//������ �̸�
	printf("��Ƽ�ϵ��: %c\n",Table[row][col].ticket_rate);//Ƽ�� ���
	printf("��Ƽ�ϰ���: %d\n",Table[row][col].ticket_price);//Ƽ�� ����
	printf("��������������������������������\n");
}

//�Լ� ������ �ӽ� ������ �Է¹ް� �޸𸮸� ����//���� ������ �¼��� �����ְ� �̹� ����� �¼��̸� ������ �Ұ����ϰ� ����� ���� ����
//�ð� ���� �ٷ��
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
	temp = (Ticket_Info*)malloc(sizeof(Ticket_Info));//�ӽ� ������ �����ϰ� �Ϻ��ϰ� ���� Ȯ���� �� ��쿡 �������ش�.
	year = (tm.tm_year + 1900)*1000000;
	month = (tm.tm_mon + 1)*10000;
	day = (tm.tm_mday)*100;
	sec = (tm.tm_sec);
	ticket_num = year + month + day + sec;
	itoa(ticket_num, temp->ticket_num, 10);//Table[s_row - 1][s_col - 1]->ticket_num
	///////////////////////////////////////////////

	//https://dojang.io/mod/forum/discuss.php?d=719
	//https://dojang.io/mod/forum/discuss.php?d=699&parent=1577
	show_table(*Table, row, col);//���� ���� ��Ȳ�� �ѹ� ������

	while (1)
	{
		printf("�ڸ��� �������ּ���.\n");
		scanf("%d %d", &s_row, &s_col);

		temp->ticket_rate	= (*Table)[s_row - 1][s_col - 1].ticket_rate;
		temp->ticket_price	= (*Table)[s_row - 1][s_col - 1].ticket_price;

		//temp->ticket_rate	= (*Table)[s_row - 1][s_col - 1]->ticket_rate;
		//temp->ticket_price = (*Table)[s_row - 1][s_col - 1]->ticket_price;
		
		printf("\n");
		printf("������ ��������������������\n");
		printf("���¼���ġ: %d�� %d��\n",s_row,s_col);
		printf("��Ƽ�ϵ��: %c\n", temp->ticket_rate);//Ƽ�� ���
		printf("��Ƽ�ϰ���: %d\n", temp->ticket_price);//Ƽ�� ����
		printf("��������������������������������\n");
		printf("���� ������ �����ϸ� �ǰڽ��ϱ�?\n");
		printf("1.�� 2.�ƴϿ� 3.���� �޴��� ���ư���\n");
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
		return 0;//������ �ʹ� ����
	}

	sel = 0;

	while (1)
	{
		printf("������ �����������Է¦�����������\n");
		printf("���̸�(�ִ� 11��): ");
		scanf("%s", temp->reservation_name);//Table[s_row - 1][s_col - 1]->reservation_name
		printf("���н�����(�ִ� 20��): ");
		scanf("%s", temp->password);//Table[s_row - 1][s_col - 1]->password
		printf("��������������������������������������������\n");
		printf("���� ������ �����ϸ� �ǰڽ��ϱ�?\n");
		printf("1.�� 2.�ƴϿ� 3.���� �޴��� ���ư���\n");
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
		

	//��Ȯ�ϰ� ������ �Ѵٴ� ���̹Ƿ�
	temp->flag = FALSE;//Table[s_row - 1][s_col - 1]->flag
	temp->enter_info = TRUE;//Table[s_row - 1][s_col - 1]->enter_info

	//temp�� ������ �����ϴ� ����
	memcpy((*Table)[s_row - 1][s_col - 1].ticket_num, temp->ticket_num, TICKET_NUM);//���Ź�ȣ
	memcpy((*Table)[s_row - 1][s_col - 1].reservation_name, temp->reservation_name, NAME_MAX);//������ �̸�
	memcpy((*Table)[s_row - 1][s_col - 1].password, temp->password, PW_MAX);//��й�ȣ

	printf("������ ��������������������\n");
	printf("�����Ź�ȣ: %s\n", (*Table)[s_row - 1][s_col - 1].ticket_num);//���Ź�ȣ
	printf("�������̸�: %s\n", (*Table)[s_row - 1][s_col - 1].reservation_name);//������ �̸�
	printf("��Ƽ�ϵ��: %c\n", (*Table)[s_row - 1][s_col - 1].ticket_rate);//Ƽ�� ���
	printf("��Ƽ�ϰ���: %d\n", (*Table)[s_row - 1][s_col - 1].ticket_price);//Ƽ�� ����
	printf("��������������������������������\n");

	free(temp);
	return 0;
}

//�����ȣ, ��й�ȣ�� �Է��� ���� ����
void start(Ticket_Info ***Table, int row, int col)
{
	int i, j;
	int enter_row, enter_col;
	int sel;
	char re_num_temp[TICKET_NUM] = { 0 };
	char pw_temp[PW_MAX] = {0};
	char re_num_check=-1, pw_check=-1;//TRUE FALSE
	//���� �����ȣ�� �� �Է��ؾ��ϴ� ��Ȳ
	

	while (1)//while�� ������ Ȯ���ϸ�  �������� ����Ѵ�.
	{
		printf("�����ȣ�� �Է����ּ���:\n");
		scanf("%s", re_num_temp);
		printf("��й�ȣ�� �Է����ּ���:\n");
		scanf("%s", pw_temp);

		//��ü �迭�� ���鼭 �ش� �����ȣ�� �ִ��� ���� ã��
		//���� �����ȣ�� �߰��ϸ� ��й�ȣ�� �´��� üũ�Ѵ�.
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
		//���̵�� ��й�ȣ�� ���� Ʋ�ȴ��� �˷��� �ʿ䰡 ���� ���߿� �ϳ��� Ʋ������ �׳� ������
		// re_num_check||pw_check
		//            T||T  ���� ����
		//            T||F  ��й�ȣ�� �ٽ� Ȯ�����ּ���
		//            F||T	�����ȣ�� Ȯ�����ּ���
		//            F||F	�����ȣ�� Ȯ�����ּ���
		if (re_num_check == TRUE&&pw_check == TRUE)
		{
			printf("���� ����\n");
			printf("�����մϴ�.\n");
			(*Table)[enter_row][enter_col].enter_info = FALSE;
			break;
		}

		if (re_num_check == FALSE)
		{
			printf("�����ȣ�� Ȯ�����ּ���.\n");
			printf("1.�����ȣ ���Է� 2.���� �޴��� ���ư���.\n");
			scanf("%d", &sel);

			if (sel == 2)
				break;
		}


	}
	

}

//�����ȣ, ��й�ȣ�� �Է��� ����, �����Ŀ��� ������ �� ��ȸ �Ұ�
void end(Ticket_Info***Table, int row, int col)//���� �������ϋ��� -> //���� �������ϋ��� .?
{
	int i, j;
	int exit_row, exit_col;
	int sel;
	char re_num_temp[TICKET_NUM] = { 0 };
	char pw_temp[PW_MAX] = { 0 };
	char re_num_check = -1, pw_check = -1;//TRUE FALSE
										  //���� �����ȣ�� �� �Է��ؾ��ϴ� ��Ȳ

	//free �ϸ�ȵǰ� �׳� �ʱ� ���� �־�����Ѵ�

	//��ȸ �˰��� ���鋚 if else�� �ִ°��� ������ if��
	while (1)
	{
		printf("�����ȣ�� �Է����ּ���:\n");
		scanf("%s", re_num_temp);
		printf("��й�ȣ�� �Է����ּ���:\n");
		scanf("%s", pw_temp);

		//��ü �迭�� ���鼭 �ش� �����ȣ�� �ִ��� ���� ã��
		//���� �����ȣ�� �߰��ϸ� ��й�ȣ�� �´��� üũ�Ѵ�.
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
		//            T||T  ���� ����
		//            T||F  ��й�ȣ�� �ٽ� Ȯ�����ּ���
		//            F||T	�����ȣ�� Ȯ�����ּ���
		//            F||F	�����ȣ�� Ȯ�����ּ���
		if (re_num_check == TRUE&&pw_check == TRUE&&(*Table)[exit_row][exit_col].enter_info == FALSE)
		{
			printf("���� ����\n");
			printf("�����մϴ�.\n");
			(*Table)[exit_row][exit_col].flag = FALSE;
			(*Table)[exit_row][exit_col].ticket_num[0] = "\0";
			(*Table)[exit_row][exit_col].reservation_name[0] = "\0";
			(*Table)[exit_row][exit_col].password[0] = "\0";

			break;
		}

		if (re_num_check == FALSE)
		{
			printf("�����ȣ�� Ȯ�����ּ���.\n");
			printf("1.�����ȣ ���Է� 2.���� �޴��� ���ư���.\n");
			scanf("%d", &sel);

			if (sel == 2)
				break;
		}


	}




}

//1.�̸����� ��ȸ�ϱ�, 2.�����ȣ�� ��ȸ�ϱ�
void check_info(Ticket_Info **Table, int row, int col)
{
	int i, j;
	int re_num_row, re_num_col;
	int sel;
	char re_num_temp[TICKET_NUM] = { 0 };
	char name_temp[NAME_MAX] = { 0 };
	char re_num_check = -1, name_check = -1;//TRUE FALSE
										
	printf("��ȸ ����� �������ּ���.\n");
	printf("1.�����ȣ�� ��ȸ 2.�̸����� ��ȸ");
	scanf("%d", &sel);

	switch (sel)
	{

	case 1:
		sel = 0;
		while (1)
		{
			printf("�����ȣ�� �Է����ּ���:\n");
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
				printf("�����ȣ�� Ȯ�����ּ���.\n");
				printf("1.�����ȣ ���Է� 2.���� �޴��� ���ư���.\n");
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
			printf("�̸� �Է����ּ���:\n");
			scanf("%s", name_temp);

			//��ü �迭�� ���鼭 �ش� �����ȣ�� �ִ��� ���� ã��
			//���� �����ȣ�� �߰��ϸ� ��й�ȣ�� �´��� üũ�Ѵ�.
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


			printf("�����ȣ�� Ȯ�����ּ���.\n");
			printf("1.�ٽ� �˻� 2.���� �޴��� ���ư���.\n");
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
			//���ڿ��� &�� ���� �ʿ䰡 ����.
			fscanf(fp_r, "%d%d%d%d%c%d%s%s%s", &scan_i, &scan_j, &(*Table)[i][j].flag, &(*Table)[i][j].enter_info, &(*Table)[i][j].ticket_rate, &(*Table)[i][j].ticket_price, (*Table)[i][j].ticket_num, (*Table)[i][j].reservation_name, (*Table)[i][j].password);
		}
	}


}



#ifdef GO

void main()
{
	//������ ������ ���̺��� �ִ��� Ȯ��
	//������ ������ �о�ͼ� �� ������ ���� ó��(���� ó���� �ʿ��� ���� ���̺��ִ��� ������ Ȯ��, ���̺� ������)
	//������ ���� Ȯ���� ���������ͷ� Ȯ�� ����! �ִٰ� �ϸ� �о���� ���ٰ� �ϸ� ����
	
	/*������ �ִٰ� ����������
	���� ù�ٿ�  �������� ������ ���̺��� ������

	//http://blog.naver.com/PostView.nhn?blogId=sharonichoya&logNo=220502134809
	//https://12bme.tistory.com/214
	//https://araikuma.tistory.com/593
	//https://kldp.org/node/80909
	//���� ����¿� ���ؼ� ������ �ڷ�
	*/

	/*������ ���ٰ� ����������
	������ �����ϰ� �������� ���̺��� �����Ѵ�
	���̺��� �����ϰ� �ű⿡ ���缭 �޸𸮸� �Ҵ��Ѵ�.

	�޸𸮸� �Ҵ��ϰ� �Ǹ� ���� �÷��׸� 1�� �ʱ�ȭ �Ѵ�
	*/

	// 
}


while (1)
{
	printf("�̸� �Է����ּ���:\n");
	scanf("%s", name_temp);

	//��ü �迭�� ���鼭 �ش� �����ȣ�� �ִ��� ���� ã��
	//���� �����ȣ�� �߰��ϸ� ��й�ȣ�� �´��� üũ�Ѵ�.
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
		printf("�����ȣ�� Ȯ�����ּ���.\n");
		printf("1.�����ȣ ���Է� 2.���� �޴��� ���ư���.\n");
		scanf("%d", &sel);

		if (sel == 2)
			break;
	}
}


#endif