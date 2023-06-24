#pragma once
#include <iostream>
#include <string>

template<typename T>
class DynamicArray {
public:
	int size = 0;
	int capacity = 10;
	T* arr;

public:

	DynamicArray() {
		this->arr = new T[this->capacity];
	}

	DynamicArray(int capacity) {
		this->capacity = capacity;
		this->arr = new T[this->capacity];
	}

	void add(T data) {
		if (this->size >= this->capacity) {
			grow();
		}
		this->arr[this->size] = data;
		this->size++;
	}

	void insert(int index, T data) {
		if (this->size >= this->capacity) {
			grow();
		}
		for (int i = size; i > index; i--)
		{
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[index] = data;
		this->size++;
	}

	void remove(T data) {
		for (int i = 0; i < size; i++) {
			if (this->arr[i] == data) {
				for (int j = 0; j < this->size - i - 1; j++) {
					this->arr[i + j] = this->arr[i + j + 1];
				}
				this->arr[this->size - 1] = NULL;
				this->size--;

				if (this->size <= (int)(this->capacity / 3)) {
					this->shrink();
				}
				break;
			}
		}
	}

	int search(T data) {

		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] == data) {
				return i;
			}
		}

		return -1;
	}

	void grow() {
		int newCapacity = this->capacity * 2;
		T* newArr = new T[newCapacity];

		for (int i = 0; i < this->size; i++)
		{
			newArr[i] = this->arr[i];
		}
		this->capacity = newCapacity;
		this->arr = newArr;
	}

	void shrink() {
		int newCapacity = this->capacity / 2;
		T* newArr = new T[newCapacity];

		for (int i = 0; i < this->size; i++)
		{
			newArr[i] = this->arr[i];
		}
		this->capacity = newCapacity;
		this->arr = newArr;
	}

	bool isEmpty() {
		return size == 0;
	}

	void print() {
		std::cout << "[ ";
		for (int i = 0; i < this->size; i++) {
			std::cout << this->arr[i] << (i != size - 1 ? ", " : "");
		}
		std::cout << " ]";
	}

};