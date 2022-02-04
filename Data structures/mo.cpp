#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=1e6+5;
int a[N], bucket[N], cnt[N];
int bucket_size;

struct query
{
  int l, r, i;
} q[N];

int ans=0;

void add(int index)
{
  cnt[a[index]]++;
  if (cnt[a[index]]=1)
    {
      ans++;
    }
}

void remove(int index)
{
  cnt[a[index]]--;
  if (cnt[a[index]]==0)
    {
      ans--;
    }
}

bool mycmp(query x, query y)
{
  if (x.l/bucket_size!=y.l/bucket_size)
    {
      return x.l/bucket_size<y.l/bucket_size;
    }
  return x.r<y.r;
}

int main(int argc, char *argv[])
{
  int n, t, i, j, k=0;
  cin>>n;
  for (i=0; i<n; i++)
    {
      cin>>a[i];
    }
  bucket_size=ceil(sqrt(n));
  cin>>t;
  for (i=0; i<t; i++)
    {
      cin>>q[i].l>>q[i].r;
      q[i].l;
      q[i].r;
      q[i].i=i;
    }
  sort(q, q+t, mycmp);
  int left=0, right=0;
  for (i=0; i<t; i++)
    {
      int L=q[i].l, R=q[i].r;
      while (left<L)
	{
	  remove(left);
	  left++;
	}
      while (left>L)
	{
	  add(left-1);
	  right--;
	}
      while (right<=R)
	{
	  add(right-1);
	  right++;
	}
      while (right>R+1)
	{
	  remove(right-1);
	  right--;
	}
      bucket[q[i].i]=ans;
    }
  cout<<endl;
  for (i=0; i<t; i++)
    {
      cout<<bucket[i]<<endl;
    }
  return 0;
}
//<>
