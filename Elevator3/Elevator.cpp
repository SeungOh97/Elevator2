#include "Elevator.h"
#include <Windows.h>
#include <conio.h>
#include <exception>

void Elevator::Act() {
	//std::string answer;
	user_input ui;

	std::cout << "Inside or Outside?";
	std::cin >> ui.answer;

	//����� �Է� ó��.
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
//��������Ʈ ���� ǥ�� 
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
//�Է� ���� ������ ó��
void Elevator::Process() {
	if (way == "up") {
		ele_floor.push_back(Floor(num, way));
	}
	else if (way == "down") {
		ele_floor.push_back(Floor(num, way));
	}
	else {
		// �߸��� �����Դϴ�!
		throw std::invalid_argument("invalid direction");
	}
}
//�Է� ���� ������ ���� ���� ���� 
void Elevator::Process2() {
	for (int i = 1; i < ele_floor.size(); i++) {
		


		//���� �����Ϳ� ���� �������� �̵� ������ ���� �� �����Ͱ� ���ο��� �Է��� ������ �� ���.
		//���������� �̵� ������ �ö󰡴� �����϶�
		if (ele_floor[i].m_way == ele_floor[i - 1].m_way and order[i - 1] != "outside" and ele_floor[i].m_way == "up") {
			if (ele_floor[i].m_floor < ele_floor[i - 1].m_floor) {
				int swap;
				swap = ele_floor[i].m_floor;
				ele_floor[i].m_floor = ele_floor[i - 1].m_floor;
				ele_floor[i - 1].m_floor = swap;
			}
		}
		//���� �����Ϳ� ���� �������� �̵� ������ ���� �� �����Ͱ� ���ο��� �Է��� ������ �� ���.
		//���������� �̵� ������ �������� �����϶�
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
//���������� �۵�
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
//���������� �������� ��� 
void Elevator::down_process() {
	while (m_current_target != m_current_floor) {
		m_current_floor -= 1;
		Status();
	}
}
//���������� �ö󰡴� ��� 
void Elevator::up_process() {
	while (m_current_target != m_current_floor) {
		m_current_floor += 1;
		Status();
	}
}
//�ܺο��� ���������� ȣ���.
void Elevator::order_process() {
	//���������͸� �ڽ������� ȣ�� �׷��� m_current_floor �� ���������� ��ġ�� ����, m_current_target�� ���� ������ ��ġ�� ����.
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

// ��ȿ�� �˻��Դϴ�.
bool user_input::valid_check()
{
	if (way == "up" || way == "down") return false;
	if (num == 0) return false;
	if (answer == "inside" || answer == "outside") return false;

	return true;
}
