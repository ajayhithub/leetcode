//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int ans = 0;
        int t = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            ans++;
        }
        
        if(ans == n)
        return 0;
        else if(ans == 0)
        return -1;
        
        
        ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0 && arr[i+1]==0 && i<n-1)
            {
              ans++;
            }
          
        }
   
        if(arr[n-1]!=0)
        return ans+1;
        else 
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends