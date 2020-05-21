#include <iostream>
#include <vector>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    vector<int> v(arr.size());
    int n = arr.size();
    v[n-1] = arr[n-1];

    for (int t=n-2;t>=0;--t)
        v[t] = max(arr[t+1], v[t+1]);

    v[n-1] = -1;
    return v;
}

int main() {
    vector<int> arr = { 17,18,5,4,6,1 };

    arr = replaceElements(arr);

    for (auto t: arr) cout << t << " ";
}

