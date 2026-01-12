#pragma once
#include "CRefCounter.h"
template<typename T>
class CMySmartPointer {
private:
	CMySmartPointer(T* pc_pointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	T& operator*();
	T* operator->();
	CMySmartPointer& operator=(const CMySmartPointer& pcOther);
public:
	T* pc_pointer;
	CRefCounter* pc_counter;
};

#include "CMySmartPointer.tpp"