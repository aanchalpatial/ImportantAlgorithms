#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int i=0,j=0,k=0;
    for(;i<6&&j<5&&k<8;)
    {
        if(ar1[i]<ar2[j])++i;
        else if(ar1[i]>ar2[j])++j;
        else if(ar1[i]==ar2[j])
        {
            if(ar1[i]==ar3[k])
            {   
                cout<<ar1[i]<<"\t";
                ++i;
                ++j;
                ++k;
            }
            else if(ar1[i]!=ar3[k])++k;
        }
    }
    
    
    return 0;
}
