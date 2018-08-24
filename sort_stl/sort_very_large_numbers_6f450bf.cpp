#include <bits/stdc++.h>
using namespace std;

bool myConditions(string x,string y)
{
    if(x.size()!=y.size()){
        if(x.size()<y.size())return true;
        else return false;
    }
    else{
        return x<y;
    }
}

int main()
{
     vector<string> arr = {"5", "1237637463746732323", 
                    "97987", "13","12","11" };
    int n=arr.size();
    cout<<"Array(before sorting):\n";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    sort(arr.begin(),arr.end(),myConditions);
    cout<<"Array(after sorting):\n";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<"\t";
    }
    
    
    return 0;
}
