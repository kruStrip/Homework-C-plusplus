#include <iostream>
#include <vector>
#include<string>
#include <tuple>

int main() {
	setlocale(LC_ALL, "");
	std::vector<std::tuple<std::string, int>> colors = { {"RED", 91 }, { "GREEN", 92 }, {"YELLOW" ,93}, {"BLUE" ,96}, {"PURPLE",95},  {"ORANGE", 33},  {"CYAN", 94,} };

	for (int i = 0; i < colors.size(); i++) {
		std::cout << "\033[" << std::get<1>(colors[i]) << "m" << std::get<0>(colors[i]) << "\033[0m" << std::endl;

	}
}
