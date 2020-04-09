//Array pair sum

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


void NlogNgetPairs(vector<int> inp, int k)
{
	if(inp.size() < 2)	return;
	sort(inp.begin(),inp.end());
	int left = 0;
	int right = inp.size() - 1;

	int csum;
	while(left<right)
	{
		csum = inp[left] + inp[right];
		if(csum==k)		
			cout<<inp[left++]<<' '<<inp[right]<<'\n';					
		else if(csum < k)
			left++;
		else
			right--;
	}
}

void NgetPairs(vector<int> inp, int k)
{
	if(inp.size()<2) return;
	set<int> seen;	
	vector<pair<int,int>> output;
	for(int i=0;i<inp.size();i++)
	{
		int target = k - inp[i];
		if(seen.find(target)!=seen.end())
		{
			pair<int,int> pp(min(inp[i],target),max(inp[i],target));
			output.push_back(pp);
		}			
		else
			seen.insert(inp[i]);
	}

	for(auto i=output.begin();i!=output.end();i++)
		cout<<i->first<<' '<<i->second<<endl;

	
}


int main()
{
	vector<int> inp;
	/*
	int n,temp,i,k;
	cout<<"\nEnter size of input: ";
	cin>>n;
	cout<<"\nEnter elements:-\n";
	for(i=0;i<n;i++)
	{
		cin>>temp;
		inp.push_back(temp);
	}		
	cout<<"\nEnter value of k: ";
	cin>>k;
	*/
	inp.push_back(2);
	inp.push_back(1);
	inp.push_back(3);
	inp.push_back(5);
	inp.push_back(4);	
	//NlogNgetPairs(inp,6);
	NgetPairs(inp,6);
	return 0;
}