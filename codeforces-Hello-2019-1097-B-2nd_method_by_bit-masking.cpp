#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define int long long int
#define float long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX_SIZE = 1000001; 
void bitmasking(int arr[],int S,int n)
{
    assert((1LL<<n)<(long long)1e18);
    for(int mask=0;mask<(1LL<<n);mask++)
    {
        int subset_sum=0;
        for(int i=1;i<=n;i++)
        {
            if(mask & (1LL<<(i-1)))
            subset_sum+=arr[i];
            else
            {
                subset_sum-=arr[i];
            }
            if(subset_sum>=360)
            subset_sum%=360;
            if(subset_sum<=(-360))
            subset_sum=360+subset_sum%360;
        }
        if(subset_sum==S)
        {
            fputs("YES",stdout);
            return;
        }
    }
    fputs("NO",stdout);
    return;
}
void myfun()
{
    int n;
    cin>>n;
    // int S;
    // cin>>S;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    bitmasking(arr,0,n);
} 
signed main()
{
   fastio
    int t=1;
    // cin>>t;
    while(t--)
        myfun();
}
