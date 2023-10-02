//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string ss = str;
        sort(ss.begin(),ss.end());
        int p = 0;
        for(int i=0;i<n;i++)
        {
            if(ss[i]>='a')
            {
                p = i;
                break;
            }
        }
        string ans;
       
       int b = 0;
       for(int i=0;i<n;i++)
       {
           if(str[i]>='a')
           {
               ans += ss[p];
               p++;
           }
           else
           {
               ans += ss[b];
               b++; 
           }
       }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends