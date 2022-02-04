#include <iostream>
#include <vector>

using namespace std;

void OddEven(vector<int> &arr, int size)
{
  bool sorted=false;
  while (!sorted)
    {
      sorted=true;
      for (int i=1; i<size-1; i+=2)
	{
	  if (arr[i]>arr[i+1])
	    {
	      swap(arr[i], arr[i+1]);
	      sorted=false;
	    }
	}
      for (int i=0; i<size-1; i+=2)
	{
	  if (arr[i]>arr[i+1])
	    {
	      swap(arr[i], arr[i+1]);
	      sorted=false;
	    }
	}
    }
}

void show(vector<int> A, int size)
{
  int i;
  for (i=0; i<size; i++)
    {
      cout<<A[i]<<endl;
    }
}

int main(int argc, char *argv[])
{
  int size, temp;
  cout<<"Enter the number of elements: ";
  cin>>size;
  vector<int> arr;
  cout<<"Enter the unsorted elements: ";
  for (int i=0; i<size; i++)
    {
      cin>>temp;
      arr.push_back(temp);
    }
  OddEven(arr, size);
  cout<<"Sorted array"<<endl;
  show(arr, size);
  return 0;
}
