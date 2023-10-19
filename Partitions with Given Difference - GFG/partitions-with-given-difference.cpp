//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int fun(vector<int>&arr, int n,int i, int sum, int mod,vector<vector<int>> &dp)
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
  
	int fun1(vector<int>&arr, int n, int sum)
	{
	     int mod = pow(10,9)+7;
         vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
         dp[n][0]=1;
         
         for(int i=n-1;i>=0;i--)
         {
             for(int t=0;t<=sum;t++)
             {   
                 int tak = 0;
                 if(arr[i] <= t)
                 {
                   tak = dp[i+1][t-arr[i]];          
                 }
                 int non  = dp[i+1][t];
                
                 dp[i][t] = (non+tak)%mod;
             }
         }
         
         return dp[0][sum];
	}
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
         int  mod = pow(10,9)+7;
         
        int tsum = 0;
        for(int i=0;i<n;i++)
        tsum += arr[i];
        // cout<<tsum<<endl;
        if((tsum-d)%2!=0)return 0;
        int target=(tsum-d)/2;
        if(target<0)return 0;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return fun1(arr,n,target);
        
        // return fun1(n,d,arr,mod);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends