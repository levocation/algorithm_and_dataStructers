#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;

bool func(int a, int b) {
	return a < b;
}

int main() {
	// �ڷᱸ�� �Ǵ� �˰����� �׽�Ʈ�ϴ� ����

	Heap test_heap = Heap(func);

	test_heap.push(1);
	test_heap.push(2);
	test_heap.push(3);
	test_heap.push(5);
	test_heap.push(6);
	test_heap.push(7);
	test_heap.push(4);

	for (int i = 0; i < test_heap.size();) {
		printf("%dȸ��\n", i + 1);
		printf("���� �켱������ ���� �� : %d\n", test_heap.max());
		printf("ũ�� : %d\n", test_heap.size());
		test_heap.pop();
		printf("---------------\n");
	}

	return 0;
}