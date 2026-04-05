#include <iostream>
#include "core/Matrix.hpp"

using namespace std;


int main () {
    Matrix A(2,3); 
    Matrix B(3,2); 
    A.randomize(); B.randomize(); 
    cout <<"A matrix :" << endl; A.print(); cout << endl; 
    cout <<"B matrix :" << endl; B.print(); cout << endl;  

    Matrix C = A.dot(B) ; 
    cout <<"C matrix :" << endl; C.print(); cout << endl;
    Matrix bias(2,2) ;
    C.add(bias); 
    cout <<"C matrix plus bias :" << endl; C.print(); cout << endl;
    return 0; 
}