//TUSHAR PANJETA CS20B1098 
//FUNCTION OVERLOADING FOR VARIOUS KNAPSACK

#include<iostream>
using namespace std;

class funOverloading
{
    public :
    int n;
    int knapsack(int W,int w[],int p[]);
    double knapsack(double W,double w[],double p[]);
    int knapsack(int W,int w[]);
    float Knapsack(int W,int w[],int p[],bool flag);
};

int funOverloading::knapsack(int W,int w[],int p[])
{

    for(int i=1 ; i<n ; i++)
    {
        int j;
        int temp = w[i];
        int temp1= p[i];
        //comparing with all elements from 0 to i-1 to find appropriate location 
        for(j=i-1 ; j>=0 && w[j]>temp ; j--)
        {
            //shifting to right
            w[j+1]=w[j];
            p[j+1]=p[j];
        }
        w[j+1]=temp;
        p[j+1]=temp1;
    }

    int output[n+1][W+1];
    int include , notInclude;

    for(int i=0;i<=n;i++)
    {
        output[i][0]=0;
    }
    for(int j=0;j<=W;j++)
    {
        output[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            notInclude = output[i-1][j];
            if(w[i-1] <= j)
            {
                include = p[i-1] + output[i-1][j-w[i-1]];
                output[i][j]= include >= notInclude? include:notInclude;
            }
            else
            {
                output[i][j]=notInclude;
            } 
        }
    }
    
    return output[n][W];
}

double funOverloading::knapsack(double W,double w[],double p[])
{
    int arr[n];
 
    for(int i=1 ; i<n ; i++)
    {
        int j;
        double temp = w[i];
        double temp1= p[i];
        //comparing with all elements from 0 to i-1 to find appropriate location 
        for(j=i-1 ; j>=0 && w[j]>temp ; j--)
        {
            //shifting to right
            w[j+1]=w[j];
            p[j+1]=p[j];
        }
        w[j+1]=temp;
        p[j+1]=temp1;
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=(w[i]+1)/1;
    }
    
    int x = (W+1)/1.0;
    double output[n+1][x+1];
    double include , notInclude;

    for(int i=0;i<=n;i++)
    {
        output[i][0]=0;
    }
    for(int j=0;j<=x;j++)
    {
        output[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            notInclude = output[i-1][j];
            if(arr[i-1] <= j)
            {
                include = p[i-1] + output[i-1][j-arr[i-1]];
                output[i][j]= include >= notInclude? include:notInclude;
            }
            else
            {
                output[i][j]=notInclude;
            } 
        }
    }
    
    return output[n][x];
}

int funOverloading::knapsack(int W,int w[])
{
    for(int i=1 ; i<n ; i++)
    {
        int j;
        int temp = w[i];
        //comparing with all elements from 0 to i-1 to find appropriate location 
        for(j=i-1 ; j>=0 && w[j]>temp ; j--)
        {
            //shifting to right
            w[j+1]=w[j];
        }
        w[j+1]=temp;
    }

    int totalitems=0,totalWeight=0;
    for(int i=0;i<n;i++)
    {
        totalWeight+=w[i];
        if(totalWeight<=W)
        {
            totalitems+=1; 
        }
        else
        {
            break; 
        }
    }
    return totalitems;

}

float funOverloading::Knapsack(int W,int w[],int p[],bool flag)
{

    double ratio[n];
    for(int i=0;i<n;i++)
    {
        ratio[i] = p[i]*1.0/w[i]*1.0;
    }

    int i ;
    for(i=1 ; i<n ; i++)
    {
        int j;
        double temp = ratio[i];
        int temp1= w[i];
        int temp2= p[i];
        //comparing with all elements from 0 to i-1 to find appropriate location 
        for(j=i-1 ; j>=0 && ratio[j]>temp ; j--)
        {
            ratio[j+1]=ratio[j];//shifting to right
            w[j+1]=w[j];
            p[j+1]=p[j];
        }
        ratio[j+1]=temp;
        w[j+1]=temp1;
        p[j+1]=temp2;
    }
    
    double total=0.0;

    for(int i=n-1;i>=0;i--)
    {
        if(W>0)
        {
            if(w[i] < W)
            {
                total = total+p[i];
                W = W - w[i];
            }
            else
            {
                total = total + (W*1.0/w[i])*1.0*p[i];
                return total;
            }
        }
        else
        {
            break;
        }
    }
    return total;
}

int main()
{
    funOverloading funOver;

    int n,W;

    cout<<"\nEnter the capacity of bag : ";
    cin>>W;

    cout<<"\nEnter the no. of items : ";
    cin>>n;
    funOver.n=n;

    int Iweight[n],Iprofit[n]; 
    double Dweight[n],Dprofit[n];

    int i;

    cout<<"\nEnter the weight of "<<n<<" int items : ";
    for(i=0;i<n;i++)
    {
        cin>>Iweight[i];
    }
 
    cout<<"\nEnter the profit of respective weights : ";
    for(i=0;i<n;i++)
    {
        cin>>Iprofit[i];
    }

    double DW;
    cout<<"\nEnter the capacity of bag(float) : ";
    cin>>DW;

    cout<<"\nEnter the weight of "<<n<<" double items : ";
    for(i=0;i<n;i++)
    {
        cin>>Dweight[i];
    }
 
    cout<<"\nEnter the profit of respective weights : ";
    for(i=0;i<n;i++)
    {
        cin>>Dprofit[i];
    }


    cout<<"\nTotal profit using dynamic prog in 0-1 Knapsack(int)    : "<<funOver.knapsack(W,Iweight,Iprofit);

    cout<<"\nTotal profit using dynamic prog in 0-1 Knapsack(double) : "<<funOver.knapsack(DW,Dweight,Dprofit);

    cout<<"\nMax items in bag knapsack varint (maximize items)       : "<<funOver.knapsack(W,Iweight);

    cout<<"\nTotal profit using greedy in fractional Knapsack(int)   : "<<funOver.Knapsack(W,Iweight,Iprofit,1);

    return 0;
}
