//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
       int l = 0;
       int r = 0;
       int i = 0;
        int j = N-1;
        while(i<=j)
        {
            if(l<r)
            {
              l+=A[i];
              i++;
            }
            else if(l>r)
            {
              r+=A[j];
              j--;
            }
            else if(i==j && l==r)
            {
                return i+1;
            }
            else
            {
                l+=A[i];
                r+=A[j];
                i++;
                j--;
            }
               
        }
        
        return -1;
      
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends