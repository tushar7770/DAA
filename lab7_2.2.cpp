//CS20B1098 TUSHAR PANJETA
//dynamic programmaxg for optimal binary search tree

#include<iostream>
using namespace std;


class bst
{
    public :
    int data;
    int freq;

    void heapSort(bst b[],int n);
    void heapify(bst b[],int sizee , int i);

    int costOBST(bst b[],int n);
 
};

void bst::heapSort(bst b[],int n)
{
    for(int i = n/2-1 ; i>=0 ; i--)
    {
        heapify(b,n,i);
    }
    
    for(int i = n-1 ; i>0 ; i--)
    {
        swap(b[0].freq,b[i].freq);
        swap(b[0].data,b[i].data);
        heapify(b,i,0);
    }


}

void bst::heapify(bst b[],int sizee , int i)
{
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && b[left].data>b[max].data)
    {
       max = left;
    }

    if(right < sizee && b[right].data>b[max].data)
    {
       max = right;
    }

    if(max != i)
    {
        swap(b[i].freq,b[max].freq);
        swap(b[i].data,b[max].data);
        heapify(b,sizee ,max);
    }
}

int bst::costOBST(bst b[],int n)
{
    int output[n][n];
 
    int i, j, k, g,f;
  
    for (g = 0; g < n; g++)
    {
        for (i = 0,j = g; j < n; i++,j++)
        {
            if(g==0)
            {
                output[i][j]=b[i].freq;
            }
            else if(g==1)
            {
                int c1 = b[i].freq + 2*b[j].freq;
                int c2 = b[j].freq + 2*b[i].freq;
                output[i][j]= c1>=c2? c2:c1;
            }
            else
            {
                int allFreq=0;
                for(f=i;f<=j;f++)
                {
                    allFreq+=b[f].freq;
                }

                int min=INT_MAX;
                for(k=i;k<=j;k++)
                {
                    int costleft = k==i? 0:output[i][k-1];
                    int costright = k==j? 0:output[k+1][j];
                    
                    int total = costleft + costright + allFreq;

                    if(total<min)
                    {
                        min=total;
                    }
                }
                output[i][j]=min;
            }
            
        }
    }
    return output[0][n-1];
    
}


int main()
{
    int n, i;
    cout<<"\nEnter the no. of nodes : ";
    cin>>n;

    bst b1[n];

    cout<<"\nEnter the data of "<<n<<" nodes : ";
    for(i=0;i<n;i++)
    {
        cin>>b1[i].data;
    }
    cout<<"\nEnter respective frequencies : ";
    {
        for(i=0;i<n;i++)
        {
            cin>>b1[i].freq;
        }
    }
    b1[0].heapSort(b1,n);

    cout<<"\n Min Cost : "<<b1[0].costOBST(b1,n);
    return 0;
}
