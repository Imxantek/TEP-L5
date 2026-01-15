#include<iostream>
#include "CMySmartPointer.h"
#include "CTree.h"

class CTest {
private:
    int i_val;
public:
    CTest(int i) {
        i_val = i;
        std::cout << "  [Konstruktor CTest] Tworze obiekt o wartosci: " << i_val << std::endl;
    }
    ~CTest() {
        std::cout << "  [Destruktor ~CTest] Kasuje obiekt o wartosci: " << i_val << std::endl;
    }
    void vHello() {
        std::cout << "  [Metoda vHello] Czesc z obiektu: " << i_val << std::endl;
    }
};

void testMoveSemantics() {
    CTree tree1;
    std::string exp1 = "+ 1 2";
    tree1.enter(exp1);

    CTree tree2;
    std::string exp2 = "+ 3 4";
    tree2.enter(exp2);

    std::cout << "--- TEST DODAWANIA ---\n";
    CTree tree3 = std::move(tree1 + tree2);

    std::cout << "\n--- WYNIK DODAWANIA ---\n";
    tree3.print();

    std::cout << "\n--- TEST PRZENOSZENIA ---\n";
    CTree tree4 = std::move(tree3);

    std::cout << "\n--- TEST KOPIOWANIA ---\n";
    CTree tree5 = tree4;

}
void testSmartPointers() {
    std::cout << "=== TEST 1: Podstawowe tworzenie i niszczenie ===\n";
    {
        CMySmartPointer<CTest> ptr1(new CTest(10));
        ptr1->vHello(); 
        (*ptr1).vHello(); 
    }
    std::cout << "--- Koniec Testu 1 ---\n\n";


    std::cout << "=== TEST 2: Kopiowanie wskaznikow (Wspoldzielenie) ===\n";
    {
        CMySmartPointer<CTest> ptr1(new CTest(20)); 
        {
            std::cout << "  > Wchodze w blok wewnetrzny...\n";
            CMySmartPointer<CTest> ptr2 = ptr1;
            ptr2->vHello();
            std::cout << "  > Wychodze z bloku wewnetrznego (ptr2 ginie)...\n";
        }
        std::cout << "  > Jestem z powrotem w bloku zewnetrznym. ptr1 nadal zyje.\n";
        ptr1->vHello();
    }
    std::cout << "--- Koniec Testu 2 ---\n\n";


    std::cout << "=== TEST 3: Operator przypisania (Nadpisywanie) ===\n";
    {
        CMySmartPointer<CTest> ptr1(new CTest(30));
        CMySmartPointer<CTest> ptr2(new CTest(40));

        std::cout << "  > Przypisuje ptr1 = ptr2...\n";
        ptr1 = ptr2;

        std::cout << "  > Po przypisaniu. Obiekt 30 powinien byc juz martwy.\n";
        ptr1->vHello();
    }
    std::cout << "--- Koniec Testu 3 ---\n";
}
int main() {
    //testSmartPointers();
    testMoveSemantics();
    return 0;
}