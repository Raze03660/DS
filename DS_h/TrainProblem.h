#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, cnt = 9, state3 = 1;
static int count = 0;
vector<int> state1;
stack<int> state2;

void dfs() {
    if (state1.size() == n) {
        cnt--;// 輸出前9個結果
        for (auto x: state1){
            printf("%d", x);
        }
        printf("\n");
        count++;
        return;
    }

    if (state2.size())//pop
    {
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back());
        state1.pop_back();
    }
    if (state3 <= n)//push
    {
        state2.push(state3);
        state3++;
        dfs();
        state3--;
        state2.pop();
    }
}
