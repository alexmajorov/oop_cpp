#include <iostream>
#include <string>

class my_string : public std::string
{
public:
    using std::string::string;

    void delete_extra_spaces(void)
    {
        size_t pos = 0;
        while ((pos = find("  ", pos)) != std::string::npos) replace(pos, 2, " ");
    }
};

int main() 
{
    my_string text = "Hello      hello!      How    are you?\nHello,     my      friend!";
    text.delete_extra_spaces();
    std::cout << text << "\n";
    return 0;
}