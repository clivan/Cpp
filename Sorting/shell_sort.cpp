#include <iostream>
 
int main(int argc, char *argv[])
{
  int size=10;
  int *array=new int[size];
  std::cout<<"How many do wont to enter in unsorted array: ";
  std::cin>>size;
  std::cout<<"Enter the number for usorted array: ";
  for (int i=0; i<size; i++)
    {
      std::cin>>array[i];
    }
  for (int i=size/2; i>0; i=i/2)
    {
      for (int j=1; j<size; j++)
	{
	  for (int k=j-1; k>=0; k=k-1)
	    {
	      if (array[k]<array[k+1])
		{
		  break;
		}
	      else
		{
		  int temp=array[k+1];
		  array[k+1]=array[k];
		  array[k]=temp;
		}
	    }
	}
    }
  std::cout<<"Sorted array: ";
  for (int i=0; i<size; i++)
    {
      std::cout<<array[i]<<std::endl;
    }
  delete[] array;
  return 0;
}
