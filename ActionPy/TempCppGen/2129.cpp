#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int j = 0;
        for (int i = 0; i <= title.size(); ++i)
        {
            if (title[i] == ' ' || title[i] == '\0')
            {
                if (i - j > 2) 
                    title[j] = toupper(title[j]);
                j = i + 1;
            } 
            else
                title[i] = tolower(title[i]);
        }
        return title;
    }
};
int main()
{
   return 0;
}