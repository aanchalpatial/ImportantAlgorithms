#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[]={2,1,9,4,3,5,6};
    int arr2[]={4,6,3,2,8,6,2};
    sort(arr1,arr1+7);
    sort(arr2,arr2+7);
    int i=0,j=0;
    for(;i<7&&j<7;)
    {
        if(arr1[i]<arr2[j])++i;
        else if(arr1[i]>arr2[j])++j;
        else if(arr1[i]==arr2[j]){cout<<arr1[i]<<"\t";
        ++i;
        ++j;}
    }
    return 0;
}
