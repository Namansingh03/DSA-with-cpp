#include<iostream>
using namespace std;

bool isPossible(int arr[], int numChapters, int numStudents, int mid) {
    int days = 1;
    int chapterSum = 0;
    for (int i = 0; i < numChapters; i++) {
        if (chapterSum + arr[i] <= mid) {
            chapterSum += arr[i];
        } else {
            days++;
            if (days > numStudents || arr[i] > mid) {
                return false;
            }
            chapterSum = arr[i];
        }
        if (days > numStudents) {
            return false;
        }
    }
    return true;
}

int bookAllocation(int time[], int m, int n) {
    int start = 0;
    int end = 0;
    for (int i = 0; i < m; i++) {
        end += time[i];
    }
    int mid, answer = -1;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (isPossible(time, m, n, mid)) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return answer;
}

int main() {
    int arr[] = {1, 2, 2, 3, 1};
    int numStudents = 3;
    int numChapters = sizeof(arr) / sizeof(arr[0]);
    cout << bookAllocation(arr, numChapters, numStudents);
    return 0;
}
