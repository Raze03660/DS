#include <iostream>
#include "DS_h/TrainProblem.h"


using namespace std;

int main() {
    int i = 0, input;
    cout << "�п�J�n�X�����ո��:" << endl;
    cin >> input;
    for (; i < input; i++) {
        cout << "�п�J��" << i + 1 << "�����:" << endl;
        scanf("%d", &n);
        dfs();
        cout << count << endl;
        count = 0;
    }
    return 0;
}