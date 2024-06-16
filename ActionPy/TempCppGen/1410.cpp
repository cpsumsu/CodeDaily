#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
using namespace std;

#include <regex>


class Solution_a {
public:
    string entityParser(string text) {
        std::regex 
        reg1("&quot;"),
        reg2("&apos;"),
        reg3("&gt;"),
        reg4("&lt;"),
        reg5("&frasl;"),
        reg6("&amp;");
        text = std::regex_replace(text, reg1, "\"");
        text = std::regex_replace(text, reg2, "\'");
        text = std::regex_replace(text, reg3, ">");
        text = std::regex_replace(text, reg4, "<");
        text = std::regex_replace(text, reg5, "/");
        text = std::regex_replace(text, reg6, "&");
        return text;
    }
}; 
int main()
{
   return 0;
}