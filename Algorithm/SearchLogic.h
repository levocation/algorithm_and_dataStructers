#pragma once

template <typename T>
// 순차 탐색 알고리즘
int linearSearch(T arr[], T value) {
	for (int i = 0; i < sizeof(arr) / sizeof(T); i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}

// 이진 탐색 알고리즘
int binarySearch(int arr[], int target) {
	
	int low = 0;
	int high = sizeof(arr) / sizeof(int) - 1;

	while (low <= high)
	{
		int middle = low + (high - low) / 2;
		int value = arr[middle];

		if (value < target) low = middle + 1;
		else if (value > target) high = middle + 1;
		else return middle;
	}

	return -1;
}