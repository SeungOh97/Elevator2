#pragma once
#include <iostream>
#include "Floor.h"
#include <vector>


class Elevator
{
private:
	//사용자로 부터 입력받을 변수
	int num;
	//사용자로 부터 입력받은 방향
	std::string way;
	//사용자 상태
	// 현재 층수
	int m_current_floor = 1;
	// 목표 층수
	int m_current_target = NULL;
	// 현재 엘리베이터 이동 방향
	std::string m_current_way = "up";
	
public:
	std::string user_status;
	// 층 데이터 넣을 벡터 Floor = int,string
	std::vector<Floor> up_floor;
	std::vector<Floor> down_floor;
	// 작동 함수 
	void Act();
	void Status();
};

