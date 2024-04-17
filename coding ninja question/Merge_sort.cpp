#include<iostream>
using namespace std;
//! fastest 
//? time complexity ->     , space complexity ->

void merge(int *arr, int start, int end) {

    int mid = (start+end)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = start;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void merge_Sort(int *arr, int start, int end) {

    if(start >= end) {
        return;
    }
    
    int mid = (start+end)/2;

    merge_Sort(arr, start, mid);
    
    merge_Sort(arr, mid+1, end);

    //merge
    merge(arr, start, end);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2};
    int n = 15;

    merge_Sort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}