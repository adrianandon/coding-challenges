#include <iostream>
#include <sstream> 

std::string reverseStringRecursively(std::string str)
{
    std::string partialReversedStr;
    if(str.size() > 1)
        partialReversedStr = reverseStringRecursively(str.substr(1, str.size()));
    
    std::stringstream reversedStringStream;
    reversedStringStream<<partialReversedStr;
    reversedStringStream<<str.front();

    return reversedStringStream.str();
} 

int main()
{
    auto str = "abcdefghijklmnopqrstuvxyz";

    auto reversedString = reverseStringRecursively(str);

    std::cout<<reversedString<<std::endl;
}