#include<iostream>
#include "CMySmartPointer.h"
#include "CTree.h"

int main() {
    CTree tree1;
    std::string exp1 = "1 2 +";
    tree1.enter(exp1);

    CTree tree2;
    std::string exp2 = "3 4 +";
    tree2.enter(exp2);

    std::cout << "--- TEST DODAWANIA (OPERATOR +) ---\n";
    CTree tree3 = tree1 + tree2;

    std::cout << "\n--- TEST PRZENOSZENIA (STD::MOVE) ---\n";
    CTree tree4 = std::move(tree3);

    return 0;
}