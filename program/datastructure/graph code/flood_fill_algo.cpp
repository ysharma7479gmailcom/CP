#include<bits/stdc++.h>
using namespace std;


void print(char **mat,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<mat[i][j];
		cout<<endl;
	}
}

void floodfill(char **mat,int i,int j,char ch,char col,int r,int c)
{
	if(i<0 || j<0 || i>r || j>c || mat[i][j]!=ch)
		return;
	
	mat[i][j]=col;
	print(mat,r,c);
	floodfill(mat,i+1,j,'.',' ',r,c);
	floodfill(mat,i,j+1,'.',' ',r,c);
	floodfill(mat,i-1,j,'.',' ',r,c);
	floodfill(mat,i,j-1,'.',' ',r,c);
	
}
int main()
{
	char **mat=new char*[100];
	int r,c;
	cin>>r>>c;
	
	for(int i=0;i<r;i++)
		{
			mat[i]=new char[100];
			for(int j=0;j<c;j++)
				cin>>mat[i][j];
		}
	print(mat,r,c);
	
	int r1,c1;
	cin>>r1>>c1;
	floodfill(mat,r1,c1,'.',' ',r,c);
	print(mat,r,c);
}

/*
15 15
...............
.....#####.....
....#.....#....
...########....
###........####
.###......#....
.##.......##...
.#..........#..
.#.........#...
..#.......#....
...#.....##....
...##....#.....
...#.....#.....
#####...#######
###############
*/
