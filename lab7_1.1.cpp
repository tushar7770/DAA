//tushar panjeta cs20b1098
//dynamic coin change problem
#include<iostream>
#define size 200
using namespace std;

class coinChange
{
    public :
    int n , array[size] , amt;

    void createArray();

    void coins();

};

void coinChange::createArray()
{
    cout<<"\nEnter no. of denominations : ";
    cin>>n;
    while(n<=0)
    {
        cout<<"\n[ERROR] Invalid input , TRY AGAIN";
        cout<<"\nEnter no of denominations : ";
        cin>>n;
    }

    cout<<"\nEnter the "<<n<<" denominations : ";
    for(int i=0 ; i<n ;i++)
    {
        cin>>array[i];
    }
}



void coinChange::coins()
{
    int c[amt+1];
    int output[amt+1];

    for(int i=0;i<n;i++)
    {
        output[i]=0;
    }

    c[0] = 0;

    for (int i=1; i<=amt; i++)
        c[i] = INT_MAX;

    for (int i=1; i<=amt; i++)
    {
        for (int j=0; j<n; j++)
        {
           if (array[j] <= i)
           {
                int  remaining = c[i-array[j]];

                if ( remaining != INT_MAX && remaining + 1 < c[i])
                {
                    c[i] = remaining + 1;
                    output[i]=j;
                }
                  
            }
        }
    }
    if(c[amt]==INT_MAX)
    {
        cout<<"\nNo change possible";
    }
    else
    {
        cout<<"\nMIN COINS : "<<c[amt]<<" -> ";
        cout<<"{";
        while(amt)
        {
            cout<<array[output[amt]];
            amt=amt-array[output[amt]];
            if(amt)
            {
                cout<<",";
            }
        }
        cout<<"}";
    }

}

int main()
{
    coinChange c1;

    cout<<"\nEnter the amount : ";
    cin>>c1.amt;

    c1.createArray();
   
    c1.coins();

    return 0;
}
