#include<bits/stdc++.h>

using namespace std;

map<string,string> name,britecamp_id;
map<string,string> father,mother;
map<string,string> father_in_law,mother_in_law,son_in_law;
map<string,string> husband,wife;
map<string, vector<string> > sister;
map<string, vector<string> > brother;	
map<string, vector<string> > children; 
class tree
{ 
public:	
	void write_rec(); 
	void search_rec();   
	void show_rec(string id);
};
tree A;
map<string,int> rec;
void show_mother_in_law(string id)
	{
		if( rec[mother_in_law[id]]==0 && mother_in_law[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<mother_in_law[id];
		cout<<"\n\t\t Name : "<<name[mother_in_law[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Mother-in_law"<<endl;
		rec[mother_in_law[id]]=1;
		A.show_rec(mother_in_law[id]);
		}
		return;
	}
		
void show_father_in_law(string id)
	{
		if(rec[father_in_law[id]]==0 && father_in_law[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<father_in_law[id];
		cout<<"\n\t\t Name : "<<name[father_in_law[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Father-in_law"<<endl;
		rec[father_in_law[id]]=1;
		A.show_rec(father_in_law[id]);
		}
	}
	
void show_son_in_law(string id)
	{
		if(rec[son_in_law[id]]==0 && son_in_law[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<son_in_law[id];
		cout<<"\n\t\t Name : "<<name[son_in_law[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Son-in_law"<<endl;
		rec[son_in_law[id]]=1;
		A.show_rec(son_in_law[id]);
		}
	}

void show_wife(string id)
	{
		if(rec[wife[id]]==0 && wife[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<wife[id];
		cout<<"\n\t\t Name : "<<name[wife[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Wife"<<endl;
		rec[wife[id]]=1;
		A.show_rec(wife[id]);
		}
	}

void show_husband(string id)
	{
		if(rec[husband[id]]==0 && husband[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<husband[id];
		cout<<"\n\t\t Name : "<<name[husband[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Husband"<<endl;
		rec[husband[id]]=1;
		A.show_rec(husband[id]);
		}
	}

void show_brother(string id)
	{
		int n=brother[id].size();
	
			for(int i=0;i<n;i++)
			{
				if(rec[brother[id][i]]==0)
				{
				cout<<"\n\t\t britecamp-id : "<<brother[id][i];
				cout<<"\n\t\t Name : "<<name[brother[id][i]];
				cout<<"\n\t\t Relation : "<<name[id]<<"'s Brother"<<endl;
				rec[brother[id][i]]=1;
		        A.show_rec(brother[id][i]);
		    	}
		    	
			}
	
	}
void show_sister(string id)
	{
		int n=sister[id].size();
	
			for(int i=0;i<n;i++)
			{
				if(rec[sister[id][i]]==0)
				{
				cout<<"\n\t\t britecamp-id : "<<sister[id][i];
				cout<<"\n\t\t Name : "<<name[sister[id][i]];
				cout<<"\n\t\t Relation : "<<name[id]<<"'s Sister"<<endl;
				rec[sister[id][i]]=1;
		        A.show_rec(sister[id][i]);
		    	}
			}
	
	}
	
void show_mother(string id)
	{
		if(rec[mother[id]]==0 && mother[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<mother[id];
		cout<<"\n\t\t Name : "<<name[mother[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Mother"<<endl;
		rec[mother[id]]=1;
		A.show_rec(mother[id]);
		}
	}

void show_father(string id)
	{
		if(rec[mother[id]]==0 &&father[id].size()!=0)
		{
		cout<<"\n\t\t britecamp-id : "<<father[id];
		cout<<"\n\t\t Name : "<<name[father[id]];
		cout<<"\n\t\t Relation : "<<name[id]<<"'s Father"<<endl;
		rec[father[id]]=1;
		A.show_rec(father[id]);
		}
	}

void show_child(string id)
	{
		int n=children[id].size();
	
			for(int i=0;i<n;i++)
			{
				if(rec[children[id][i]]==0)	
				{
				cout<<"\n\t\t britecamp-id : "<<children[id][i];
				cout<<"\n\t\t Name : "<<name[children[id][i]];
				cout<<"\n\t\t Relation : "<<name[id]<<"'s children"<<endl;
				rec[children[id][i]]=1;
		        A.show_rec(children[id][i]);
		    	}
			}
	}
	
void tree::write_rec()
{
	cout<<"\nEnter first person information: "<<endl;
	
	string t1,t2;
	cout<<"\nEnter person Name:";
	
	cin>>t1;
	cout<<"\nEnter person britecamp_id:";
	cin>>t2;
	name[t2]=t1;

	
	cout<<"\n.................................."<<endl;
	
	cout<<"\nEnter second person information: "<<endl;
	
	string x1,x2;
		cout<<"\nEnter person Name:";
		cin>>x1;
		cout<<"\nEnter person britecamp_id:";
		cin>>x2;
	name[x2]=x1;
	
	

	
	cout<<"\n.................................."<<endl;
	
	cout<<"\nEnter the relation between them: ";
	string relation;
	cin>>relation;
		
	transform(relation.begin(),relation.end(),relation.begin(),::toupper);
	
	if(relation=="FATHER")
	{
		father[x2]=t2;
		children[t2].push_back(x2);
	
		
	}
	
	else if(relation=="MOTHER")
	{
		mother[x2]=t2;
		children[t2].push_back(x2);
		
	}
	
	else if(relation=="BROTHER" || relation=="SISTER")
	{
		if(relation=="BROTHER")
		{
			brother[t2].push_back(x2);
			brother[x2].push_back(t2);
		}
		else
		{
			brother[t2].push_back(x2);
			sister[x2].push_back(t2);
		}
	}
	
	else if(relation=="HUSBAND" || relation=="wife")
	{
		if(relation=="HUSBAND")
		{
			husband[x2]=t2;
		    wife[t2]=x2;
		}
		else
		{
			husband[t2]=x2;
		    wife[x2]=t2;
		}
	}
	
	else if(relation=="FATHER-IN-LAW" || relation=="FATHER-IN-LAW")
	{
		if(relation=="FATHER-IN-LAW")
		{
		father_in_law[x2]=t2;
		son_in_law[t2]=x2;
		}
		else
		{
		mother_in_law[x2]=t2;
		son_in_law[t2]=x2;
		}
	}
	
	else if(relation=="CHILDREN")
	{
		father[t2]=x2;
		children[x2].push_back(t2);
	}
	else
	{
		cout<<"\n.........wrong relation input........"<<endl;
		return;
	}
	cout<<"\n.........data stored........"<<endl;
	return;	
}

void tree::show_rec(string id)
{rec[id]=1;
	show_father(id);
	show_mother(id);
	show_father_in_law(id);
 	show_mother_in_law(id);
 	show_wife(id);
 	show_husband(id);
 	show_brother(id);
	show_sister(id);
	show_child(id);	
	show_son_in_law(id);	
}

void tree::search_rec()
{
	cout<<"\nEnter person Britecamp-ID: ";
	string search_id;
	cin>>search_id;
	show_rec(search_id);	
}
int main()
{
    tree A;
	int choice;
    string temp;
    while(true)
    {
    	rec.clear();
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
       	cout<<endl;
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}
