/*
https://www.geeksforgeeks.org/batch/placement-100-2019/track/DSASP-Searching/problem/count-only-repeated2047
Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.
Note: If there's no repeating element, Return {-1,-1}.


Example 1:

Input:
N = 5
arr[] = {1,2,3,3,4}
Output: 3 2
Explanation: In the given array, 3 is 
occuring two times.
*/

pair<long, long> findRepeating(long *arr, int n){
    //code here
    // step 1: find repeating element
    int repeatingElementIndex = -1;
    int l=0, h=n-1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        // cout<<l<<", "<<mid<<", "<<h<<endl;
        
        if((mid!=0&&arr[mid]==arr[mid-1])||(mid!=n-1&&arr[mid]==arr[mid+1])) {
            repeatingElementIndex = mid;
            break;
        } else if(arr[mid]-arr[l]>=arr[h]-arr[mid]) {
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    if(repeatingElementIndex==-1) return {-1, -1};
    // step 2: find first index of repeating element
    int firstIndex;
    l=0, h=n-1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if(arr[mid]==arr[repeatingElementIndex]&&(mid==0||arr[mid]!=arr[mid-1])) {
            firstIndex = mid;
            break;
        } else if(arr[repeatingElementIndex]<=arr[mid]) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    // step 3: find last index of repeating element
    int lastIndex;
    l=0, h=n-1;
    while(l<=h) {
        int mid = l + (h-l)/2;
        if(arr[mid]==arr[repeatingElementIndex]&&(mid==n-1||arr[mid]!=arr[mid+1])) {
            lastIndex = mid;
            break;
        } else if(arr[repeatingElementIndex]<arr[mid]) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    // step 4: count = last index - first index + 1
    return {arr[repeatingElementIndex], lastIndex-firstIndex+1};
}