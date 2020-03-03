

#ifndef __FUNC_H__
#define __FUNC_H__

#include"Mylibrary.h"
#include"Myheader.h"
//만들어야할 기능 
//랜덤으로 좌석 배치도 만드는 기능
//티켓 사는 기능() 평범한 예약 순서 영화 예매하는것과 같이
//예약 정보 확인 기능
//조회하기(입장정보 확인하는거 암호), 입장하기(), 퇴장하기()

//원래는 함수 기능에 따라서 .h하나 .c하나 만들어준다
//unlink

Ticket_Info** make_random_table(int row, int col);
void show_table(Ticket_Info**Table, int row, int col);//판매 유무를 확인해서 OX 로 표시 상단과 좌측에는 행열 숫자 표시
void show_ticket_info(Ticket_Info**Table, int row, int col);
int reservation_ticket(Ticket_Info***Table, int row, int col);//함수 내부의 임시 변수에 입력받고 메모리를 리턴//예약 가능한 좌석을 보여주고 이미 예약된 좌석이면 예약이 불가능하게 통상의 예약 과정
void start(Ticket_Info ***Table, int row, int col);//예약번호, 비밀번호를 입력후 입장 가능
void check_info(Ticket_Info **Table, int row, int col);//1.이름으로 조회하기, 2.예약번호로 조회하기
void end(Ticket_Info***Table, int row, int col);//예약번호, 비밀번호를 입력후 퇴장, 퇴장후에는 재입장 및 조회 불가
void read_table(FILE *fp_r, Ticket_Info***Table, int* row, int* col);
void record_table(FILE *fp_w ,Ticket_Info**Table, int row, int col);

//%%%%%void형 포인터를 이용해서 함수로 번호도 찾고 이름도 찾게 만들 수 있다.%%%%%%

//파일 읽어오는 함수 만들기
//파일 쓰는 함수 만들기


#endif