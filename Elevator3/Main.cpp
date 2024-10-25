#include "Main.h"
#include "Elevator.h"
int main() {
	Elevator m_elevator;
	//사용자 입력
	while (true) {
		
		m_elevator.Act();
		if (m_elevator.user_status == "stop") {
			break;
		}
		
	}
	m_elevator.Process2();
	// 사용자 입력 처리
	while (m_elevator.ele_floor.size() != 0) {
		m_elevator.do2();
	}
	return 0;
}