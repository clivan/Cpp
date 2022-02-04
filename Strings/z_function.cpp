#include <iostream>
#include <string>
#include <cassert>
#include <vector>

std::vector<uint64_t> Z_function(const std::string &pattern)
{
  uint64_t pattern_length=pattern.size();
  std::vector<uint64_t> z(pattern_length, 0);
  uint64_t i, l=0, r=0;
  for (i=1; i<pattern_length; i++)
    {
      if (i<=r)
	{
	  z[i]=std::min(r-i+1, z[i-l]);
	}
      while (i+z[i]<pattern_length && pattern[z[i]]==pattern[i+z[i]])
	{
	  z[i]++;
	}
      if (i+z[i]-1>r)
	{
	  r=i+z[i]-1;
	}
    }
  return z;
}

std::vector<uint64_t> find_pat_in_text(const std::string &pattern, const std::string &text)
{
  uint64_t text_length=text.size(), pattern_length=pattern.size();
  std::vector<uint64_t> z=Z_function(pattern+'#'+text);
  std::vector<uint64_t> matching_indexes;
  for (uint64_t i=0; i<text_length; i++)
    {
      if (z[i+pattern_length+1]==pattern_length)
      {
	matching_indexes.push_back(i);
      }
    }
  return matching_indexes;
}

static void test()
{
  std::string text1="alskfjaldsabc1abc1abcbksbcdnsdabcabc";
  std::string pattern1="abc";
  std::vector<uint64_t> matching_indexes1=find_pat_in_text(pattern1, text1);
  assert((matching_indexes1==std::vector<uint64_t>{10, 14, 18, 30, 33}));
  std::string text2="greengrass";
  std::string pattern2="abc";
  std::vector<uint64_t> matching_indexes2=find_pat_in_text(pattern2, text2);
  assert((matching_indexes2==std::vector<uint64_t>{}));
}

int main(int argc, char *argv[])
{
  test();
  return 0;
}


//<>
