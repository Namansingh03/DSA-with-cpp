#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n); 

    for (int i = n - 1; i >= 0; i--) {
        int current = arr[i];
        while (s.top() >= current) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(current);
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    vector<int> result = nextSmallerElement(arr, arr.size());

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
