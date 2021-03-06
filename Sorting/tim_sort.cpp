#include <iostream>
#include <algorithm>

const int RUN=32;

void insertionSort(int arr[], int left, int right)
{
  for (int i=left+1; i<right; i++)
    {
      int temp=arr[i];
      int j=i-1;
      while (arr[j]>temp && j>=left)
	{
	  arr[j+1]=arr[j];
	  j--;
	}
      arr[j+1]=temp;
    }
}

void merge(int arr[], int l, int m, int r)
{
  int len1=m-l+1, len2=r-m;
  int *left=new int[len1], *right=new int[len2];
  for (int i=0; i<len1; i++)
    {
      left[i]=arr[l+1];
    }
  for (int i=0; i<len2; i++)
    {
      right[i]=arr[m+1+i];
    }
  int i=0;
  int j=0;
  int k=l;
  while (i<len1 && j<len2)
    {
      if (left[i]<=right[j])
	{
	  arr[k]=left[i];
	  i++;
	}
      else
	{
	  arr[k]=right[j];
	  j++;
	}
      k++;
    }
  while (i<len1)
    {
      arr[k]=left[i];
      k++;
      i++;
    }
  while (j<len2)
    {
      arr[k]=right[j];
      k++;
      j++;
    }
  delete[] left;
  delete[] right;
}

void timSort(int arr[], int n)
{
  for (int i=0; i<n; i+=RUN)
    {
      insertionSort(arr, i, std::min((i+31), (n-1)));
    }
  for (int size=RUN; size<n; size=2*size)
    {
      for (int left=0; left<n; left+=2*size)
	{
	  int mid=left+size-1;
	  int right=std::min((left+2*size-1), (n-1));
	  merge(arr, left, mid, right);
	}
    }
}

void printArray(int arr[], int n)
{
  for (int i=0; i<n; i++)
    {
      std::cout<<arr[i]<<std::endl;
    }
}

int main(int argc, char *argv[])
{
  int arr[]={5, 21, 7, 23,19};
  int n=sizeof(arr)/sizeof(arr[0]);
  std::cout<<"Given array is: "<<std::endl;
  printArray(arr, n);
  timSort(arr, n);
  printf("After Sorting array is:");
  printArray(arr, n);
  return 0;
}
