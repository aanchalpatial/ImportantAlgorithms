/*
https://www.geeksforgeeks.org/batch/placement-100-2019/track/DSASP-Strings/problem/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

*/

bool contains(int shash[], int phash[]) {
    for(int i=0;i<26;++i) {
        if(shash[i]<phash[i]) return false;
    }
    return true;
}
string smallestWindow (string s, string p)
{
    // Your code here
    int n = s.size();
    int m = p.size();
    if(m>n) return "-1";
    // string resultStr;
    // int result = INT_MAX;
    // // naive solution
    // // time: O(n^3) & space: O(1)
    // for(int i=0;i<n;++i) {
    //     for(int j=i;j<n;++j) {
    //         vector<int> hashP(26, 0);
    //         for(int z=0;z<m;++z) hashP[p[z]-'a']++;
    //         string str = "";
    //         for(int k=i;k<=j;++k) {
    //             str += s[k];
    //             hashP[s[k]-'a']--;
    //         }
    //         bool containsAllChar = true;
    //         for(int x=0;x<26;++x) {
    //             if(hashP[x]>0) {
    //                 containsAllChar = false;
    //                 break;
    //             }
    //         }
    //         if(containsAllChar&&result>(j-i+1)) {
                
    //             result = j-i+1;
    //             resultStr = str;
    //         }
    //     }
    // }
    // return resultStr;
    
    // method 2: sliding window
    // time: O(n) & space: O(256)
    int phash[26] = {0};
    for(int i=0;i<m;++i) {
        int index = p[i] - 'a';
        phash[index]++;
    }
    int l=0, r=0;
    int shash[26] = {0};
    int resultL = 0, resultR = n;
    while(r<n) {
        // keep on incrementing r till l to r substring of s has all chars of p
        while(r<n&&contains(shash, phash)==false) {
            int index = s[r] - 'a';
            shash[index]++;
            ++r;
        }
        // keep on reducing window size, by incrementing l till l to r substring of s has all chars of p
        // since we need to find the min sized window
        while(contains(shash, phash)==true) {
            if((resultR-resultL+1)>(r-l)) {
                resultL = l;
                resultR = r-1;
            }
            int index = s[l] - 'a';
            shash[index]--;
            ++l;
        }
    }
    
    if(resultR==n) return "-1";
    string resultStr = "";
    for(int i=resultL;i<=resultR;++i) resultStr += s[i];
    return resultStr;
}