#include<bits/stdc++.h>
using namespace std;

void word_break(vector<string> v,string s1,string out)
{
	if(s1.size()==0)
	{
		cout<<out<<endl;
		return;
	}
	
	for(int i=1;i<=s1.size();i++)
	{
		string prefix=s1.substr(0,i);
		
		if( find(v.begin(),v.end(),prefix) != v.end())
			word_break(v,s1.substr(i),out + " " + prefix);
	}
}

bool wordbreak(vector<string> v,string s1)
{
	if(s1.size()==0)
	{
		return true;
	}
	
	for(int i=1;i<=s1.size();i++)
	{
		string prefix=s1.substr(0,i);
		
		if( find(v.begin(),v.end(),prefix)!= v.end() && wordbreak(v,s1.substr(i)))
			return true;
	}
}

bool dynamic_wordbreak(vector<string> const &dict, string str, vector<int> &lookup)
{
    int n = str.size();
    if (n == 0)
        return true;
    if (lookup[n] == -1)
    {
        lookup[n] = 0;
        for (int i = 1; i <= n; i++)
        {
           
            string prefix = str.substr(0, i);
            if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                dynamic_wordbreak(dict, str.substr(i), lookup))
            {
                return lookup[n] = 1;
            }
        }
    }
    return lookup[n];
}

 bool wordBreak(string s, vector<string>& wordDict) {
        
        if(wordDict.size()==0)
            return false;
        vector<bool> dp(s.size()+1,false);
        
        dp[0]=true;
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word=s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),word)!=wordDict.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];    
    }
    
    
int main()
{
	int n;
	cin>>n;
	vector<string> v(n);
	
	for(int i=0;i<n;i++)
		cin>>v[i];
		
	string s1;
	cin>>s1;
	vector<int> l(s1.size()+1,-1);
	word_break(v,s1,"");
	cout<<wordbreak(v,s1)<<endl;
	cout<<dynamic_wordbreak(v,s1,l);
	
}
