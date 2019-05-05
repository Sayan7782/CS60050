//ROLL-16MI31014
//NAME-SAYAN GUHA
//Assignment no-1
//Put the input file name in command line, if file is in other folder as of the program then provide the full path name as well
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
string line;
int x;
int arr[30][15];	
ifstream f;int row=0;
f.open(argv[1]);int h[8];
if(f.fail())
{
	cerr<<"File cannot be opened";
}
while(f.good())
{
for(int k=0;k<8;k++)
{

	getline(f,line,',');
	
		
		
		
		
			arr[row][k]=(int)line[0]-48;
			
}
		getline(f,line,'\n');
		arr[row][8]=(int)line[0]-48;
		row++;
	
}
row=row-1;



int i,j;


int z=0;int l=8;
for(i=0;i<8;i++)
{
	h[i]=arr[z][i];
	
}

for(i=1;i<20;i++)
{
	for(j=0;j<8;j++)
	{
	if(arr[i][8]==1)
	{
		
	
	
	if(arr[i][j]!=h[j])
	h[j]=-50;
}
}
}int a=0;
for(i=0;i<8;i++)
{
	if(h[i]==1||h[i]==0)
	a++;
	
}
cout<<a<<",";
for(i=0;i<8;i++)
{
	if(h[i]==1)
	cout<<(i+1)<<",";
	if(h[i]==0)
	cout<<-(i+1)<<",";
}
	
}
