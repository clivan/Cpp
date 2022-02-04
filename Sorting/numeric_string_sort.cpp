#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

bool NumericSort(std::string a, std::string b)
{
  while (a[0]=='0')
    {
      a.erase(a.begin());
    }
  while (b[0]=='0')
    {
      b.erase(b.begin());
    }
  int n=a.length();
  int m=b.length();
  if (n==m)
    {
      return a<b;
    }
  return n<m;
}

int main(int argc, char *argv[])
{
  int n;
  std::cout<<"Enter the number of elements to be sorted numerically: ";
  std::cin>>n;
  std::vector<std::string> v(n);
  std::cout<<"enter the string of numbers: ";
  for (int i=0; i<n; i++)
    {
		   std::cin>>v[i];
    }
  sort(v.begin(), v.end());
  std::cout<<"Elements sorted normally: ";
  for (int i=0; i<n; i++)
    {
      std::cout<<v[i]<<std::endl;
    }
  std::sort(v.begin(), v.end(), NumericSort);
  std::cout<<"Elements sorted numerically: ";
  for (int i=0; i<n; i++)
    {
      std::cout<<v[i]<<std::endl;
    }
  return 0;
}
