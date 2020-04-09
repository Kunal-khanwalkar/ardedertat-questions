#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getRegionSum(vector<vector<int>> v,int A[],int D[])
{
	//cout<<"\npp";	
	int sum=0;
	for(int i=A[0];i<=D[0];i++)
	{
		for(int j=A[1];j<=D[1];j++)
		{
			sum+=v[i][j];
		}
	}
	return sum;
}


vector<vector<int>> computeSum(vector<vector<int>> v)
{
	int bottomRow=v.size() , rightCol=v[0].size();
	vector<vector<int>> sums(bottomRow,vector<int>(rightCol,0));
	int i,j,rowSum;

	sums[0][0] = v[0][0];

	for(i=1;i<rightCol;i++)
		sums[0][i] = sums[0][i-1] + v[0][i];
	for(i=1;i<bottomRow;i++)
		sums[i][0] = sums[i-1][0] + v[i][0];

	for(i=1;i<bottomRow;i++)
	{
		rowSum = v[i][0];
		for(j=1;j<rightCol;j++)
		{
			sums[i][j] = sums[i-1][j] + v[i][j] + rowSum;
			rowSum += v[i][j];
		}
	}

	return sums;	
}


int getSum(vector<vector<int>> v, int A[], int D[], vector<vector<int>> sums)
{
	if(v.size()==0)
		return -1;

	return sums[D[0]][D[1]] - sums[A[0]-1][D[1]] - sums[D[0]][A[1]-1] + sums[A[0]-1][A[1]-1];

}



int main()
{
	vector<vector<int>> v {	{1,2,3,4,5},
					{6,7,8,9,10},
					{11,12,13,14,15},
					{16,17,18,19,20},
					{21,22,23,24,25}
					};	

/*
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout<<v[i][j]<<' ';
		cout<<endl;
	}
*/
	int A[2] = {2,1};
	int D[2] = {3,4};

	int fsum;
	fsum = getRegionSum(v,A,D);
	//cout<<"\nSum: "<<fsum;

	vector<vector<int>> sums(computeSum(v));
/*
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout<<sums[i][j]<<' ';
		cout<<endl;
	}	
*/
	fsum = getSum(v,A,D,sums);
	cout<<"\nSum: "<<fsum;

	return 0;
}