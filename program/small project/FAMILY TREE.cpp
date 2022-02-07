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

 
class person
{
 
public:
	map<string,string> parent;
	int level;
	string a,b;
	void write_rec();
	void read_rec(); 
	void search_rec();  
};


void person::write_rec()
{
    cout<<"\nEnter Elder person name: ";
    cin>>a;
    cout<<"\nEnter Older person name: ";
    cin>>b;
    parent[b]=a;
    if(parent[a]=="")parent[a]=a;
    cout<<"\n.........data stored........"<<endl;
    cout<<endl;
}

void person::search_rec()
{
	string x,y;
    cout<<"\nEnter first person name: ";
    cin>>x;
    cout<<"\nEnter second person name: ";
    cin>>y;
    string t1=x,t2=y;
    int x1=0,y1=0;
    while(x!=parent[x]){
	x=parent[x];
	x1++;
	}
    while(y!=parent[y])
	{
	y1++;
	y=parent[y];
   }
   
    if(x==y)cout<<"They have relation and "<<t1<<" is "<<y1-x1<<" level elder than "<<t2;
    else cout<<"They don't have relation in between them";
    cout<<endl;
}
int main()
{
    person A;
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
    else cout<<"\nEnter correct choice"<<endl;
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}
