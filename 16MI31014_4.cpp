//ROLL-16MI31014
//NAME-SAYAN GUHA
//Assignment no-4
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include<vector>
using namespace std;
int min(vector<double> vd);
int main()
{
	ifstream p("data4.csv");ofstream f3("16MI31014_4.out");		
  	string f;
	int r=0;
	double x[100][50];vector<vector<double> > v,vt;vector<double> v2,v0,v1,vd;double dt;int z1,i1,j1;
	double y[100];
	int z[10];
	int c=0,k,s;int i;int j;
  	while(p.good()){
		for(i=0;i<4;i++)
		{
			getline(p,f,',');
			x[r][i]=(strtod(f.c_str(),NULL));
		}
		getline(p,f,'\n');
		y[r]=(int)f[0]-48;
		r++;
	}
	for(i=0;i<74;i++)
	{
		v2.push_back(y[i]);	
		}
		for(i=0;i<74;i++)
{
	for(j=0;j<4;j++)
	v0.push_back(x[i][j]);
	v.push_back(v0);
	v0.clear();
	
}
ifstream t("test4.csv");		
	int rt=0;
	double xt[100][50];
	while(t.good()){
		for(int i=0;i<4;i++)
		{
			if(i==3)
			{
				getline(t,f,'\n');
				xt[rt][i]=(strtod(f.c_str(),NULL));
			}
			else
			{
				getline(t,f,',');
				xt[rt][i]=(strtod(f.c_str(),NULL));
			}	
			
		}
		rt++;
	}
	for(i=0;i<26;i++)
{
	for(j=0;j<4;j++)
	{
	
	v1.push_back(xt[i][j]);
}

	for(i1=0;i1<74;i1++)
	{
	dt=0.0;
		for(j1=0;j1<4;j1++)
		{
		dt=dt+pow((v1[j1]-v[i1][j1]),2); //square
		
	}
		vd.push_back(dt);
		}
	int k1,k2;k1=k2=0;
	for(k=0;k<5;k++)
	{
	z1=min(vd);
	if(v2[z1]==0)
	k1++;
	else
	k2++;
	vd[z1]=5000.0;
	
		
	}
	if(k1>k2)
	f3<<0<<" ";
	else
	f3<<1<<" ";
	v1.clear();
	vd.clear();
}
}
int min(vector<double> vd)
{
	int i;int k;double min=vd[0];k=0;
	for(i=1;i<74;i++)
	{
		if(vd[i]<min)
		{
			min=vd[i];
			k=i;
		}
	}
	return k;
}



