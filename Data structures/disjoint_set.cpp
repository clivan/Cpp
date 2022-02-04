#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> root, rank;

//function to create a set
void CreateSet(int n)
{
  root=vector<int>(n+1);
  rank=vector<int>(n+1, 1);
  for (int i=1; i<=n; i++)
    {
      root[i]=i;
    }
}

//takes a number x and returns the set to which this number belongs to
int Find(int x)
{
  if (root[x]==x)
    {
      return x;
    }
  return root[x]=Find(root[x]);
}

//A utility function to check if x and y are from same set or not
bool InSameUnion(int x, int y)
{
  return Find(x)==Find(y);
}

//Union operation combines two disjoint sets to make a single set, in this union function we pass two elements and check if they are from different sets then combine those sets
void Union(int x, int y)
{
  int a=Find(x);
  int b=Find(y);
  if (a!=b)
    {
      if (rank[a]<rank[b])
	{
	  root[a]=b;
	}
      else if (rank[a]>rank[b])
	{
	  root[b]=a;
	}
      else
	{
	  root[a]=b;
	  rank[b]++;
	}
    }
}

int main(int argc, char *argv[])
{
  int n=100;
  //Tests CreatSet and Find
  CreateSet(n);
  for (int i=1; i<=100; i++)
  {
    if (root[i]!=1)
	  {
	    cout<<"Fail"<<endl;
	    break;
	  }
  }
  //Tests InSameUnion and Union 
  cout<<"1 and 2 are initially not in the same subset"<<endl;
  if (InSameUnion(1, 2))
    {
      cout<<"Fail"<<endl;
    }
  Union(1, 2);
  cout<<"1 and 2 are now in the same subset"<<endl;
  if (!InSameUnion(1, 2))
    {
      cout<<"Fail"<<endl;
    }
  return 0;
}