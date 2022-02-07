#include<bits/stdc++.h>
using namespace std;
static int b;

int main()
{
	
	int r=0,m=0,c=0,tot=0;
	string input,q,e;
	while(1)
	{
	r=0;
	cout<<"\t\t\t\t\t ----------------------------------"<<endl;
	cout<<"\t\t\t\t\t Simple Vehicle Parking System"<<endl;
	cout<<"\t\t\t\t\t ----------------------------------"<<endl;
	cout<<"\t\t\t\t\t 1> BUS"<<endl;
	cout<<"\t\t\t\t\t 2> MOTORCYCLE"<<endl;
	cout<<"\t\t\t\t\t 3> RICKSHAW"<<endl;	
	cout<<"\t\t\t\t\t 4> SHOW RECORD"<<endl;
	cout<<"\t\t\t\t\t 5> DELETE RECORD"<<endl;
	cout<<"\t\t\t\t\t 6> SHOW PRIZE FOR PARKING"<<endl;
	cout<<"\t\t\t\t\t 7> SHOW TIME AND DATE"<<endl;	
	cout<<"\t\t\t\t\t 8> EXIT"<<endl;
	cout<<"\t\t\t\t\t ";	
	cin>>input;
	system("CLS");
	if(input=="1")
	{
		cout<<endl<<"\t\t\t\t\tBus is leaving(L) or Enter(E) : ";
		cin>>e;
		if(e=="E" || e=="e")
		{
		b++;
		c++;
		tot+=300;	
		cout<<endl;
		}
		if(e=="L" || e=="l") 
		{
			b--;
			c--;
		}
	}
	
	else if(input=="2")
	{
		cout<<endl<<"\t\t\t\t\tMotorCycle is leaving(L) or Enter(E) : ";
		cin>>e;
		if(e=="E" || e=="e")
		{
		m++;
		c++;
		tot+=200;	
		cout<<endl;
		}
		if(e=="L" || e=="l") 
		{
			m--;
			c--;
		}
	}
	
	else if(input=="3")
	{
		cout<<endl<<"\t\t\t\t\tRickshaw is leaving(L) or Enter(E) : ";
		cin>>e;
		if(e=="E" || e=="e")
		{
		r++;
		c++;
		tot+=100;	
		cout<<endl;
		}
		if(e=="L" || e=="l") 
		{
			r--;
			c--;
		}
	}
	else if(input=="4")
	{
		cout<<"\t\t\t\t\t--------------------------------------\t\t\t\t\t"<<endl;
		cout<<"\t\t\t\t\tTotal number of vehicle parked    : "<<c<<endl;
		cout<<"\t\t\t\t\tTotal number of buses parked      : "<<b<<endl;
		cout<<"\t\t\t\t\tTotal number of motorcycle parked : "<<m<<endl;
		cout<<"\t\t\t\t\tTotal number of rickshaw parked   : "<<r<<endl;
		cout<<"\t\t\t\t\tTotal amount                      : "<<tot<<endl;
		cout<<"\t\t\t\t\t--------------------------------------\t\t\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
		cout<<"\t\t\t\t\t\t"<<endl;
		while(1)
		{
			
			cin>>q;
			if(q=="1")
			{
			system("CLS");
			break;	
			}
			else 
			{
			cout<<"\t\t\t\t\t\t Wrong Input"<<endl;
			cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
			}
		}
		cout<<endl;
	}
	else if(input=="5")
	{
		tot=0;
		r=0;
		b=0;
		m=0;
		c=0;
		cout<<"\t\t\t\t\tRecord Deleted......."<<endl;
		cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
		
		while(1)
		{
			cout<<"\t\t\t\t\t\t"<<endl;
			cin>>q;
			if(q=="1")
			{
			system("CLS");
			break;	
			}
			else 
			{
			cout<<"\t\t\t\t\t\t Wrong Input"<<endl;
			cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
			}
		}
	}
	else if(input=="6")
	{
		cout<<"\t\t\t\t\t--------------------------------------\t\t\t\t\t"<<endl;
		cout<<"\t\t\t\t\t CHARGES FOR PARKING :"<<endl;
		cout<<"\t\t\t\t\t\t 1-> BUSES      : 300"<<endl;
		cout<<"\t\t\t\t\t\t 2-> MOTORCYCLE : 200"<<endl;
		cout<<"\t\t\t\t\t\t 3-> RICKSHAW   : 100"<<endl;
		cout<<"\t\t\t\t\t--------------------------------------\t\t\t\t\t"<<endl;
		cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
		
		while(1)
		{
			cout<<"\t\t\t\t\t\t"<<endl;
			cin>>q;
			if(q=="1")
			{
			system("CLS");
			break;	
			}
			else 
			{
			cout<<"\t\t\t\t\t\t Wrong Input"<<endl;
			cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
			}
		}
	}
	else if(input=="7")
	{
		time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	cout << "\t\t\t\t\t\tTime of the computer presently:"<<endl;
	cout << "\t\t\t\t\t\tseconds= " << timePtr->tm_sec << endl;
	cout << "\t\t\t\t\t\tminutes = " << timePtr->tm_min << endl;
	cout << "\t\t\t\t\t\thours = " << timePtr->tm_hour << endl;
	cout << "\t\t\t\t\t\tday of month = " << timePtr->tm_mday << endl;
	cout << "\t\t\t\t\t\tmonth of year = " << timePtr->tm_mon +1<< endl;
	cout << "\t\t\t\t\t\tyear = " << timePtr->tm_year + 1900 << endl;
	cout << "\t\t\t\t\t\tweekday = " << timePtr->tm_wday << endl;
	cout << "\t\t\t\t\t\tday of year = " << timePtr->tm_yday << endl<<endl;;
	
	cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
		
		while(1)
		{
			cout<<"\t\t\t\t\t\t"<<endl;
			cin>>q;
			if(q=="1")
			{
			system("CLS");
			break;	
			}
			else 
			{
			cout<<"\t\t\t\t\t\t Wrong Input"<<endl;
			cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
			}
		}
	}
	else if(input=="8")
	{
		cout<<"\t\t\t\t\t Exiting......."<<endl;
		break;
	}
	else 
	{
	cout<<"\t\t\t\t\t Wrong Input"<<endl<<endl;
	cout<<"\t\t\t\t\t\t Please PRESS 1 FOR MENU"<<endl;
		
		while(1)
		{
			cout<<"\t\t\t\t\t\t"<<endl;
			cin>>q;
			if(q=="1")
			{
			system("CLS");
			break;	
			}
			else 
			{
			cout<<"\t\t\t\t\t\t Wrong Input"<<endl;
			cout<<"\t\t\t\t\t\t PRESS 1 FOR MENU"<<endl;
			}
		}
	}
	system("CLS");
	}
}
