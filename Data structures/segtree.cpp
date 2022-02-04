#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

//Constructs the initial segment tree
void ConsTree(const std::vector<int64_t> &arr, std::vector<int64_t> *segtree, uint64_t low, uint64_t high, uint64_t pos)
{
  if (low==high)
    {
      (*segtree)[pos]=arr[low];
      return;
    }
  uint64_t mid=(low+high)/2;
  ConsTree(arr, segtree, low, mid, 2*pos+1);
  ConsTree(arr, segtree, mid+1, high, 2*pos+2);
  (*segtree)[pos]=(*segtree)[2*pos+1]+(*segtree)[2*pos+2];
}

//Returns the sum of all elements in a range
int64_t query(std::vector<int64_t> *segtree, std::vector<int64_t> *lazy, uint64_t qlow, uint64_t qhigh, uint64_t low, uint64_t high, uint64_t pos)
{
  if (low>high||qlow>high||low>qhigh)
  {
    return 0; 
  }
  if ((*lazy)[pos]!=0)
    {
      (*segtree)[pos]+=(*lazy)[pos]*(high-low+1);
      if (low!=high)
	{
	  (*lazy)[2*pos+1]+=(*lazy)[pos];
	  (*lazy)[2*pos+2]+=(*lazy)[pos];
	}
      (*lazy)[pos]=0;
      }
    if (qlow<=low && low && qhigh>=high)
      {
       return (*segtree)[pos];
      }
    uint64_t mid=(low+high)/2;
    return query(segtree, lazy, qlow, qhigh, low, mid, 2*pos+1)+query(segtree, lazy, qlow, qhigh, mid+1, high, 2*pos+2);
}

//Updates a range of the segment tree
void update(std::vector<int64_t> *segtree, std::vector<int64_t> *lazy, int64_t start, int64_t end, int64_t delta, uint64_t low, uint64_t high, uint64_t pos)
{
  if (low>high)
    {
      return;
    }
  if ((*lazy)[pos]!=0)
    {
      (*segtree)[pos]+=(*lazy)[pos]*(high-low+1);
      if (low!=high)
	{
	  (*lazy)[2*pos+1]+=(*lazy)[pos];
	  (*lazy)[2*pos+2]+=(*lazy)[pos];
	}
      (*lazy)[pos]=0;
    }
  if (start>high||end<low)
    {
      return;
    }
  if (start<=low&& end>=high)
    {
      (*segtree)[pos]+=delta*(high-low+1);
      if (low!=high)
	{
	  (*lazy)[2*pos+1]+=delta;
	  (*lazy)[2*pos+2]+=delta;
	}
      return;
    }
  uint64_t mid=(low+high)/2;
  update(segtree, lazy, start, end, delta, low, mid, 2*pos+1);
  update(segtree, lazy, start, end, delta, mid+1, high, 2*pos+2);
  (*segtree)[pos]=(*segtree)[2*pos+1]+(*segtree)[2*pos+2];
}

static void test()
{
  auto max=static_cast<int64_t>(2*pow(2, ceil(log2(7)))-1);
  assert(max==15);
  std::vector<int64_t> arr{1, 2, 3, 4, 5, 6, 7}, lazy(max), segtree(max);
  ConsTree(arr, &segtree, 0, 7-1, 0);
  assert(query(&segtree, &lazy, 1, 5, 0, 7-1, 0)==2+3+4+5+6);
  update(&segtree, &lazy, 2, 4, 1, 0, 7 -1, 0);
  assert(query(&segtree, &lazy, 1, 5, 0, 7 -1, 0)==2+4+5+6+6);
  update(&segtree, &lazy, 0, 6, -2, 0, 7-1, 0);
  assert(query(&segtree, &lazy, 0, 4, 0, 7-1, 0)==-1+0+2+3+4);
}

int main(int argc, char *argv[])
{
  //test();
  std::cout<<"Enter number of elements: ";
  uint64_t n=0;
  std::cin>>n;
  auto max=static_cast<uint64_t>(2*pow(2, ceil(log2(n)))-1);
  std::vector<int64_t> arr(n), lazy(max), segtree(max);
  int choice=0;
  std::cout<<"\nDo you wish to enter each number?:\n1.- Yes\n2.- No (default initialize them to 0)"<<std::endl;
  std::cin>>choice;
  if (choice==1)
    {
      std::cout<<"Enter "<<n<<" numbers: ";
      for (int i=1; i<=n; i++)
	{
	  std::cout<<i<<": ";
	  std::cin>>arr[i];
	}
    }
  ConsTree(arr, &segtree, 0, n-1, 0);
  do
    {
      std::cout<<"\nMake your chice:\n1.- Range update (input)\n2.- Range query (output)\n0.- Exit"<<std::endl;
      std::cin>>choice;
      if (choice==1)
	{
	  std::cout<<"Enter 1-indexed lower bound, upper bound & value: "<<std::endl;
	  uint64_t p=1, q=1, v=0;
	  std::cin>>p>>q>>v;
	  update(&segtree, &lazy, p-1, q-1, v, 0, n-1, 0);
	}
      else if (choice==2)
	{
	  std::cout<<"Enter 1-indexed lower bound & upper bound: "<<std::endl;
	  uint64_t p=1, q=1;
	  std::cin>>p>>q;
	  std::cout<<query(&segtree, &lazy, p-1, q-1, 0, n-1, 0)<<std::endl;
	}
    }
  while (choice>0);
  return 0;
}

//<>
