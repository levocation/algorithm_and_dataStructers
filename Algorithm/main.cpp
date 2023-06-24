#include <iostream>
#include <string>
#include "DynamicArray.h"

int main() {

	DynamicArray<int> arr = DynamicArray<int>(5);

	arr.add(1);
	arr.add(2);
	arr.add(3);
	arr.add(4);
	arr.add(5);
	arr.add(6);

	arr.remove(6);
	arr.remove(5);
	arr.remove(4);

	arr.print();
	std::cout << "\nsize : " << arr.size << "\n";
	std::cout << "capacity : " << arr.capacity << "\n";

	return 0;
}