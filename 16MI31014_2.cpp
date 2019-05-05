//ROLL-16MI31014
//NAME-SAYAN GUHA
//Assignment no-2
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include<vector>
using namespace std;
double entropy(vector<int> v);
int  i_gain(vector<vector<int> > v,vector <int> v2,int row,int col);
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* Createtree(vector<vector<int> > v,vector <int> v2,int n);
int result(vector <int> v,Node* root);

int main(){
	ifstream p("data2.csv");vector<int> v2,v0,v3,v4;vector<vector<int> > v,v1;		
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
	for(i=0;i<24;i++)
{
	v2.push_back(y[i]);
}
for(i=0;i<24;i++)
{
	for(j=0;j<8;j++)
	v0.push_back(x[i][j]);
	v.push_back(v0);
	v0.clear();
	
}



Node*root=new Node();
root=Createtree(v,v2,0);

ifstream p1("test2.csv");
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



int k1;int j1;	ofstream f3("16MI31014_2.out");
for(i=0;i<4;i++)
{
	for(j=0;j<8;j++)
	v3.push_back(x1[i][j]);

	f3<<result(v3,root)<<" ";
v3.clear();
}
}
int  i_gain(vector<vector<int> > v,vector <int> v2,int row,int col) 
{
	int i,j;double min;vector <int> v3;vector <int> v4;vector <double> v5;double a,b;int k;double c,c1,c2;
	for(i=0;i<col;i++)
	{
		if(v[0][i]==50)
		{
			v5.push_back(100);
			continue;
		}
		for(j=0;j<row;j++)
		{
			if(v[j][i]==0)
			v3.push_back(v2[j]);
			if(v[j][i]==1)
			v4.push_back(v2[j]);
		}
		a=(double)(v3.size())/row;
		b=(double)(v4.size())/row;

		c1=(a*entropy(v3));
		
		c2=(b*entropy(v4));
		
		c=c1+c2;
		v5.push_back(c);
		v3.clear();
		v4.clear();
	}
	min=v5[0];
	k=0;
	for(i=0;i<v5.size();i++)
	{
		if(v5[i]<min)
		{
			min=v5[i];
			k=i;
		}
	}
return k;	
}
double entropy(vector<int> v)
{
	int l=0,a=0;double b,c;double q,w;double z;
	if(v.size()==0)
	return 0.0;
	else
	{
	

	for (int i = 0; i < v.size(); i++) {
        
        	if(v[i]==0)
        	l++;
		
	}
	
		
	for (int i = 0; i < v.size(); i++) 
	a++;
	
	q=double(l)/a;
w=double(a-l)/a;

b=-q*log2(q);
c=-w*log2(w);
z=b+c;
if(isnan(z))

	return 0.0;
	else
	return z;

}

}
Node* Createtree(vector<vector<int> > v,vector <int> v2,int n)
{
double k=entropy(v2);int i;int a,b;int f;
Node* root=new Node;

if(k==0)
{
	root->data=v2[0];
	root->left=root->right=NULL;
	return root;
	}
	
	if(n==v[0].size())
	{ 
	 for(i=0;i<v2.size();i++)
	 {
	 	if(v2[i]==0)
	 	a++;
	 	if(v2[i]==1)
	 	b++;
	 }
	 root->data=a>b?0:1;
	 root->left=root->right=NULL;
	return root;
	 
	}
	
	int c,d;vector<vector<int> > v5,v6;int e;vector <int> v7,v8,v9,v10;int j;int x,y;x=y=0;int g;
	c=v.size();
	d=v[0].size();
	root->data=i_gain(v,v2,c,d);
	
	for(i=0;i<v.size();i++)
	{
		if(v[i][root->data]==0)
		{
		e++;
		v7.push_back(v2[i]);
}
}

for(i=0;i<v.size();i++)
	{
		if(v[i][root->data]==0)
		{
		
				
				v5.push_back(v[i]);
			
		}
			
				
			}
	for(i=0;i<v5.size();i++)
{
	
		v5[i][root->data]=50;
	
}
for(i=0;i<v.size();i++)
	{
		if(v[i][root->data]==1)
		{
		f++;
		v8.push_back(v2[i]);
}
}		
	for(i=0;i<v.size();i++)
	{
		if(v[i][root->data]==1)
		{
		
				
				v6.push_back(v[i]);
			
		}
			
				
			}			
		
	for(i=0;i<v6.size();i++)
{
	
	
		v6[i][root->data]=50;
	}

	
			
			
			
				
		root->left=Createtree(v5,v7,n+1);
	root->right=Createtree(v6,v8,n+1);
	return root;
		}
		
		int result(vector <int> v,Node* root)
		{
			
			if(root->left==NULL && root->right==NULL)
		return root->data;
		if(v[root->data]==0)
	return 	result(v,root->left);
		if(v[root->data]==1)
	return 	result(v,root->right);
		}
