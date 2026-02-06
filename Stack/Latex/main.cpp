#include <iostream>
#include <stack>

using namespace std;

bool match(char open, char close) {
	return (open == '(' && close == ')') ||
		(open == '{' && close == '}') ||
		(open == '[' && close == ']');
}

bool isValid(string str) {
	stack<char> S;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c == '(' || c == '{' || c == '[')
			S.push(c);
		else if (c == ')' || c == '}' || c == ']') {
			if (S.empty()) return 0;
			char top = S.top();
			S.pop();
			if (!match(top, c)) return 0;
		}
	}
	return (S.empty()) ? 1 : 0;
}

int main() {
	string str;
	cin >> str;
	cout << isValid(str);

	return 0;
}