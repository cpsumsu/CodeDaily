#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution_a {
public:
	int cal(int a, int b, string c) {
 		if (c == "*")
 			return a * b;
 		else if (c == "+")
 			return a + b;
 		else if (c == "/")
 			return b / a;
 		else
 			return b - a;
 	}

    int evalRPN(vector<string>& tokens) {
     	stack<int> s;

     	int ret = 0;
     	for (auto &x : tokens) {
     		if (string("+-*/").find(x) == string::npos) 
     			s.push(atoi(x.c_str()));
     		else {
     			assert(s.size() >= 2);
     			auto a = s.top(); s.pop();
     			auto b = s.top(); s.pop();
     			s.push(cal(a, b, x));
     		}
     	}

     	return s.top();
    }
};
int main()
{
   return 0;
}