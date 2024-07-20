#include "Vector.hpp"

int main() {
    Vector<int> myVector;
    Vector<int> myVector2;

    myVector2.pushBack(20);
    myVector2.pushBack(30);
    myVector2.pushBack(10);

 

    
    myVector.pushBack(20);
    myVector.pushBack(10);
    myVector.insert(1, 30);
    myVector.pop_back();
    myVector.display();
    
    std::cout << "Size: " << myVector.Size() << std::endl;
    bool x = myVector == myVector2;
    std::cout << myVector2 << std::endl;

    return 0;
}
