#include <algorithm>
#include <iostream>
#include <cmath>

int jumpSearch(int arr[], int x, int n)
{
  int step=std::sqrt(n);
  int prev=0;
  while (arr[std::min(step, n)-1]<x)
    {
      prev=step;
      step+=std::sqrt(n);
      if (prev>=n)
	{
	  return -1;
	}
    }
  while (arr[prev]<x)
    {
      return prev;
    }
  return -1;
}

int main(int argc, char *argv[])
{
  int arr[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
  int x=55;
  int n=sizeof(arr)/sizeof(arr[0]);
  int index=jumpSearch(arr, x, n);
  std::cout<<"Number "<<x<<" is at index "<<index<<std::endl;
  return 0;
}
