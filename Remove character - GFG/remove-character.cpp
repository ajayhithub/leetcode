//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        
        unordered_map<char,int> mpp;
        int n = string2.length();
        int nn = string1.length();
        
        for(int i=0;i<n;i++)
        {
            mpp[string2[i]]++;
        }
        
        string ans = "";
        for(int i=0;i<nn;i++)
        {
            if(mpp[string1[i]]==0)
            ans += string1[i];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends