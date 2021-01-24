#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

float toFind = 0;

bool magg(float x){
	return x > toFind;
}


int main(int argc, char** argv) {
	std::vector<float> vet;
	
	int temp;
	std::cout << "Inserire numero: (ctrl+z per concludere): ";
	while (std::cin >> temp) {
		vet.push_back(temp);
		std::cout << "Inserire numero: (ctrl+z per concludere): ";
	}
	std::cin.clear();
	
	std::cout << "Inserire numero da confrontare: "; std::cin >> toFind;
	
	
	std::vector<float>::iterator found = std::find_if(vet.begin(), vet.end(), magg);
	
	for(; found != vet.end(); found++) std::cout << *found << std::endl;
	
	
	
	return 0;
}
