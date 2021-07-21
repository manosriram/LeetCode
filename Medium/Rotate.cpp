#include <iostream>
using namespace std;
int r = 4, c = 4;

void transpose(int a[5][5]) {
    for (int t=0;t<r;++t) {
        for (int tt=t;tt<c;++tt) {
            swap(a[t], a[tt]);
        }
    }
}

void reverseCol(int arr[5][5]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0, k = 4 - 1; j < k; j++, k--)
            swap(arr[j][i], arr[k][i]);

    for (int t=0;t<r;++t) {
        for (int tt=0;tt<c;++tt) {
            cout << arr[t][tt] << " ";
        }
        cout << endl;
    }
}

void rotate(int a[5][5]) {
    transpose(a);
    reverseCol(a);
}

int main() {
    int arr[5][5] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    rotate(arr);
}
