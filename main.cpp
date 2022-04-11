#include <iostream>
#include <stack>
#include "DS_h/InfixToPrefix.h"

using namespace std;


int main() {
    int data, key;
    string infix, prefix;
    stack<char> stack;
    cout<<"�п�J�n�X�����:"<<endl;
    cin >> data;
    for (int i = 0; i < data; i++) {
        cout<<"�п�J�n�઺�Ҧ�1.(in->pre)2.(pre->in):"<<endl;
        cin >> key;
        if (key == 1) {
            cout << "Enter infix expression" << endl;
            cin >> infix;
            cout << "Infix expression is:" << infix << endl;
            prefix = InfixToPrefix(stack, infix);
            cout << "Prefix expression is:" << prefix << endl;
        } else if (key == 2) {
            cout << "Enter prefix expression" << endl;
            cin >> prefix;
            cout << "Prefix expression is:" << prefix << endl;
            infix = PrefixToInfix(prefix);
            cout << "Infix expression is:" << infix << endl;
        }
    }
    return 0;
}
