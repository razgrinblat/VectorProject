#include "Vector.hpp"

int main() {
    Vector<int> myVector; 

    
    myVector.pushBack(10);
    myVector.pushBack(20);
    myVector.insert(1, 30); 
    myVector.display(); 
    myVector.reverse();
    myVector.display();

    return 0;
}
