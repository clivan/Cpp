#include <iostream>

int linearSearch(int *array, int size, int key)
{
  for (int i=0; i<size; i++)
    {
      if (array[i]==key)
	{
	  return i;
	}
    }
  return -1;
}

int main(int argc, char *argv[])
{
  int size;
  std::cout<<"Enter the sie of the Array: ";
  std::cin>>size;
  int *array=new int[size];
  int key;
  std::cout<<"Enter the array of "<<size<<" numbers: ";
  for (int i=0; i<size; i++)
    {
      std::cin>>array[i];
    }
  std::cout<<"Enter the number to be searched: ";
  std::cin>>key;
  int index=linearSearch(array, size, key);
  if (index !=-1)
    {
      std::cout<<"Number found at index: "<<index<<std::endl;
    }
  else
    {
      std::cout<<"Not found"<<std::endl;
    }
  delete[] array;
  return 0;
}
