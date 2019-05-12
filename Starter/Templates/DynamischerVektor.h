#pragma once
#include <cassert>

template<class T>
class DynamischerVektor
{
public:
	DynamischerVektor() 
	{
		size = 0;
		capacity = 1;
		data = new T; //Konstruktor ohne Parameter wird erwartet
	}

	DynamischerVektor(const DynamischerVektor&) = delete; //Entferne Kopier Konstruktor

	DynamischerVektor(size_t capacity) //Konstruktor mit Parameter
	{
		size = 0;
		capacity = capacity;
		data = new T[capacity];
	}

	~DynamischerVektor() 
	{
		capacity = 0;
		size = 0;
		delete[] data;
		data = nullptr;
	}

	//Abfangen wenn Array-Index ueberschritten wird
	T operator[](size_t index)
	{
		assert(index < size);
		return data[index];
	}

	void push_back(T item) 
	{
		if (size >= capacity)
		{
			resize(capacity + capacity); //verdoppeln
		}

		data[size] = item;
		size++;
	}

	T pop_back()
	{
		if (size <= capacity * 0.25f)
		{
			resize(capacity * 0.5f);
		}

		size--;
		return data[size];
	}

	size_t getSize()
	{
		return size;
	}

	size_t getCapacity()
	{
		return capacity;
	}

private:
	size_t size;
	size_t capacity;
	T* data;

	void resize(size_t newCapacity)
	{
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		capacity = newCapacity;
		data = newData;
	}
};
