#pragma once
template<typename T>
class MyUniquePointer {
public:
	MyUniquePointer(T* pointer);
	~MyUniquePointer();
	MyUniquePointer(MyUniquePointer&& other) noexcept;
	T& operator->();
	T* operator*();
	MyUniquePointer& operator=(MyUniquePointer&& other) noexcept;
private:
	T* pc_pointer
};

#include "MyUniquePointer.tpp"