#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class trie
{
	public:
		bool isend;
		unordered_map<char,trie*> m;
};
trie* getnew()
{
	trie *temp= new trie;
	
	temp->isend=false;
	
	return temp;
}

void insert(trie *t,string s)
{
	if(t==nullptr)
		t=getnew();
	trie *c=t;
	for(int i=0;i<s.size();i++)
	{
		if(c->m[s[i]]==nullptr)
			c->m[s[i]]=getnew();
		c=c->m[s[i]];
		
	}
	c->isend=true;
}

bool search(trie *t,string s)
{
	if(t==nullptr)
		return false;
		trie *c=t;
	for(int i=0;i<s.size();i++)
	{
		if(c->m[s[i]]!=nullptr)
			c=c->m[s[i]];
		else return false;
	}
	return c->isend;
}
int main()
{
	trie *head=getnew();
	
	insert(head, "hello");
    cout << search(head, "hello") << " ";       // print 1
 
    insert(head, "helloworld");
    cout << search(head, "helloworld") << " ";  // print 1
 
    cout << search(head, "helll") << " ";       // print 0 (Not present)
 
    insert(head, "hell");
    cout << search(head, "hell") << " ";        // print 1
 
    insert(head, "h");
    cout << search(head, "h") << endl;      
}
