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


class person{
	private:	
		string name,britecamp_id;
		string father,mother;
		string father_in_law,mother_in_law,son_in_law;
		string husband,wife;
		
		vector<string> sister;
		vector<string> brother;	
		vector<string> children;		
	public:
// function for storing data	
	void store_mother_in_law(string mother_in_law_id)
		{
			this->mother_in_law=mother_in_law_id;
		}
		
	void store_father_in_law(string father_in_law_id)
		{
			this->father_in_law=father_in_law_id;
		}
		
	void store_son_in_law(string son_in_law_id)
		{
			this->son_in_law=son_in_law_id;
		}
	
	void store_wife(string wife_id)
		{
			this->wife=wife_id;
		}
	
	void store_husband(string husband_id)
		{
			this->husband=husband_id;
		}
	
	void store_brother(string brother_id)
		{
			this->brother.push_back(brother_id);
		}
		
	void store_mother(string mother_id)
		{
			this->mother=mother_id;
		}
	
	void store_father(string father_id)
		{
			this->father=father_id;
		}
	
	void store_child(string child_id)
		{
			this->children.push_back(child_id);
		}
	
	string getname()
		{
			return this->name;
		}
		
	string get_id()
		{
			return this->britecamp_id;
		}

//function to store
	
	void show_child();
	void show_husband();
	void show_wife();
	void show_brother();
	void show_mother();
	void show_father();
	void show_father_in_law();
	void show_mother_in_law();
	void show_son_in_law();
	
		
	void read_data()
		{
				cout<<"\nEnter person Name:";
				cin>>this->name;
				cout<<"\nEnter person britecamp_id:";
				cin>>this->britecamp_id;				
		}	

	bool operator<(const person& t) const
	{ 
		return (this->britecamp_id < t.britecamp_id); 
	} 
};

map<string,person> parent;

void person::show_mother_in_law()
	{
		if(mother_in_law.size()!=0)
		{
		cout<<"\n britecamp-id : "<<mother_in_law;
		cout<<"\n Name : "<<parent[mother_in_law].getname();
		cout<<"\n Relation : Mother-in_law"<<endl;
		
		}
	}
		
void person::show_father_in_law()
	{
		if(father_in_law.size()!=0)
		{
		cout<<"\n britecamp-id : "<<father_in_law;
		cout<<"\n Name : "<<parent[father_in_law].getname();
		cout<<"\n Relation : Father-in_law"<<endl;
		}
	}
	
void person::show_son_in_law()
	{
		if(son_in_law.size()!=0)
		{
		cout<<"\n britecamp-id : "<<son_in_law;
		cout<<"\n Name : "<<parent[son_in_law].getname();
		cout<<"\n Relation : Son-in_law"<<endl;
		}
	}

void person::show_wife()
	{
		if(wife.size()!=0)
		{
		cout<<"\n britecamp-id : "<<wife;
		cout<<"\n Name : "<<parent[wife].getname();
		cout<<"\n Relation : Wife"<<endl;
		}
	}

void person::show_husband()
	{
		if(husband.size()!=0)
		{
		cout<<"\n britecamp-id : "<<husband;
		cout<<"\n Name : "<<parent[husband].getname();
		cout<<"\n Relation : Husband"<<endl;
		}
	}

void person::show_brother()
	{
		int n=brother.size();
		cout<<"brother "<<n<<endl;
	if(n!=0)
		{
			for(int i=0;i<n;i++)
			{
				cout<<"\n britecamp-id : "<<brother[i];
				cout<<"\n Name : "<<parent[brother[i]].getname();
				cout<<"\n Relation : Brother"<<endl;
			}
		}
	}
	
void person::show_mother()
	{
		if(mother.size()!=0)
		{
		cout<<"\n britecamp-id : "<<mother;
		cout<<"\n Name : "<<parent[mother].getname();
		cout<<"\n Relation : Mother"<<endl;
		}
	}

void person::show_father()
	{
		if(father.size()!=0)
		{
		cout<<"\n britecamp-id : "<<father;
		cout<<"\n Name : "<<parent[father].getname();
		cout<<"\n Relation : Father"<<endl;
		}
	}

void person::show_child()
	{
		int n=children.size();
		cout<<"children "<<n<<endl;
	if(n!=0)
		{
			for(int i=0;i<n;i++)
			{
				cout<<"\n britecamp-id : "<<children[i];
				cout<<"\n Name : "<<parent[children[i]].getname();
				cout<<"\n Relation : Brother"<<endl;
			}
		}

	}

class tree
{
 
public:
	
	void write_rec();
	void read_rec(); 
	void search_rec();   
	void show_rec(string id);
};

void tree::write_rec()
{
	cout<<"\nEnter first person information: "<<endl;
	person p1;
	p1.read_data();
	parent[p1.get_id()]=p1;
	
	cout<<"\n.................................."<<endl;
	
	cout<<"\nEnter second person information: "<<endl;
	person p2;
	p2.read_data();
	parent[p2.get_id()]=p2;
	
	cout<<"\n.................................."<<endl;
	
	cout<<"\nEnter the relation between them: ";
	string relation;
	cin>>relation;	
	
	if(relation=="FATHER")
	{
		parent[p1.get_id()].store_child(p2.get_id());
		parent[p2.get_id()].store_father(p1.get_id());
	}
	
	else if(relation=="MOTHER")
	{
		parent[p1.get_id()].store_child(p2.get_id());
		parent[p2.get_id()].store_mother(p1.get_id());
	}
	
	else if(relation=="BROTHER" || relation=="SISTER")
	{
		parent[p1.get_id()].store_brother(p2.get_id());
		parent[p2.get_id()].store_brother(p1.get_id());
	}
	
	else if(relation=="HUSBAND" || relation=="wife")
	{
		parent[p1.get_id()].store_wife(p2.get_id());
		parent[p2.get_id()].store_husband(p1.get_id());
	}
	
	else if(relation=="FATHER-IN-LAW" || relation=="FATHER-IN-LAW")
	{
		if(relation=="FATHER-IN-LAW")
		{
		parent[p1.get_id()].store_son_in_law(p2.get_id());
		parent[p2.get_id()].store_father_in_law(p1.get_id());
		}
		else
		{
		parent[p1.get_id()].store_son_in_law(p2.get_id());
		parent[p2.get_id()].store_mother_in_law(p1.get_id());	
		}
	}
	
	else if(relation=="CHILDREN")
	{
		parent[p1.get_id()].store_father(p2.get_id());
		parent[p2.get_id()].store_child(p1.get_id());
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
{
	parent[id].show_child();
	parent[id].show_husband();
	parent[id].show_wife();
	parent[id].show_brother();
	parent[id].show_mother();
	parent[id].show_father();
	parent[id].show_father_in_law();
	parent[id].show_mother_in_law();
	parent[id].show_son_in_law();	
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
