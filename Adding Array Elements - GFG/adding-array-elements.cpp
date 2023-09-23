//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
      //  sort(arr,arr+n);
        priority_queue<int, vector<int>, greater<int>> pq;
       for(int i=0;i<n;i++)
       {
           pq.push(arr[i]);
       }
       
       int ans = 0;
       while(!pq.empty())
       {
          if(pq.top()>=k)
          {
              return ans;
          }
          if(pq.size()==1 && pq.top()<k)
          {
             return -1;
          }
          int a = pq.top();
          pq.pop();
          int b = pq.top();
          pq.pop();
          ans++;
          pq.push(a+b);
       }
       
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends