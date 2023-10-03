#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;

bool func(int a, int b) {
	return a < b;
}

int main() {
	// 자료구조 또는 알고리즘을 테스트하는 공간

	Heap test_heap = Heap(func);

	test_heap.push(1);
	test_heap.push(2);
	test_heap.push(3);
	test_heap.push(5);
	test_heap.push(6);
	test_heap.push(7);
	test_heap.push(4);

	for (int i = 0; i < test_heap.size();) {
		printf("%d회전\n", i + 1);
		printf("가장 우선순위가 높은 값 : %d\n", test_heap.max());
		printf("크기 : %d\n", test_heap.size());
		test_heap.pop();
		printf("---------------\n");
	}

	return 0;
}