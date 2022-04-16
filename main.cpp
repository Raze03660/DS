#include <iostream>
#include "DS_h/TrainProblem.h"


using namespace std;

int main() {
    int i = 0, input;
    cout << "請輸入要幾筆測試資料:" << endl;
    cin >> input;
    for (; i < input; i++) {
        cout << "請輸入第" << i + 1 << "筆資料:" << endl;
        scanf("%d", &n);
        dfs();
        cout << count << endl;
        count = 0;
    }
    return 0;
}