#include "Elevator.h"


void Elevator::Act() {
	std::string answer;
	std::cout << "Inside or Outside?";
	std::cin >> answer;
	if (answer == "inside") {
		std::cout << "Floor : ";
		std::cin >> num;
	}
	else if (answer == "outside") {
		std::cout << "Elevator way : ";
		std::cin >> way;
		std::cout << "Floor : ";
		std::cin >> num;
	}
	else if (answer == "stop") {
		user_status = "stop";
		return;
	}
}

void Elevator::Status() {
	std::cout << "Elevator Status" << std::endl;
	std::cout << "Current Floor : " << m_current_floor << std::endl;
	std::cout << "Current Target Floor : " << m_current_target << std::endl;
	std::cout << "Elevator Way : " << m_current_way << std::endl;
}