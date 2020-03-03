

#ifndef __FUNC_H__
#define __FUNC_H__

#include"Mylibrary.h"
#include"Myheader.h"
//�������� ��� 
//�������� �¼� ��ġ�� ����� ���
//Ƽ�� ��� ���() ����� ���� ���� ��ȭ �����ϴ°Ͱ� ����
//���� ���� Ȯ�� ���
//��ȸ�ϱ�(�������� Ȯ���ϴ°� ��ȣ), �����ϱ�(), �����ϱ�()

//������ �Լ� ��ɿ� ���� .h�ϳ� .c�ϳ� ������ش�
//unlink

Ticket_Info** make_random_table(int row, int col);
void show_table(Ticket_Info**Table, int row, int col);//�Ǹ� ������ Ȯ���ؼ� OX �� ǥ�� ��ܰ� �������� �࿭ ���� ǥ��
void show_ticket_info(Ticket_Info**Table, int row, int col);
int reservation_ticket(Ticket_Info***Table, int row, int col);//�Լ� ������ �ӽ� ������ �Է¹ް� �޸𸮸� ����//���� ������ �¼��� �����ְ� �̹� ����� �¼��̸� ������ �Ұ����ϰ� ����� ���� ����
void start(Ticket_Info ***Table, int row, int col);//�����ȣ, ��й�ȣ�� �Է��� ���� ����
void check_info(Ticket_Info **Table, int row, int col);//1.�̸����� ��ȸ�ϱ�, 2.�����ȣ�� ��ȸ�ϱ�
void end(Ticket_Info***Table, int row, int col);//�����ȣ, ��й�ȣ�� �Է��� ����, �����Ŀ��� ������ �� ��ȸ �Ұ�
void read_table(FILE *fp_r, Ticket_Info***Table, int* row, int* col);
void record_table(FILE *fp_w ,Ticket_Info**Table, int row, int col);

//%%%%%void�� �����͸� �̿��ؼ� �Լ��� ��ȣ�� ã�� �̸��� ã�� ���� �� �ִ�.%%%%%%

//���� �о���� �Լ� �����
//���� ���� �Լ� �����


#endif