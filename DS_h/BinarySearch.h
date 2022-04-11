#include <iostream>

using namespace std;

/*
 * int arr[10] = {1, 4, 5, 6, 7, 8, 31, 33, 54, 65};
 *
 * cout << Binary_Search(arr, 8, 10)<<endl;
 * -->found in 5
 *
 * cout << Binary_Search_Recursive(arr, 8, 0,9);
 * -->not found return -1
 */

int Binary_Search(int *arr, int target, const int capacity) {
    int left = 0, right = capacity - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (target > arr[middle]) {
            left = middle + 1;
        } else if (target < arr[middle]) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}

//遞迴版本

int Binary_Search_Recursive(int *arr, int target, const int left, const int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (target > arr[middle]) {
            return Binary_Search_Recursive(arr, target, middle + 1, right);
        } else if (target < arr[middle]) {
            return Binary_Search_Recursive(arr, target, left, middle - 1);
        } else {
            return middle;
        }
    }
    return -1;
}