#include<iostream>
using namespace std;
int P,Q,N,ri,ci,val,I,J;
void dispquadruplet(int sparse[][3],int i,int j,int dir)
{
	for(int z=1;z<=N;z++)
	{
		if(sparse[z][0]==i && sparse[z][1]==j)
		{
				cout<<i<<" "<<j<<" "<<sparse[z][2]<<" "<<dir<<endl;
				break;
		}
	}
}

int main()
{
	//void disp(int,int,int,int);
	int i,dir=1,count,m=0,n=1;
	cin>>P>>Q>>N;
	//row triplet representation
	int sparse[N+1][3];
	sparse[0][0]=P;
	sparse[0][1]=Q;
	sparse[0][2]=N;
	/*for(int i=0;i<P;i++)
	{
		for(int j=0;j<Q;j++)
		{
			sparse[i][j]=0;
		}
	}*/
	
	for(i = 1; i <= N; i++)
	{
		cin>>ri>>ci>>val;
		sparse[i][0]=ri;
		sparse[i][1]=ci;
		sparse[i][2]=val;
	}
	
	//input starting point
	cin>>I>>J;
	//displaying the starting point
	dispquadruplet(sparse,I,J,dir);
	count=1;
	while(count<=(P*Q))
	{
		//for loop to traverse down
		for(m=0;m<n;m++)
		{
			//moving down
			I++;
			count++;
			dir=1;//print 1 if traversing down
			dispquadruplet(sparse,I,J,dir);//displaying the value if it is not zero
		}
		//for loop to traverse right
		for(m=0;m<n;m++)
		{
			//moving right
			J++;//moving right
			count++;
			dir=2;//print 2 if traversing right
			//displaying the value if it is not zero
			dispquadruplet(sparse,I,J,dir);
		}
		n=n+1;
		//for loop to traverse up
		for(m=0;m<n;m++)
		{
			//moving up
			I--;
			count++;
			dir=3;//print 3 if traversing up
			//displaying the value if it is not zero
			dispquadruplet(sparse,I,J,dir);
		
		}
		//for loop to traverse left
		for(m=0;m<n;m++)
		{
			//moving left
			J--;
			count++;
			dir=4;//print 4if traversing left
			//displaying the value if it is not zero
			dispquadruplet(sparse,I,J,dir);
			
		}
		n=n+1;
		
	}
	return 0;
}
