#pragma once
#include <vector>
#include <functional>

// C++ STL�� vector�� ����ؼ� ���� Heap �ڷᱸ��

/*
Heap �̶�?
- �켱���� ť�� ���� ������� �ڷᱸ��

- �켱���� ť��?
  = "�켱����"�� ������ ť�� ������ �ڷᱸ��
  = �����͵��� �켱������ ������ �־� �켱������ ���� �����Ͱ� ���� ������.
*/

class Heap {
private:
	std::vector<int> arr;
	int heapSize = 0;
	std::function<bool(int, int)> func;
	// ���� ������ ���� 0�� ������ ��� X

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void reload() {
		// ���� �籸��

		for (int i = 1; i * 2 <= this->heapSize; ) {
			// ���� ��Ʈ ���� ���� �켱������ ���� ���� ���� �����̱� ������ 
			// ���ϴ� ����� �ڽ� ��尡 �������� ������ �񱳸� �����ؾ� �Ѵ�.

			if (i * 2 + 1 > this->heapSize) {
				// ������ �ڽĳ�尡 �������� ���� ���

				if (this->func(this->arr[i], this->arr[i * 2])) {
					// if (this->arr[i] > this->arr[i * 2])
					// ���� ����� �켱������ ���� �ڽĳ���� �켱�������� ���ٸ�
					// ���� ��尡 �̹� ���ĵǾ��ִٴ� ���̹Ƿ�
					// �� �̻� ���� �ʿ䰡 ����.
					break;
				}
				else {
					// �׷��� �ʰ� ���� �ڽĳ���� �켱������ �� ���ٸ�

					swap(this->arr[i], this->arr[i * 2]);
					// �θ� ���� ���� �ڽĳ���� ���� ����

					i = i * 2;
					// ���� �񱳸� ���� ������ �θ� ��带 ���� �ڽĳ��� ����
				}
			}
			else {
				// ������ ��尡 ������ ���

				if (this->func(this->arr[i], this->arr[i * 2]) 
					&& this->func(this->arr[i], this->arr[i * 2 + 1])) {
					// if (this->arr[i] > this->arr[i * 2] && this->arr[i] > this->arr[i * 2 + 1])
					// 
					// ���� ����� �켱������ �ڽĵ��� ����� �켱�������� ���ٸ�
					// ���� ��尡 �̹� ���ĵǾ��ִٴ� ���̹Ƿ�
					// �� �̻� ���� �ʿ䰡 ����.
					break;
				}
				// �׷��� ���� ���, �ڽ� ���� �� �θ� ��庸�� �켱������ ���� ���� �����Ѵٴ� ��
				else if (this->func(this->arr[i * 2], this->arr[i * 2 + 1])) {
					// else if (this->arr[i * 2] > this->arr[i * 2 + 1])
					
					// ���� �ڽĳ���� �켱������ �� ���ٸ�

					swap(this->arr[i], this->arr[i * 2]);
					// �θ� ���� ���� �ڽĳ���� ���� ����

					i = i * 2;
					// ���� �񱳸� ���� ������ �θ� ��带 ���� �ڽĳ��� ����
				}
				else {
					// ������ �ڽĳ���� �켱������ �� ���ٸ�

					swap(this->arr[i], this->arr[i * 2 + 1]);
					// �θ� ���� ������ �ڽĳ���� ���� ����

					i = i * 2 + 1;
					// ���� �񱳸� ���� ������ �θ� ��带 ������ �ڽĳ��� ����
				}
			}
		}
	}

public:
	Heap() {
		arr.emplace_back(0);
		this->func = [](int a, int b) -> bool {
			return a > b;
			// b���� a�� �� �켱������ ���ٸ� true !!
		};
	}
	Heap(std::function<bool(int, int)> func) {
		// �켱������ ������ �Լ��� ���ؼ� ������ �� �ֵ��� ����

		arr.emplace_back(0);
		this->func = func;
	}
	~Heap() {

	}

	// ���� �ڽ� index = (�θ� index) * 2
	// ������ �ڽ� index = (�θ� index) * 2 + 1
	// �θ� index = (�ڽ� index) / 2

	void push(int num) {

		this->arr.emplace_back(num);
		this->heapSize++;

		for (int i = this->heapSize; i > 1; i /= 2) {
			// �� ������ ������
			// ������ ����� �θ� ���,
			// (������ ����� �θ� ���)�� �θ� ���,
			// ...
			// �� ���� ���Ѵ�.
			// 0��° ������ ������� �����Ƿ� 1��° index(�ֻ��� �θ� ���, ��Ʈ ����� ǥ��)���� ��

			if (this->func(this->arr[i], this->arr[i / 2])) {
				// if (this->arr[i] > this->arr[i / 2])
				// ������ ��尡 �ڽ��� �θ� ��庸�� ũ�ٸ� swap

				// �� �κ��� �켱������ �����ϴ� ���� �߿��� �κ��̹Ƿ�
				// �ǻ��ÿ� �켱������ �����ϴ� ������ �� if������ ó���Ѵ�.

				this->swap(this->arr[i / 2], this->arr[i]);
			}
			else {
				// �׷��� �ʴٸ� �� ������ �̹� ������ �Ϸ�Ǿ� �ִ� ���� ���ϹǷ�

				break;
				// for���� Ż��
			}
		}
	}

	int pop() {
		// �� �ڷᱸ������ ������
		// ��Ʈ ���(�켱������ ���� ����)�� ������ ���ϹǷ�
		// ��Ʈ ����� ���� �����ϰ�
		// ������ ��Ʈ ��忡�� ���� ������ ���(�켱������ ���� ����) ��带 ������ ��
		// ���� �籸���Ѵ�.
		if (this->heapSize <= 0) {
			// �� ���ο� �ƹ��͵� �������� ���� ���

			return 0;
			// 0�� ����
		}
		else if (this->heapSize == 1) {
			int root_node = this->arr[1];
			arr.pop_back();
			this->heapSize--;
			return root_node;
		}
		else {
			int root_node = this->arr[1];
			// 0��° ������ ������� �����Ƿ�
			// ��Ʈ ���� 1��° index�� ���

			this->arr[1] = this->arr[this->heapSize];
			// �켱������ ���� ���� ��带
			// �켱������ ���� ���� ��ġ�� ��ġ�Ѵ�.
			this->arr[this->heapSize] = 0;
			// ���� �籸���� ���� �ӽ÷� ������ ����� ���� 0���� �ʱ�ȭ
			this->heapSize--;
			// ���� 0���� �ʱ�ȭ�� ���� ������� ������ ��Ÿ���� ���� heapSize�� 1 ����

			this->reload();
			// ���� �籸��

			this->arr.pop_back();
			// ���� �籸���� ���� ����
			// �� ������ ���� ���� �ʿ䰡 ������ ����


			return root_node;
		}
	}

	int size() {
		return this->heapSize;
	}

	int max() {
		return this->arr[1];
	}
};