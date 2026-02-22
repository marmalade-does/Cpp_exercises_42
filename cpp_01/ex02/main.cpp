
#include <iostream>
#include <iomanip>
#include <string>

int     main(void)
{
        std::string             str = "HI THIS IS BRAIN";

        std::string             *stringPTR = &str;
        std::string             &stringREF = str;

        std::cout << std::left
                << std::setw(22) << "Address of str: " << &str << '\n'
                << std::setw(22) << "Address of stringPTR: " << stringPTR << '\n'
                << std::setw(22) << "Address of stringREF: " << &stringREF << std::endl;

        std::cout << std::endl;

        std::cout << std::setw(22) << "Value of str: " << str << '\n'
                << std::setw(22) << "Value of stringPTR: " << *stringPTR << '\n'
                << std::setw(22) << "Value of stringREF: " << stringREF << std::endl;

        std::cout << std::endl;

        return (0);
}


