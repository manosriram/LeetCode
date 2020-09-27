#include <iostream>
using namespace std;

int findElement(int *arr, int n, int target, int l, int h) {
    if (l > h) return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == target) return mid;

    if (arr[l] <= arr[mid]) {
        if (target >= arr[l] && target <= arr[mid])
            return findElement(arr, n, target, l, mid - 1);
        else
            return findElement(arr, n, target, mid+1, h);
    }

    if (target >= arr[mid] && target <= arr[h])
        return findElement(arr, n, target, mid+1, h);

    return findElement(arr, n, target, l, mid-1);

}

int main() {
    int arr[] = { 3, 4, 5, 6, 1, 2 };
    int n = 6;

    cout << findElement(arr, n, 6, 0, n - 1);
}
