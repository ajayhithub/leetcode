//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int fun1(int n, int m, string s1, string s2)
    {
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
             {
                 int l = 0;
                 if(s1[i-1]==s2[j-1])
                 l = 1+dp[i-1][j-1];
        
                 int r = max(dp[i][j-1],dp[i-1][j]);
                 dp[i][j] = max(l,r);
             }
         }
         
         return dp[n][m];
    }
  
    int countMin(string str){
    //complete the function here
    string rev = str;
    reverse(rev.begin(),rev.end());
    
    int ans = fun1(str.length(),str.length(),str,rev);
     return str.length()-ans;
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends