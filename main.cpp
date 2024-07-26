#include "Vector.hpp"

int main() {
    Vector<int> myVector = Vector<int>();
    Vector<int> myVector2 = Vector<int>();;

    myVector2.pushBack(20);
    myVector2.pushBack(30);
    myVector2.pushBack(10);
    myVector2.reverse();

    std::cout << myVector2 << std::endl;


    myVector.pushBack(20);
    myVector.pushBack(10);
    myVector.insert(1, 30);
    myVector.popBack();
    

    std::cout << "Size of Vector: " << myVector.size() << std::endl;
    std::cout << myVector << std::endl;
    bool x = myVector == myVector2;
    if (x)
    {
        std::cout << "Vectors are equal" << std::endl;;
    }
    else {
        std::cout << "Vectors are not equal" << std::endl;
    }

    return 0;
}
