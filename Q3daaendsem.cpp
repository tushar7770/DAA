//CS20B1098 TUSHAR PANJETA
// 0,1/2,1 KNAPSACK
#include <iostream>
using namespace std;


double knapSackRec(int W, double wt[],double profit[], int i, double **dp)// Returns the profitue of maximum profit
{
    //base case
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W)
    {
        
        if (wt[i] / 2 > W)  //checking for 1/2 of weight case
        {
            dp[i][W] = knapSackRec(W, wt,profit, i - 1,dp);
        }
        else
        {
            dp[i][W] = max(profit[i] / 2 + knapSackRec(W - wt[i] / 2,wt, profit,i - 1, dp),knapSackRec(W, wt, profit,i - 1, dp));
        }

        return dp[i][W];
    }
    else
    {
        //Store profit in a table before return
        //finding maximum b/W half anf full profit of objects.
        dp[i][W] = max(profit[i] / 2 + knapSackRec(W - wt[i] / 2,wt, profit,i - 1, dp),max(profit[i] + knapSackRec(W - wt[i],wt, profit,i - 1, dp),knapSackRec(W, wt, profit,i - 1, dp)));

        
        return dp[i][W];//Returning profit after storing
    }
}

double knapSack(int W, double wt[], double profit[], int n)
{
    double **dp;
    dp = new double *[n];

    
    for (int i = 0; i < n; i++)// creating the table dynamically
    {
        dp[i] = new double[W + 1];
    }

    for (int i = 0; i < n; i++)//setting all value = -1
    {
        for (int j = 0; j < W + 1; j++)
        {
            dp[i][j] = -1;
        }
        
    }
        
    return knapSackRec(W, wt, profit, n - 1, dp);
}

int main()
{
    int W;
    cout << "Enter capacity of bag:";
    cin >> W;

    int n;
    cout << "Enter the no. of items :";
    cin >> n;

    double wt[n], profit[n];
    cout << "Enter weight of items:";
    for (int i = 0; i < n; i++)
    {
        cin >>wt[i];
    }
        
    cout << "Enter profits of items:";
    for (int i = 0; i < n; i++)
    {
        cin >>profit[i];
    }

    cout << knapSack(W, wt, profit, n);

    return 0;
}