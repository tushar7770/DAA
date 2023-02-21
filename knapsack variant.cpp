
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define size 101
using namespace std;
int ans[size],arr[size];
void solve()
{
    int countt=0,c=0,x=0;
    int t; cin>>t;c=t;
    int n=0,amt=0;
    while(t)
    {
        int total=0,i=0,j=0;
        cin>>n>>amt;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int temp=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[i]< arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        for(j=0;j<n;j++)
        {
            if(total<amt)
            {
                total+=arr[j];
                x++;
            }
            else
            {
                break;
            }
        }
        if(total>=amt)
        {
            ans[countt]=x;
        }
        else
        {
            ans[countt]=-1;
        }
        countt++;
        t--;x=0;
    }
    for(int z=0;z<c;z++)
    {
        cout<<ans[z]<<endl;
    }
    
    return;
}


int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

