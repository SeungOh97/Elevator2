#pragma once
#include <iostream>
#include "Floor.h"
#include <vector>
#include <chrono>
class user_input {
public:
	int num;
	std::string way;
	std::string answer;

public:
	bool valid_check();
};
class Elevator
{
private:
	//사용자로 부터 입력받을 변수
	int num;
	//사용자로 부터 입력받은 방향
	std::string way;
	// 현재 층수
	int m_current_floor = 1;
	// 목표 층수
	int m_current_target = NULL;
	// 현재 엘리베이터 이동 방향
	std::string m_current_way = "up";
	//처리 횟수
	int step = 1;
	
public:
	//while문 탈출을 위한 변수 
	std::string user_status;
	// 층 데이터 넣을 벡터 Floor = int,string
	//ele_floor - 사용자 입력 데이터 저장
	std::vector<Floor> ele_floor;
	//order - 외부 내부 구분용 벡터
	std::vector<std::string> order;
	// 작동 함수 
	void Act();
	void Status();
	void Process();
	void Process2();
	void do2();
	void down_process();
	void up_process();
	void order_process();
};

