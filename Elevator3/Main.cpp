#include "Main.h"
#include "Elevator.h"
int main() {
	Elevator m_elevator;
	//����� �Է�
	while (true) {
		
		m_elevator.Act();
		if (m_elevator.user_status == "stop") {
			break;
		}
		
	}
	m_elevator.Process2();
	// ����� �Է� ó��
	while (m_elevator.ele_floor.size() != 0) {
		m_elevator.do2();
	}
	return 0;
}