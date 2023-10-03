#pragma once
#include <vector>
#include <functional>

// C++ STL인 vector를 사용해서 만든 Heap 자료구조

/*
Heap 이란?
- 우선순위 큐를 위해 만들어진 자료구조

- 우선순위 큐란?
  = "우선순위"의 개념을 큐에 도입한 자료구조
  = 데이터들이 우선순위를 가지고 있어 우선순위가 높은 데이터가 먼저 나간다.
*/

class Heap {
private:
	std::vector<int> arr;
	int heapSize = 0;
	std::function<bool(int, int)> func;
	// 쉬운 구현을 위해 0번 공간은 사용 X

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void reload() {
		// 힙의 재구성

		for (int i = 1; i * 2 <= this->heapSize; ) {
			// 현재 루트 노드는 가장 우선순위가 가장 낮은 값인 상태이기 때문에 
			// 비교하는 노드의 자식 노드가 존재하지 않으면 비교를 중지해야 한다.

			if (i * 2 + 1 > this->heapSize) {
				// 오른쪽 자식노드가 존재하지 않을 경우

				if (this->func(this->arr[i], this->arr[i * 2])) {
					// if (this->arr[i] > this->arr[i * 2])
					// 현재 노드의 우선순위가 왼쪽 자식노드의 우선순위보다 높다면
					// 이하 노드가 이미 정렬되어있다는 뜻이므로
					// 더 이상 비교할 필요가 없다.
					break;
				}
				else {
					// 그렇지 않고 왼쪽 자식노드의 우선순위가 더 높다면

					swap(this->arr[i], this->arr[i * 2]);
					// 부모 노드와 왼쪽 자식노드의 값을 변경

					i = i * 2;
					// 다음 비교를 위해 설정할 부모 노드를 왼쪽 자식노드로 설정
				}
			}
			else {
				// 오른쪽 노드가 존재할 경우

				if (this->func(this->arr[i], this->arr[i * 2]) 
					&& this->func(this->arr[i], this->arr[i * 2 + 1])) {
					// if (this->arr[i] > this->arr[i * 2] && this->arr[i] > this->arr[i * 2 + 1])
					// 
					// 현재 노드의 우선순위가 자식들의 노드의 우선순위보다 높다면
					// 이하 노드가 이미 정렬되어있다는 뜻이므로
					// 더 이상 비교할 필요가 없다.
					break;
				}
				// 그렇지 않은 경우, 자식 노드들 중 부모 노드보다 우선순위가 높은 값이 존재한다는 것
				else if (this->func(this->arr[i * 2], this->arr[i * 2 + 1])) {
					// else if (this->arr[i * 2] > this->arr[i * 2 + 1])
					
					// 왼쪽 자식노드의 우선순위가 더 높다면

					swap(this->arr[i], this->arr[i * 2]);
					// 부모 노드와 왼쪽 자식노드의 값을 변경

					i = i * 2;
					// 다음 비교를 위해 설정할 부모 노드를 왼쪽 자식노드로 설정
				}
				else {
					// 오른쪽 자식노드의 우선순위가 더 높다면

					swap(this->arr[i], this->arr[i * 2 + 1]);
					// 부모 노드와 오른쪽 자식노드의 값을 변경

					i = i * 2 + 1;
					// 다음 비교를 위해 설정할 부모 노드를 오른쪽 자식노드로 설정
				}
			}
		}
	}

public:
	Heap() {
		arr.emplace_back(0);
		this->func = [](int a, int b) -> bool {
			return a > b;
			// b보다 a가 더 우선순위가 높다면 true !!
		};
	}
	Heap(std::function<bool(int, int)> func) {
		// 우선순위의 기준을 함수를 통해서 정의할 수 있도록 설정

		arr.emplace_back(0);
		this->func = func;
	}
	~Heap() {

	}

	// 왼쪽 자식 index = (부모 index) * 2
	// 오른쪽 자식 index = (부모 index) * 2 + 1
	// 부모 index = (자식 index) / 2

	void push(int num) {

		this->arr.emplace_back(num);
		this->heapSize++;

		for (int i = this->heapSize; i > 1; i /= 2) {
			// 맨 마지막 노드부터
			// 마지막 노드의 부모 노드,
			// (마지막 노드의 부모 노드)의 부모 노드,
			// ...
			// 을 전부 비교한다.
			// 0번째 공간은 사용하지 않으므로 1번째 index(최상위 부모 노드, 루트 노드라고 표현)까지 비교

			if (this->func(this->arr[i], this->arr[i / 2])) {
				// if (this->arr[i] > this->arr[i / 2])
				// 마지막 노드가 자신의 부모 노드보다 크다면 swap

				// 이 부분이 우선순위를 결정하는 가장 중요한 부분이므로
				// 실사용시에 우선순위를 결정하는 기준은 이 if문에서 처리한다.

				this->swap(this->arr[i / 2], this->arr[i]);
			}
			else {
				// 그렇지 않다면 윗 노드들은 이미 정렬이 완료되어 있는 것을 뜻하므로

				break;
				// for문을 탈출
			}
		}
	}

	int pop() {
		// 힙 자료구조에서 삭제는
		// 루트 노드(우선순위가 제일 높은)의 삭제를 뜻하므로
		// 루트 노드의 값을 리턴하고
		// 삭제할 루트 노드에는 힙의 마지막 노드(우선순위가 제일 낮은) 노드를 가져온 뒤
		// 힙을 재구성한다.
		if (this->heapSize <= 0) {
			// 힙 내부에 아무것도 존재하지 않을 경우

			return 0;
			// 0을 리턴
		}
		else if (this->heapSize == 1) {
			int root_node = this->arr[1];
			arr.pop_back();
			this->heapSize--;
			return root_node;
		}
		else {
			int root_node = this->arr[1];
			// 0번째 공간은 사용하지 않으므로
			// 루트 노드는 1번째 index의 노드

			this->arr[1] = this->arr[this->heapSize];
			// 우선순위가 가장 낮은 노드를
			// 우선순위가 가장 높은 위치에 배치한다.
			this->arr[this->heapSize] = 0;
			// 힙의 재구성을 위해 임시로 마지막 노드의 값을 0으로 초기화
			this->heapSize--;
			// 값이 0으로 초기화된 노드는 사용하지 않음을 나타내기 위해 heapSize를 1 감소

			this->reload();
			// 힙의 재구성

			this->arr.pop_back();
			// 힙의 재구성이 끝난 시점
			// 맨 마지막 노드는 이제 필요가 없으니 삭제


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