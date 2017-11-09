#include<iostream>
#include<fstream>
using namespace std;
int n,a[50][50];

void citire()
{
	int x,y;
	ifstream f("in.txt");
	f>>n;
	while(f>>x>>y)
		a[x][y]=a[y][x]=1;
}

void afisare()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void Roy_Warshall()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j && a[i][j]==0 && a[i][k] && a[k][j])
					a[i][j]=1;
}

int main()
{
	citire();
	afisare();
	Roy_Warshall();
	afisare();
	return 0;
}
