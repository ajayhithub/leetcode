//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int fun(int arr[], int n,int i, int sum, int mod,vector<vector<int>> &dp)
	{
	 
	    if(i==n)
	    {
	        if(sum==0)
	        return 1;
	        else
	        return 0;
	    }
	    if(dp[i][sum]!=-1)
	    return dp[i][sum];
	 
	    
	    int l = fun(arr,n,i+1,sum,mod,dp);
	    int r = 0;
	    if(arr[i]<=sum)
	    r = fun(arr,n,i+1,sum-arr[i],mod,dp);
	    
	    dp[i][sum] = (l+r)%mod;
	    return (l+r)%mod;   
	}
	
	int fun1(int arr[], int n, int sum)
	{
	     int mod = pow(10,9)+7;
         vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
         dp[n][0]=1;
         
         for(int i=n-1;i>=0;i--)
         {
             for(int t=0;t<=sum;t++)
             {   
                 int tak = 0;
                 if(arr[i]<=t)
                 {
                   tak = dp[i+1][t-arr[i]]%mod;          
                 //  dp[i][t]=(dp[i][t]+dp[i+1][t-arr[i]])%mod;
                 }
                  int non  = dp[i+1][t]%mod;
                // dp[i][t]=(dp[i][t]+dp[i+1][t])%mod;   
                
                dp[i][t] = (non+tak)%mod;
             }
          
         }
         
         return dp[0][sum];
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int mod = pow(10,9)+7;
      //  vector<vector<int>> dp(n,vector<int>(sum+1,-1));
     //   return fun(arr,n,0,sum,mod,dp);
        
     return fun1(arr,n,sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends