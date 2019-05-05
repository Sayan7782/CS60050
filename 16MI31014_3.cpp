//ROLL-16MI31014
//NAME-SAYAN GUHA
//Assignment no-3
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include<vector>
using namespace std;


int main(){
	ifstream p("data3.csv");vector<int> v2,v0,v3,v4;vector<vector<int> > v,v1;double a,b,c,d;int e,y1,g,h;	vector<double> pr; vector<vector<double> > pr1;double py,pn;int yes,no;
	yes=no=0;
  	string f,f1;
	int r=0;int r1=0;
	int x[30][100];
	int y[100];
	int i,j;
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

for(i=0;i<8;i++)
{
	e=y1=g=h=0;
	for(j=0;j<20;j++)
	{
	if(v[j][i]==0 && v2[j]==0)
	e++;
	if(v[j][i]==0 && v2[j]==1)
	y1++;
	if(v[j][i]==1 && v2[j]==0)
	g++;
	if(v[j][i]==1 && v2[j]==1)
	h++;	
	}
	a=(double)(e+1)/(9.0);
	pr.push_back(a);
	b=(double)(y1+1)/(15.0);
	pr.push_back(b);
	c=(double)(g+1)/(9.0);
	pr.push_back(c);
	d=(double)(h+1)/(15.0);
	pr.push_back(d);
	
	pr1.push_back(pr);
	pr.clear();
	
}
for(i=0;i<20;i++)
{
if(v2[i]==1)
yes++;
else
no++;	
}

py=(yes)/20.0;
pn=(no)/20.0;

ifstream p1("test3.csv");
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

ofstream f3("16MI31014_3.out");
double re1,re2;re1=1.0;re2=1.0;
for(i=0;i<4;i++)
{
	for(j=0;j<8;j++)
	{
		if(x1[i][j]==0)
		{
			re1=re1*pr1[j][1];
			re2=re2*pr1[j][0];
		}
	if(x1[i][j]==1)
		{
			re1=re1*pr1[j][3];
			re2=re2*pr1[j][2];
		}	
	}
	re1=re1*py;
	re2*=pn;
	
	if(re1>=re2)
		f3<<1<<" ";
	else
		f3<<0<<" ";

}
}





