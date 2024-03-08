// Program to check the existence of a polygon using the triangle inequality

#include <iostream>
#include <vector>

// Function for entering the number of sides and side lengths
void input(std::vector<double> sides) {
	float side, data;

	do {
		std::cout << "Input the number of sides that are more than three: ";
		std::cin >> side;
	} while (side < 3);

	std::cout << "Input please side length: ";
	while (side > 0 && std::cin >> data) {
		sides.push_back(data);
		side--;
	}
}

// Output processing function
std::string processing(std::vector<double> sides) {
	unsigned int i = 0, j = 0, stop = sides.size() - 1, sum = 0;

	while (i++ < sides.size()) {
		while (j < sides.size()) {
			if (j != stop) {
				sum += sides[j];
			}
			j++;
		}
		j = 0;

		if (sum > sides[stop] ? true : false) {
			sum = 0;
			stop -= 1;
		}
		else {
			return "Impossible";
		}
	}

	return "Possible";
}

int main() {
	std::vector<double> sides;

	input(sides);
	auto st = processing(sides);

	std::cout << st << std::endl;
	return 0;
}