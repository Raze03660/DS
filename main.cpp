#include <iostream>
#include "DS_h/Rectangle.h"
#include "DS_h/BinarySearch.h"

using namespace std;

int main() {

    int arr[10] = {1, 4, 5, 6, 7, 8, 31, 33, 54, 65};
    //found in 5
    cout << Binary_Search(arr, 8, 10)<<endl;
    //not found return -1
    cout << Binary_Search_Recursive(arr, 8, 0,9);
}
