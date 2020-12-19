#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define int long long int
#define float long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX_SIZE = 1000001; 
int n,l,r,diff;
int bitmasking(int arr[],int n)
{
    assert((1LL<<n)<(long long)1e18);
    int total_count=0;
    for(int mask=0;mask<(1LL<<n);mask++)
    {
        int sum=0,count=0,min1=INT_MAX,max1=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(mask & (1LL<<(i-1)))
            {
                count++;
                sum+=arr[i];
                min1=min(min1,arr[i]);
                max1=max(max1,arr[i]);
            }
        }
        if(count>=2 && sum>=l && sum<=r && abs(min1-max1)>=diff)
        {
            total_count++;
        }
    }
    return total_count;
}
void myfun()
{
    cin>>n>>l>>r>>diff;
    // int S;
    // cin>>S;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<bitmasking(arr,n)<<"\n";
} 
signed main()
{
   fastio
    int t=1;
    // cin>>t;
    while(t--)
        myfun();
}
