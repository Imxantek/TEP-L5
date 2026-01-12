#include<iostream>
using namespace std;
#include "CMySmartPointer.h"
#include "CTree.h"
int main() {
	CTree c_tree;
	CTree c_other;
	c_tree = std::move(c_other);
	return 0;
}