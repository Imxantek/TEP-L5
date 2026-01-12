#pragma once
#include "CRefCounter.h"
template<typename T>
class CMySmartPointer {
public:
	CMySmartPointer(T* pc_pointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	T& operator*();
	T* operator->();
	CMySmartPointer& operator=(const CMySmartPointer& pcOther);
private:
	T* pc_pointer;
	CRefCounter* pc_counter;
};

#include "CMySmartPointer.tpp"