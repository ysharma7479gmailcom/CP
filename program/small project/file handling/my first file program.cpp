#include<bits/stdc++.h>
using namespace std;

int main()
{
	ofstream fout;
	fout.open("myfirstfile.docx");
	fout<<"hello world";
	fout.close();
	
	ifstream fin;
	char ch;
	fin.open("myfirstfile.docx");
	fin>>ch;
	while(!fin.eof())
	{
		cout<<ch;
		fin>>ch;
	}
	cout<<endl;
	fin.close();
	
	
	//tellg()
	fin.open("myfirstfile.docx");
	ch=fin.get();
	int pos=fin.tellg();
	while(!fin.eof())
	{
		cout<<ch;
		ch=fin.get();
	}
	fin.close();
	cout<<endl;
//tellp
	fout;
	fout.open("myfirstfile.docx",ios::app);
	fout<<" \nhello world";
	fout.close();
	
	fin.open("myfirstfile.docx");
	ch=fin.get();
	pos=fin.tellg();
	while(!fin.eof())
	{
		cout<<ch;
		ch=fin.get();
	}
	fin.close();
	cout<<endl;
}
