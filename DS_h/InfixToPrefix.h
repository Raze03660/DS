#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else {
        return false;
    }
}

//權重
int precedence(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}
//A/B–C+D*E–A*C
string InfixToPrefix(stack<char> s, string infix) {
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] >= 'A' && infix[i] <= 'Z') {
            //if it is operand than append to prefix
            prefix += infix[i];
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while ((!s.empty()) && (s.top() != '(')) {
                //判斷是否為空和是否不是左括號 是operator才會加到prefix裡
                prefix += s.top();
                s.pop();
            }
            //遇到左括號表示裡面的operator都pop出來了 所以要pop出來才會抵消
            if (s.top() == '(') {
                s.pop();
            }
        } else if (isOperator(infix[i])) {
            if (s.empty()) {
                s.push(infix[i]);
            } else {
                if (precedence(infix[i]) >= precedence(s.top())) {
                    s.push(infix[i]);
                } else {
                    while (!s.empty() && (precedence(infix[i]) < precedence(s.top()))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    //可能會剩下括號以外的符號
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

bool isOperand(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    } else {
        return false;
    }
}
//-/*A+BCDG
string PrefixToInfix(string prefix) {
    stack<string> s;
    for (int i = prefix.length()-1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            string op(1, prefix[i]);
            s.push(op);
        } else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}
