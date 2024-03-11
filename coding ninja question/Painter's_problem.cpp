#include<iostream>
#include<vector>
using namespace std;
bool isPossible(vector<int> arr, int k , int mid){
    int painter = 1;
    int boardSum = 0;
    for(int i=0; i<arr.size();i++){
        if(boardSum + arr[i] <= mid ){
            boardSum += arr[i];
        }
        else{
            painter++;
            if(painter>k || arr[i]>mid){
                return false;
            }
            boardSum = arr[i];
        }
        if(painter > k){
            return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
     int start = 0;
    int end = 0;
    for(int i=0;i<boards.size();i++){
        end += boards[i];
    }
    int mid, answer = -1;
    while(start<=end){
        mid = start + (end - start)/2;
        if(isPossible(boards,k,mid)){
            answer = mid;
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
    return answer;
}
 
    int main(){
    vector<int> boards;
    boards.push_back(10);
    boards.push_back(20);
    boards.push_back(30);
    boards.push_back(40);

    int k = 2;

    cout << findLargestMinDistance(boards,k) << endl;
    return 0;
}