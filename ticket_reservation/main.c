//typedef�� ������ ���̴µ� ����ü ticket ��ȣ,�ð���, ������ ��, �ݾ�, �¼�����(R, �Ϲ�) 2���� �迭 
//���� � 5�̻� 10���� ��, 10�̻� 20���� �� 
//������ ��й�ȣ�� ����ü�� ���־����
//���� ó���� �ؾ���
//���� ó�� ����, 2�� �������� Ȯ���ϴ� ���

//���Ͽ� �а� �� ������ ������ ���𰡸� �Ѵٰ� �����ϴ°� ���ϴ�.

#include"All.h"


int main()
{
	FILE *fp_r,*fp_w;
	char file_flag = FALSE;//������ ���� �ʱ� ���� F, ������ �����ϸ� T
	Ticket_Info**Table;
	int row, col;
	int sel;

	fp_r = fopen("C:\\Users\\songd\\temporary_visual_file_IO\\ticket_list.txt", "rt");//������ �������� �ݰԵǸ� ������ �����

	if (fp_r == NULL)
	{
		fp_w = fopen("C:\\Users\\songd\\temporary_visual_file_IO\\ticket_list.txt","wt");
		if (fp_w == NULL)
		{
			printf("���� ���濡 ���� �߽��ϴ�\n");
			return 0;
		}
	}
	else
		file_flag = TRUE;

	if (file_flag == FALSE)
	{
		srand((unsigned int)time(NULL));
		//������ ��� ó�� �������� ���
		row = (rand() % 6) + 5;//5~10��
		col = (rand() % 11) + 10;//10~20��

		Table = make_random_table(row, col);
	}
	else
		read_table(fp_r, &Table, &row, &col);

	while (1)
	{
		printf("���� �ý���\n");
		printf("1. �����ϱ�\n");
		printf("2. ��ȸ�ϱ�\n");
		printf("3. �����ϱ�\n");
		printf("4. �����ϱ�\n");
		printf("5. �����ϱ�\n");
		printf("�޴��� �����ϼ���:\n");
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
					printf("���� ���濡 ���� �߽��ϴ�\n");
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