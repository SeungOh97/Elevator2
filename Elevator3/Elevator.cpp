#include "Elevator.h"
#include <Windows.h>
#include <conio.h>
#include <exception>

void Elevator::Act() {
	//std::string answer;
	user_input ui;

	std::cout << "Inside or Outside?";
	std::cin >> ui.answer;

	//사용자 입력 처리.
	if (ui.answer == "inside") {
		std::cout << "Floor : ";
		std::cin >> ui.num;
	}
	else if (ui.answer == "outside") {
		std::cout << "Elevator way : ";
		std::cin >> ui.way;
		std::cout << "Current_Floor : ";
		std::cin >> ui.num;
	}
	else if (ui.answer == "stop") {
		user_status = "stop";
		return;
	}

	if (!ui.valid_check()) {
		std::cout << "invalid input!"<< std::endl;
		return;
	}

	order.push_back(ui.answer);
	num = ui.num;
	way = ui.way;
	Process();
}
//엘리베이트 상태 표시 
void Elevator::Status() {
	std::cout << "----------------------------" << step << "---------------------------------" << std::endl;
	std::cout << "Elevator Status" << std::endl;
	std::cout << "Current Floor : " << m_current_floor << std::endl;
	std::cout << "Current Target Floor : " << m_current_target << std::endl;
	std::cout << "Elevator Way : " << m_current_way << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	step += 1;
	Sleep(2000);
}
//입력 받은 데이터 처리
void Elevator::Process() {
	if (way == "up") {
		ele_floor.push_back(Floor(num, way));
	}
	else if (way == "down") {
		ele_floor.push_back(Floor(num, way));
	}
	else {
		// 잘못된 방향입니다!
		throw std::invalid_argument("invalid direction");
	}
}
//입력 받은 데이터 저장 벡터 정리 
void Elevator::Process2() {
	for (int i = 1; i < ele_floor.size(); i++) {
		


		//현재 데이터와 이전 데이터의 이동 방향이 같고 두 데이터가 내부에서 입력한 데이터 일 경우.
		//엘리베이터 이동 방향이 올라가는 방향일때
		if (ele_floor[i].m_way == ele_floor[i - 1].m_way and order[i - 1] != "outside" and ele_floor[i].m_way == "up") {
			if (ele_floor[i].m_floor < ele_floor[i - 1].m_floor) {
				int swap;
				swap = ele_floor[i].m_floor;
				ele_floor[i].m_floor = ele_floor[i - 1].m_floor;
				ele_floor[i - 1].m_floor = swap;
			}
		}
		//현재 데이터와 이전 데이터의 이동 방향이 같고 두 데이터가 내부에서 입력한 데이터 일 경우.
		//엘리베이터 이동 방향이 내려가는 방향일때
		else if (ele_floor[i].m_way == ele_floor[i - 1].m_way and order[i - 1] != "outside" and ele_floor[i].m_way == "down") {
			if (ele_floor[i].m_floor > ele_floor[i - 1].m_floor) {
				int swap;
				swap = ele_floor[i].m_floor;
				ele_floor[i].m_floor = ele_floor[i - 1].m_floor;
				ele_floor[i - 1].m_floor = swap;
			}
		}

	}
}
//엘리베이터 작동
void Elevator::do2() {
	m_current_target = ele_floor.front().m_floor;
	m_current_way = ele_floor.front().m_way;
	std::string m_order = order.front();
	if (m_order == "outside") {
		order_process();
	}
	else if (m_order == "inside") {
		if (m_current_way == "up") {
			up_process();
		}
		else if (m_current_way == "down") {
			down_process();
		}
	}
	
	order.erase(order.begin());
	ele_floor.erase(ele_floor.begin());
}
//엘리베이터 내려가는 기능 
void Elevator::down_process() {
	while (m_current_target != m_current_floor) {
		m_current_floor -= 1;
		Status();
	}
}
//엘리베이터 올라가는 기능 
void Elevator::up_process() {
	while (m_current_target != m_current_floor) {
		m_current_floor += 1;
		Status();
	}
}
//외부에서 엘리베이터 호출시.
void Elevator::order_process() {
	//엘리베이터를 자신쪽으로 호출 그래서 m_current_floor 는 엘리베이터 위치로 가정, m_current_target은 현재 본인의 위치로 가정.
	if (m_current_target != m_current_floor) {
		if (m_current_way == "up" and m_current_floor < m_current_target) {
			up_process();
		}
		else if (m_current_way == "up" and m_current_floor > m_current_target) {
			down_process();
		}
		else if (m_current_way == "down" and m_current_floor < m_current_target) {
			up_process();
		}
		else if (m_current_way == "down" and m_current_floor > m_current_target) {
			down_process();
		}
	}
	else {

	}
}

// 유효성 검사입니다.
bool user_input::valid_check()
{
	if (way == "up" || way == "down") return false;
	if (num == 0) return false;
	if (answer == "inside" || answer == "outside") return false;

	return true;
}
