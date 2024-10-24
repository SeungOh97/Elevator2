#pragma once
#include <iostream>
//층수 데이터를 담기위한 클래스 
class Floor
{
public:
	int m_floor;
	std::string m_way;
	//기본 생성자
	Floor(int floor,std::string way);
};

