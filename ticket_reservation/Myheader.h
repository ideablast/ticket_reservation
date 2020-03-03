#ifndef __MYHEADER_H__
#define __MYHEADER_H__
#include"Mylibrary.h"

#define TRUE 1
#define FALSE 0

#define TICKET_NUM 11
#define PW_MAX 21
#define NAME_MAX 11



//typedef로 별명을 붙이는데 구조체  2차원 배열
//티켓 번호는 연,월,일,시로 이루어진 열자리 숫자로 한다
//몇행 몇열 5이상 10이하 행, 10이상 20이하 열 
//예약자 비밀번호도 구조체에 들어가있어야함
//파일 처리를 해야함
//제일 처음 구매, 2번 예약정보 확인하는 기능
//

typedef struct {
	char flag;//TRUE 판매 가능 FALSE 판매 불가   //배열 생성할때 초기화     
	char enter_info;//TRUE 입장 가능 FALSE 입장 불가 //티켓 구매시 초기화
	char ticket_rate;//R인지 N인지 배치도를 3등분 해서 중간 지점을 R존으로 한다 //배열 생성할때 초기화 //티켓 정보 표기 시 보여줄 정보
	unsigned int ticket_price;//R존 12만원, N존 4만원 //배열 생성할때 초기화 //티켓 정보 표기 시 보여줄 정보
	char ticket_num[TICKET_NUM];//년,월,일,시,분,초 예)20200130131332 //티켓 구매시 초기화 //티켓 정보 표기 시 보여줄 정보
	char reservation_name[NAME_MAX]; //티켓 구매시 초기화 //티켓 정보 표기 시 보여줄 정보
	char password[PW_MAX]; //티켓 구매시 초기화

}Ticket_Info;


#endif