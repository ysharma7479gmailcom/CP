#include<iostream>
#include<fstream>
#include<cstdlib>
#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using namespace std;
map<string,int> m;

class person{
	private:	
		string name,email;
		int age,level;
	public:
		void setname(string s)
		{
			this->name= s;
		}
		void setemail(string mail)
		{
			this->email=mail;
		}
		void setage(int ag)
		{
		this->age=ag;
		}
		void setlevel(int lev)
		{
			this->level=lev;
		}
		string getname()
		{
			return name;
		}
		string getemail()
		{
			return email;
		}
		int getage()
		{
			return age;
		}
		int getlevel()
		{
			return level;
		}
		void read_data()
		{
				cout<<"\nEnter person information: "<<endl;
				cout<<"\nEnter First person Name:";
				cin>>this->name;
				cout<<"\nEnter First person Age:";
				cin>>this->age;
				cout<<"\nEnter First person email-id:";
				cin>>this->email;
				this->level=0;	
		}	
};

class tree
{
 
public:
	map<string,string> parent;
	void write_rec();
	void read_rec(); 
	void search_rec();   
};

void tree::write_rec()
{
	person p1;
	p1.read_data();
	person p2;
	p2.read_data();
	p1.setlevel(m[p1.getemail()]);
	p2.setlevel(m[p2.getemail()]);
	
   cout<<"\nEnter Relation Level Between Them:";
   int relation;
   cin>>relation;
   
   p2.setlevel(p1.getlevel()-relation);
   
   map<string,int> ::iterator it=m.begin();
   for( ; it!=m.end();it++)
   {
   	string y=it->first;
   	 while(y!=parent[y]){
	y=parent[y];
	}
		if(y==p2.getemail())
		{
			m[it->first]=p2.getlevel()+m[it->first];
		}	
   }
      
   parent[p2.getemail()]=p1.getemail();
   
   if(parent[p1.getemail()].size()==0)parent[p1.getemail()]=p1.getemail();
   m[p2.getemail()]=p2.getlevel();
   m[p1.getemail()]=p1.getlevel();
   cout<<"\n.........data stored........"<<endl;
    cout<<endl;
}

void tree::search_rec()
{
	person p1;
    p1.read_data();
	person p2;
	p2.read_data();
	p1.setlevel(m[p1.getemail()]);
	p2.setlevel(m[p2.getemail()]);
	
    person t1=p1,t2=p2;
    string x=p1.getemail(),y=p2.getemail();
    while(x!=parent[x]){
	x=parent[x];
	}
    while(y!=parent[y])
	{
	y=parent[y];
   }
   
    if(x==y)
	{
		if(p1.getlevel()==p2.getlevel())cout<<"They have relation and both are of same level";
	else cout<<"They have relation and "<<t1.getname()<<" is "<<p1.getlevel()-p2.getlevel()<<" level older than "<<t2.getname();
	}
    else cout<<"They don't have relation in between them";
    cout<<endl;
}
int main()
{
    tree A;
    int choice;
   string temp;
    while(true)
    {
    	 cout<<"***FAMILY TREE APPLICATION FOR KIDS***"<<endl;
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Search Record from file"<<endl;
        cin>>temp;
        if(temp.size()==1 && (temp=="1" || temp=="2"))
    {
	   if(temp=="1")choice=1;else choice=2;
        switch(choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.search_rec();
            break;
        }
    }
    else cout<<"\nEnter incorrect choice"<<endl;
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}
