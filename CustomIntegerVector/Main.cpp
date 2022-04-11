#include "CustomIntegerVector.h"

int main()
{
    CustomIntegerVector test_vector_1 = CustomIntegerVector({ 1, 2, 3, 4 });

    std::cout << "Size of a vector: " << test_vector_1.GetSize() << std::endl;
    std::cout << "Capacity of a vector: " << test_vector_1.GetCapacity() << std::endl;

    test_vector_1 = CustomIntegerVector({ 1, 2, 3, 4 });

    std::cout << "Size of a vector: " << test_vector_1.GetSize() << std::endl;
    std::cout << "Capacity of a vector: " << test_vector_1.GetCapacity() << std::endl;

    return 0;
}
