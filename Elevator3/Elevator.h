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
	//����ڷ� ���� �Է¹��� ����
	int num;
	//����ڷ� ���� �Է¹��� ����
	std::string way;
	// ���� ����
	int m_current_floor = 1;
	// ��ǥ ����
	int m_current_target = NULL;
	// ���� ���������� �̵� ����
	std::string m_current_way = "up";
	//ó�� Ƚ��
	int step = 1;
	
public:
	//while�� Ż���� ���� ���� 
	std::string user_status;
	// �� ������ ���� ���� Floor = int,string
	//ele_floor - ����� �Է� ������ ����
	std::vector<Floor> ele_floor;
	//order - �ܺ� ���� ���п� ����
	std::vector<std::string> order;
	// �۵� �Լ� 
	void Act();
	void Status();
	void Process();
	void Process2();
	void do2();
	void down_process();
	void up_process();
	void order_process();
};

