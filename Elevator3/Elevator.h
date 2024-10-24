#pragma once
#include <iostream>
#include "Floor.h"
#include <vector>


class Elevator
{
private:
	//����ڷ� ���� �Է¹��� ����
	int num;
	//����ڷ� ���� �Է¹��� ����
	std::string way;
	//����� ����
	// ���� ����
	int m_current_floor = 1;
	// ��ǥ ����
	int m_current_target = NULL;
	// ���� ���������� �̵� ����
	std::string m_current_way = "up";
	
public:
	std::string user_status;
	// �� ������ ���� ���� Floor = int,string
	std::vector<Floor> up_floor;
	std::vector<Floor> down_floor;
	// �۵� �Լ� 
	void Act();
	void Status();
};

