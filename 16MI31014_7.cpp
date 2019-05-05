//ROLL-16MI31014
//NAME-SAYAN GUHA
//Assignment no-7
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include<vector>
using namespace std;
int distance(vector<double> v2,vector<double>v1,vector<vector<int> > v,int i);ofstream f3("16MI31014_7.out");

int main()
{
	ifstream p("data7.csv");
	string f;
  	
	int r=0;
	double x[100][50];
	int z[10];
	int y[50];
	int c=0,k,s,k1;
	vector<int> v0,v3,v4;vector<vector<int> > v;int i,j,i1,j1;int di;vector<double> v2,v1;
  	while(p.good()){
		for(int i=0;i<7;i++)
		{
			getline(p,f,',');
			x[r][i]=(int)f[0]-48;
		}
		getline(p,f,'\n');
		x[r][7]=(int)f[0]-48;
		r++;
	}	
	r--;
	for(i=0;i<20;i++)
{
	for(j=0;j<8;j++)
	v0.push_back(x[i][j]);
	v.push_back(v0);
	v0.clear();
	
}

for(i=0;i<8;i++)
{
	v1.push_back(x[0][i]);    //random assignment of centroid 1

}
for(i=0;i<8;i++)
{
	v2.push_back(x[1][i]);  //random assignment of centroid 2

}



for(i=0;i<10;i++)
{
	
for(i1=0;i1<20;i1++)     //clustering
{
	di=distance(v2,v1,v,i1);
	
	if(di==1)
	v3.push_back(i1);
	else
	v4.push_back(i1);
	}
	for(j=0;j<8;j++)    //pre cursor to update
	{
	
		v1[j]=0.0;
		v2[j]=0.0;
	}
	for(j=0;j<v3.size();j++){
		k=v3[j];
	
		for(j1=0;j1<8;j1++)

{
	
	v1[j1]=v1[j1]+v[k][j1];
	
	}
		}
for(j=0;j<8;j++)    // update
	{
	v1[j]=v1[j]/v3.size();		
}
for(j=0;j<v4.size();j++){
	k1=v4[j];
	
		for(j1=0;j1<8;j1++)

{
	
	v2[j1]=v2[j1]+v[k1][j1];
	
	}
		}
for(j=0;j<8;j++)    // update
	{
	v2[j]=v2[j]/v4.size();
			
}
} //close of loop
for(i=0;i<20;i++){    //printing
	int flag=0;
	for(j=0;j<v3.size();j++)
	{
		if(i==v3[j])
		flag=1;
		
	}
	if(flag==1)
	f3<<1<<" ";
	else
f3<<2<<" ";	
}
}  //close of main
int distance(vector<double> v2,vector<double>v1,vector<vector<int> > v,int i)  //distance function
{
	double d1,d2;d1=d2=0.0;
	int q;
	for(q=0;q<8;q++)
	{
		d1+=pow((v[i][q]-v1[q]),2);
		d2+=pow((v[i][q]-v2[q]),2);
	}
	
	if(d1<d2)
	return 1;
	else return 2;
}





