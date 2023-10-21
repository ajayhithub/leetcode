//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long int fun(int coins[], int i, int sum, vector<vector<long long int>> &dp)
  {
      if(i==0)
      {
          if(sum%coins[0] == 0)
          return 1;
          else
          return 0;
      }
      if(dp[i][sum]!=-1)
      return dp[i][sum];
      
      long long int non = fun(coins,i-1,sum,dp);
      long long int tak = 0;
      if(coins[i]<=sum)
      tak = fun(coins,i,sum-coins[i], dp);
       
       dp[i][sum] = non+tak;
       return non+tak;
  }
  
  long long int fun1(int coins[], int i, int sum)
  {
       int N = i;
      vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,0));
     
      for(int t=0;t<=sum;t++)
      {
          if(t%coins[0]==0)
          dp[0][t] = 1;
      }
      
      for(int i=1;i<N;i++)
      {
          for(int t=0;t<=sum;t++)
          {
               long long int non = dp[i-1][t];
               long long int tak = 0;
               if(coins[i]<=t)
               tak = dp[i][t-coins[i]];
       
               dp[i][t] = non+tak;
          }
      }
      
      return dp[N-1][sum];
  }
  
    long long int count(int coins[], int N, int sum) {

        // code here
        // vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
        // return fun(coins,N-1,sum, dp);
        
        return fun1(coins,N,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends