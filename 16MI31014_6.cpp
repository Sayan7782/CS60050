//ROLL-16MI31014
//NAME-SAYAN GUHA
//Assignment no-6
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include<vector>
using namespace std;
int calculate(vector<vector<int> > v,double wt[8],int i);

int main()
{
ifstream p("data6.csv");	

vector<int> v2,v0,v3,v4;vector<vector<int> > v,v1;double a,b,c,d;int e,y1,g,h;	vector<double> pr; vector<vector<double> > pr1;double py,pn;
string f,f1;
	int r=0;int r1=0;
	int x[30][100];
	int y[100];
	int i,j,k,i1,j1;
	while(p.good()){
		for(i=0;i<8;i++)
		{
			getline(p,f,',');
			x[r][i]=(int)f[0]-48;
		}
		getline(p,f,'\n');
		y[r]=(int)f[0]-48;
		r++;
	}	
	r--;
	for(i=0;i<20;i++)
{
	v2.push_back(y[i]);
}
for(i=0;i<20;i++)
{
	for(j=0;j<8;j++)
	v0.push_back(x[i][j]);
	v.push_back(v0);
	v0.clear();
	
}
double wt[8];double eta=0.1;double dwt[8];int cal;
for(i=0;i<8;i++)
{
	wt[i]=0.0;
}
for(i=0;i<10;i++)  //start of delta rule
{
for(k=0;k<8;k++)
{
	dwt[k]=0.0;
	}
	for(i1=0;i1<20;i1++)
	{
	cal=calculate(v,wt,i1);
	
	for(j1=0;j1<8;j1++)
	{
		dwt[j1]=dwt[j1]+eta*(v2[i1]-cal)*v[i1][j1];
		
		
	}
	
	
	
		}
		for(k=0;k<8;k++)
{
wt[k]=wt[k]+dwt[k];
}

}  //delta close


	ifstream p1("test6.csv");
int x1[30][100];
while(p1.good()){
		for(int i=0;i<8;i++)
		{
			if(i==7)
			{
				getline(p1,f1,'\n');
				x1[r1][i]=(int)f1[0]-48;	
			}
			else{
			getline(p1,f1,',');
			x1[r1][i]=(int)f1[0]-48;
			}	
			
		}
	
		r1++;
	}	
	r1--;

ofstream f3("16MI31014_6.out");
for(i=0;i<20;i++)
{
	for(j=0;j<8;j++)
	v3.push_back(x1[i][j]);
	v1.push_back(v3);
	v3.clear();
}
for(i=0;i<4;i++)
{
	int co=calculate(v1,wt,i);
	f3<<co<<" ";
}
}
  //main close
int calculate(vector<vector<int> > v,double wt[8],int i)
{
double score=0.0;int u;double sig;
for(u=0;u<8;u++)
{
score=score+v[i][u]*wt[u];

		
}

sig=1.0/(1+exp(-score));

if(sig>=0.5)
return 1;
else
return 0;
	
}

