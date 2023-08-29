//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string removeConsonants(string s){
    //complete the function heredef removeConsonants(s):
    
      string ans = "";
      int n = s.length();
       for(int i=0;i<n;i++)
       {
           if(s[i]=='a' || s[i]=='e' ||  s[i]=='i' ||  s[i]=='o' ||  s[i]=='u' ||
           s[i]=='A' || s[i]=='E' ||  s[i]=='I' ||  s[i]=='O' ||  s[i]=='U')
           ans += s[i];
       }
       
       if(ans == "")
       return "No Vowel";
       else
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsonants(s) << "\n";
    }
return 0;
}
// } Driver Code Ends