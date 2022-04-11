#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <ctype.h>

void PrintV1(vector<int> &, bool, int);

void PrintV2(vector<int> &, bool, int);

void PrintV3(vector<int> &, bool, int);


using namespace std;

/*
 *  A--(n-1 disks)-->B
 *  A--(  n disk )-->C
 *  B--(n-1 disks)-->C
 *
 *  int data, disk;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    cout << "輸入資料筆數" << endl;
    cin >> data;
    for (int i = 0; i < data; i++) {
        cout << "請輸入測試數字" << endl;
        cin >> disk;

        clearVector(v1, v2, v3);

        pushToVector(v1, disk);

        PrintInitialArray(v1, v2, v3);

        towers(disk, v1, v2, v3);
    }
    cout<<"END!";
 *
 *
 */

static string strA = "A(", strB = "B(", strC = "C(";

void towers(int disk, vector<int> &v1, vector<int> &v2, vector<int> &v3) {
    vector<int>::iterator it;
    it = v1.begin();
    int i1 = 0, i2 = 0, i3 = 0;
    //判斷vector是否原本就空
    bool flagA = true, flagB = true, flagC = true;


    if (disk > 0) {
//      A--(n-1 disks)-->B
        towers(disk - 1, v1, v3, v2);

//      取得最前面的元素
        int front = v1.front();

//      v1.清除最前面元素
        v1.erase(it);

//      push front進去
        v3.push_back(front);
//      排序
        sort(v3.begin(), v3.end());

//      A--(  n disk )-->C
        cout << strA;
        PrintV1(v1, flagA, i1);
        cout << strB;
        PrintV2(v2, flagB, i2);
        cout << strC;
        PrintV3(v3, flagC, i3);
        cout << endl;

//      B--(n-1 disks)-->C
        towers(disk - 1, v2, v1, v3);
    }
}

void PrintInitialArray(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
    int i = 0;
    bool flag = true;
    string str = "A(";
    cout << str;
    while (flag) {
        if (v1.back() == v1.at(i)) {
            cout << v1[i] << ")";
            flag = false;
        } else {
            cout << to_string(v1[i]).insert(1, ",");
            i++;
        }
    }
    cout << "B()C()" << endl;
}

void PrintV1(vector<int> &v1, bool flagA, int i1) {
    if (!v1.empty() && flagA) {
        while (true) {
            if (v1.back() == v1.at(i1)) {
                cout << v1[i1] << ")";
                flagA = false;
                break;
            } else {
                cout << to_string(v1[i1]).insert(1, ",");
                i1++;
            }
        }
    } else if (v1.empty() && flagA) {
        // 原本就為空，但沒列印過
        cout << ")";
    }
}

void PrintV2(vector<int> &v2, bool flagB, int i2) {
    if (!v2.empty() && flagB) {
        while (true) {
            if (v2.back() == v2.at(i2)) {
                cout << v2[i2] << ")";
                flagB = false;
                break;
            } else {
                cout << to_string(v2[i2]).insert(1, ",");
                i2++;
            }
        }
    } else if (v2.empty() && flagB) {
        // 原本就為空，但沒列印過
        cout << ")";
    }
}

void PrintV3(vector<int> &v3, bool flagC, int i3) {
    if (!v3.empty() && flagC) {
        while (true) {
            if (v3.back() == v3.at(i3)) {
                cout << v3[i3] << ")";
                flagC = false;
                break;
            } else {
                cout << to_string(v3[i3]).insert(1, ",");
                i3++;
            }
        }
    } else if (v3.empty() && flagC) {
        // 原本就為空，但沒列印過
        cout << ")";
    }
}

void clearVector(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
    if (!v1.empty()) {
        v1.clear();
    } else if (!v2.empty()) {
        v2.clear();
    } else if (!v3.empty()) {
        v3.clear();
    }
}

void pushToVector(vector<int> &v, int disk) {
    //push initialVector
    for (int j = 1; j <= disk; j++) {
        v.push_back(j);
    }
}