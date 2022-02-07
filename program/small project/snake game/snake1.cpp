#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int size;
int tailx[100],taily[100];
bool game;
int width=20,height=20;
int x,y,coinx,coiny,score;
enum edirection{
	stop=0,
	l,
	
	up,
	down,
	r,
};
edirection dir=l;

void setup()
{
	game=false;
	dir=stop;
	x=width/2;
	y=height/2;
	coinx=rand() % width;
	coiny= rand() % height;
	score=0;
}

void draw()
{
	cout<<endl<<endl;
	system("cls");
	for(int i=0;i<height;i++)
	{
		cout<<"                          ";
		for(int j=0;j<width;j++)
		{
			
			if(i==0 || i==height-1)cout<<"#";
			else if(i==x && j==y)cout<<"D";
			else if(i==coinx && j== coiny)
				cout<<"F";
			else if(j==0 || j==width-1)cout<<"#";
			
			else {
			bool flag=false;
			for(int k=0;k<size;k++)
			{
				if(tailx[k]==i && taily[k]==j)
				{
						cout<<"*";
						flag=true;
				
				}
			
			}
			if(!flag)cout<<" ";
		}
	}
		cout<<endl;
	}
	cout<<"score: "<<score<<endl;
	
}
void input()
{
	if(_kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir=l;
				break;
			case 'w':
				dir=up;
				break;		
			case 's':
				dir=down;
				break;
			
			case 'd':
				dir=r;
				break;
			
			case ' ':
				game=true;
				break;
				
	}
}
}

void basic_code()
{
	
	int prevx=tailx[0],prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x,taily[0]=y;
	for(int i=1;i<size;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(dir)
	{
		case l:
			y--;
			break;
		case up:
			x--;
			break;
		case r:
			y++;
			break;
		case down:
			x++;
			break;
		default:
			break;
	}
 
	
	
	for(int i=0;i<size;i++)
	if(x==tailx[i] && y==taily[i])
		game=true;
	if(x==coinx && y==coiny)
	{
		score+=1;
	coinx=rand() % width;
	coiny= rand() % height;
	if(coinx==0)coinx++;
	if(coiny==0)coiny++;
	if(coinx==width)coinx--;
	if(coiny==height)coiny--;
	
	size++;
		
	}
	
		if(x==width)x=1;
		if(y==height)y=1;
		if(x==0)x=width-2;
		if(y==0)y=height-2;
}

int main()
{
	setup();
	while(!game)
	{
		draw();
		input();
		basic_code();
	
	}
	return 0;
}
