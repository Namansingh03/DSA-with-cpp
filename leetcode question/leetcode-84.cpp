#include<iostream.
#include<vector>
#include<stack>

using namespace std;
vector<int> nextSmallerElement(vector<int>&arr ,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n); 

    for (int i = n - 1; i >= 0; i--) {
        int current = arr[i];
        while (s.top() != -1 && arr[s.top()] >= current) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerRllement(vector<int>&arr ,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n); 

    for (int i =0 ; i<n ; i++) {
        int current = arr[i];
        while (s.top() != -1 && arr[s.top()] >= current) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);

        next = nextSmallerElement(heights,n);

        vector<int>prev(n);
        int area = INT_MIN;
        prev = prevSmallerRllement(heights,n);

        for(int i=0 ; i<n ; i++){
            int l = heights[i];

            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] -1;

            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
}

int main(){
    vector<int>arr = {2,1,5,6,2,3};

    cout << largestRectangleArea(arr) << endl;
    return 0;
}
