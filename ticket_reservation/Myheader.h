#ifndef __MYHEADER_H__
#define __MYHEADER_H__
#include"Mylibrary.h"

#define TRUE 1
#define FALSE 0

#define TICKET_NUM 11
#define PW_MAX 21
#define NAME_MAX 11



//typedef�� ������ ���̴µ� ����ü  2���� �迭
//Ƽ�� ��ȣ�� ��,��,��,�÷� �̷���� ���ڸ� ���ڷ� �Ѵ�
//���� � 5�̻� 10���� ��, 10�̻� 20���� �� 
//������ ��й�ȣ�� ����ü�� ���־����
//���� ó���� �ؾ���
//���� ó�� ����, 2�� �������� Ȯ���ϴ� ���
//

typedef struct {
	char flag;//TRUE �Ǹ� ���� FALSE �Ǹ� �Ұ�   //�迭 �����Ҷ� �ʱ�ȭ     
	char enter_info;//TRUE ���� ���� FALSE ���� �Ұ� //Ƽ�� ���Ž� �ʱ�ȭ
	char ticket_rate;//R���� N���� ��ġ���� 3��� �ؼ� �߰� ������ R������ �Ѵ� //�迭 �����Ҷ� �ʱ�ȭ //Ƽ�� ���� ǥ�� �� ������ ����
	unsigned int ticket_price;//R�� 12����, N�� 4���� //�迭 �����Ҷ� �ʱ�ȭ //Ƽ�� ���� ǥ�� �� ������ ����
	char ticket_num[TICKET_NUM];//��,��,��,��,��,�� ��)20200130131332 //Ƽ�� ���Ž� �ʱ�ȭ //Ƽ�� ���� ǥ�� �� ������ ����
	char reservation_name[NAME_MAX]; //Ƽ�� ���Ž� �ʱ�ȭ //Ƽ�� ���� ǥ�� �� ������ ����
	char password[PW_MAX]; //Ƽ�� ���Ž� �ʱ�ȭ

}Ticket_Info;


#endif