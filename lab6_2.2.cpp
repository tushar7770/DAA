//CS20B1098 TUSHAR PANJETA
//greedy strategy for optimal binary search tree

#include<iostream>
using namespace std;


class bst
{
    public :
    int data;
    int freq;

    void heapSort(bst b[],int n);
    void heapify(bst b[],int sizee , int i);
 
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
    int min = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < sizee && b[left].freq<b[min].freq)
    {
       min = left;
    }

    if(right < sizee && b[right].freq<b[min].freq)
    {
       min = right;
    }

    if(min != i)
    {
        swap(b[i].freq,b[min].freq);
        swap(b[i].data,b[min].data);
        heapify(b,sizee ,min);
    }
}

class Node 
{
    public:
    int data;
    int f;
        
    Node * left;
   Node * right;

    int depth(Node* root, int x)
    {

        if (root == NULL)
            return 0;

        int d = 0;

        if ((root->data == x) || (d = depth(root->left, x)) >= 1  || (d = depth(root->right, x)) >= 1)
            return d + 1;
    
        return d;
    }

    Node(int value,int fr) 
    {
        data = value;
        f=fr;
        
        Node * left = NULL;
        Node * right = NULL;
    }

    Node * insertNode(Node * root, int value,int fr) 
    {
        if(root==NULL) 
        {
            return new Node(value,fr);
        }
        else if(value < root->data) 
        {
            root->left = insertNode(root->left, value,fr);
        }
        else if(value > root->data) 
        {
            root->right = insertNode(root->right, value,fr);
        }
        return root;
    }

};


int main()
{
    int c=0;

    Node*root=NULL;
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

    for(i=0;i<n;i++)
    {
        root=root->insertNode(root,b1[i].data,b1[i].freq);
    }

    for(i=0;i<n;i++)
    {
        c=c+ (root->depth(root,b1[i].data)) * b1[i].freq;
    }

    cout<<"\n Cost : "<<c;
    return 0;
}
