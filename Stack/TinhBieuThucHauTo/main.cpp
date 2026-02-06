/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

void tachChuoi(string s, string arr[], int& n) {
    n = 0;
    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (temp != "") {      // nếu có từ tạm thì thêm vào mảng
                arr[n++] = temp;
                temp = "";
            }
        }
        else {
            temp += s[i];          // nối ký tự vào chuỗi tạm
        }
    }

    if (temp != "")                // thêm từ cuối cùng
        arr[n++] = temp;
}


string Tinh(string str) {
    stack<double> S;
    string token;
    double kq;
    

    if (S.size() != 1)
        return "KHONG HOP LE";

    kq = S.top();
    // nếu là số nguyên, in không có .000000
    if (kq == (int)kq)
        return to_string((int)kq);
    else
        return to_string(kq);
}

int main() {
    string str;
    getline(cin, str);
    cout << Tinh(str);
    return 0;
}