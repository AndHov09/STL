#include "String.h"

int main()
{
    String str("Hello");
    std::cout << str << std::endl;
    String str1 = str;
    str1.push_back('a');
    str1.insert(3,'b');
    std::cout << str1 << std::endl;
    String str2 = str1 + str;
    std::cout << str2 << std::endl;
    std::cout << str2.size() << std::endl;
}
