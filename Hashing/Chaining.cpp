#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class hash_chain
{
private:
  using Node=struct Node {
    int data{};
    shared_ptr<struct Node> next;
  };
  vector<shared_ptr<Node>> head;
  int _mod;

public:
  explicit hash_chain(int mod):_mod(mod)
  {
    while (mod--)
      {
	head.push_back(nullptr);
      }
  }

  void add(int x, int h)
  {
    shared_ptr<Node> curr;
    shared_ptr<Node> temp(new  Node);
    temp->data=x;
    temp->next=nullptr;
    if (!head[h])
      {
	head[h]=temp;
	curr=head[h];
      }
    else
      {
	curr=head[h];
	while (curr->next)
	  {
	    curr=curr->next;
	    curr->next=temp;
	  }
      }
  }

  void display()
  {
    shared_ptr<Node> temp=nullptr;
    for (int i=0; i<_mod; i++)
      {
	if (!head[i])
	  {
	    cout<<"Key "<<i<<" is empty"<<endl;
	  }
	else
	  {
	    cout<<"Key "<<i<<" has values= "<<endl;
	    temp=head[i];
	    while (temp->next)
	      {
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	      }
	    cout<<temp->data<<endl;
	  }
      }
  }

  virtual int hash(int x) const
  {
    return x %_mod;
  }

  bool find(int x, int h) const
  {
    shared_ptr<Node> temp=head[h];
    if (!head[h])
      {
	cout<<"Element not found"<<endl;
	return false;
      }
    while (temp->data!= x && temp->next)
      {
	temp=temp->next;
      }
    if (temp->next)
      {
	cout<<"Element found"<<endl;
	return true;
      }
    if (temp->data==x)
      {
	cout<<"Element found"<<endl;
	return true;
      }
    cout<<"Element not found"<<endl;
    return false;
  }
};

int main(int argc, char *argv[])
{
  int c=0, x=0, mod=0, h=0;
  cout<<"Enter the size of Hash Table ="<<endl;
  cin>>mod;
  hash_chain mychain(mod);
  bool loop=true;
  while (loop)
    {
      cout<<endl;
      cout<<"Please choice"<<endl;
      cout<<"1- Add element"<<endl;
      cout<<"2. Find element"<<endl;
      cout<<"3. Generate hash"<<endl;
      cout<<"4. Display hash table"<<endl;
      cout<<"5. Exit"<<endl;
      cin>>c;
      switch(c)
	{
	case 1:
	  cout<<"Enter Element to add="<<endl;
	  cin>>x;
	  h=mychain.hash(x);
	  mychain.add(x, h);
	  break;
	case 2:
	  cout<<"Enter element to generate hash="<<endl;
	  cin>>x;
	  mychain.hash(x);
	  mychain.find(x, h);
	  break;
	case 3:
	  cout<<"Enter element to generate hash="<<endl;
	  cin>>x;
	  cout<<"Hash of "<<x<<" is= "<<mychain.hash(x)<<endl;
	  break;
	case 4:
	  mychain.display();
	  break;
	default:
	  loop=false;
	  break;
	}
      cout<<endl;
    } 
  return 0;
}

