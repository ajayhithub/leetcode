//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

 Node* fun(int in[], int post[], int &ind, int inS, int inE)
 {
     if(ind<0 || inS>inE)
     return NULL;
     
     Node* node = new Node(post[ind--]);
    //  cout<<node->data<<endl;
     int len = 0;
     for(int i=inS;i<=inE;i++)
     {
         if(in[i] == node->data)
         {
             len = i;
             break;
         }
     }
     
     
     node->right = fun(in,post,ind,len+1,inE);
     node->left = fun(in,post,ind,inS,len-1);
     
     return node;
 }

Node *constructTree (int post[], int size)
{
//code here
  int in[size];
  for(int i=0;i<size;i++)
  {
      in[i] = post[i];
  }
  sort(in,in+size);
  
    int ind = size-1;
    return fun(in,post,ind,0,size-1);
    
}