#include <iostream>

int main(int argc, char *argv[])
{
  int n, i, j, temp, numbers[50];
  std::cout<<"Enter the amount of numbers to sort: ";
  std::cin>>n;
  std::cout<<"Enter "<<n<<" numbers:";
  for (i=0; i<n; i++)
    {
      std::cin>>numbers[i];
    }
  for (i=0; i<(n-1); i++)
    {
      for (j=0; j<(n-1-i); j++)
	{
	  if (numbers[j]>numbers[j+1])
	    {
	      temp=numbers[j];
	      numbers[j]=numbers[j+1];
	      numbers[j+1]=temp;
	    }
	}
    }
  std::cout<<"Sorted array: ";
  for (i=0; i<n; i++)
    {
      std::cout<<numbers[i]<<std::endl;
    }
  return 0;
}

//<>
