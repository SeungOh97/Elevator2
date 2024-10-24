#include "Main.h"
#include "Elevator.h"
int main() {
	Elevator m_elevator;
	while (true) {
		m_elevator.Status();
		m_elevator.Act();
		if (m_elevator.user_status == "stop") {
			exit(0);
		}
	}
	return 0;
}