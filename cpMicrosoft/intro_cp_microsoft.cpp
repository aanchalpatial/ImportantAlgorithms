
//ios_base::sync_with_studio(0);
//cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef double dd;
#define ap aanchal_patial
#define loop(i,a) for(int i=0;i<a;++i)
/*void aanchal_patial()
{
    cout<<"aanchal patial is a great guy\n";
}
void fibo(int x)
{
    cout<<"0->1->";
    int a=0,b=1;
    loop(i,x-2)
    {
        int temp=a+b;
        cout<<temp<<"->";
        a=b;
        b=temp;
    }
}
void fiboviaformula(int x)
{
    loop(i,x)
    {
        cout<<(pow((1+pow(5,0.5)),x)-pow((1-pow(5,0.5)),x))/(pow(2,x)*pow(5,0.5))<<"->";
    }
}
*/
int main(int argc, const char * argv[]) {
  /*  cout << "Hello, World!\n";

    dd d=(dd)22/7;
    ld e=(ld)22/7;
    printf("%.5f\n",d);
    ap();
    loop(i,5){cout<<10*i<<"\n";}*/
   /* int x;
    cin>>x;
    fibo(x);
    cout<<"\n";
    fiboviaformula(x);*/
    
   /* //------->>> maximum_subarray
    int arr[8]={-1 ,2 ,4 ,-3 ,5 ,2 ,-5, 2};
    
    int max_sum=0;                                                           //  0(n^3)
    for(int a=0;a<8;++a)
    {
        for(int b=a;b<8;++b)
        {int s=0;
            for(int c=a;c<b;++c)
            {s+=arr[c];}
            max_sum=max(max_sum,s);
        }
    }
    cout<<max_sum<<"\n";
    
    int max_sum2=0;                                                         //   0(n^2)
    for(int a=0;a<8;++a)
    {   int s=0;
        for(int b=a;b<8;++b)
        {s+=arr[b];
            max_sum2=max(max_sum2,s);
        }
    }
    cout<<max_sum2<<"\n";
    
    
    int max_sum3=0;                                                         //   0(n) dynPro
    int s=0;
    for(int i=0;i<8;++i)
    {
        //cout<<arr[i]<<"\t"<<s+arr[i]<<"\t"<<s<<"\t";
        s=max(arr[i],s+arr[i]);
        max_sum3=max(max_sum3,s);
        //cout<<s<<"\t"<<max_sum3<<"\n";
    }
    cout<<max_sum3<<"\n";
    
    // -1 ,2 ,4 ,-3 ,5 ,2 ,-5, 2
    
    //------->>> maximum_subarray
    
    //------->>> sorting
    int x[]={4,5,3,2,8,9};
    vector <int> v;
    loop(i,5){int m;
        cin>>m;
        v.push_back(m);}
    
    string s="zyxcba";
    sort(x,x+6);
    loop(i,6){cout<<x[i]<<"\t";}
    cout<<endl;
    sort(v.begin(),v.end());
    loop(i,v.size()){cout<<v[i]<<"\t";}
    cout<<endl;
    sort(v.rbegin(),v.rend());
    loop(i,v.size()){cout<<v[i]<<"\t";}
    cout<<endl;
    sort(s.begin(),s.end());
    cout<<s<<"\n";
    
    vector<pair<int,string>> p;
    loop(i, 3){
        int m;
        string s;
        cin>>m>>s;
        p.push_back(make_pair(m,s));
    }
    sort(p.begin(),p.end());
    
    loop(i, 3){
        cout<<p[i].first<<"\t"<<p[i].second<<"\n";
    }
    
    //------->>> sorting
    
    
    //------->>> searching                                                          gfg
    vector<int> arr1={10,15,20,25,30,35};
    vector<int> arr2={10,10,10,15,20,20,25,30,35};
    vector<int> arr3={10,15,25,30,35};
    
    bool x = binary_search(arr1.begin(),arr1.end(),22);
    cout<<x<<"\n";
   
    cout<<lower_bound(arr2.begin(),arr2.end(), 10)-arr2.begin()<<endl;
    cout<<upper_bound(arr2.begin(),arr2.end(), 10)-arr2.begin();
    
    
    //------->>> searching
    */
    
    
    
    
    
    
    
    
    
    

    cout<<"\n\n\n";
    return 0;
}
