//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int fun(vector<int>&arr, int i,vector<int> &dp)
	{
	    if(i==0)
	    return arr[i];
	    if(i<0)
	    return 0;
	    if(dp[i]!=-1)
	    return dp[i];
	    
	   
	    int l = arr[i] + fun(arr,i-2,dp);
	    int r = fun(arr,i-1,dp);
	    
	    dp[i] = max(l,r);
	    return max(l,r);
	}
	
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return fun(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends