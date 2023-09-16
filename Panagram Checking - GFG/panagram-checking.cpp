//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        
        int cnt = 0;
        int n = str.length();
        set<char> ss;
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            ss.insert(str[i]);
            else if(str[i]>='A' && str[i]<='Z')
            {
                ss.insert(str[i]+32);
            }
        }
        
        if(ss.size() == 26)
        return true;
        else
        return false;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends