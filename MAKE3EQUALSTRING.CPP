#include <iostream>
using namespace std;

int main() {
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  int count=0;
  while(true)
  {
    if(s1 == s2 && s2 == s3)
    {
      break;
    }
    if(s1.length() < 2 || s2.length() < 2 ||  s3.length() < 2)
    {
      count = -1;
      break;
    }
    if(s1.back() == s2.back()  &&   s2.back() == s3.back())
    {
      s1.pop_back();
      s2.pop_back();
      s3.pop_back();
    }
    else if(s1.back() == s2.back())
    {
      s1.pop_back();
      s2.pop_back();
    }
    else if(s1.back() == s3.back())
    {
      s1.pop_back();
      s3.pop_back();
    }
    else if(s2.back() == s3.back())
    {
      s2.pop_back();
      s3.pop_back();
    }
    else
    {
      count = -1;
      break;
    }
    count++;
  }
  cout << cout << endl;
  return 0;
}




This code first takes the input of three strings s1, s2, and s3. Then, it enters a loop that continues until the three strings are equal or one of the strings has length less than 2. Inside the loop, it checks if the last characters of all three strings are equal. If they are, it removes the last character from all three strings. Otherwise, it checks if the last characters of any two of the strings are equal. If they are, it removes the last character from the two strings that are equal. If none of the last characters are equal, it sets the count to -1 to indicate that it is not possible to make the three strings equal. Finally, it prints the count and returns 0.



time complexity and space complexity  of this solutin:


The time complexity of the solution is O(n), where n is the maximum length of the three strings. This is because the loop continues until one of the strings has length less than 2, and in each iteration of the loop, we only perform constant-time operations. The space complexity of the solution is O(1), because we only use a constant amount of additional memory, regardless of the input size.

Here is a more detailed explanation of the time complexity:

The worst-case scenario is when all three strings have the same length, and we need to perform n operations to make them equal.
In the best-case scenario, we only need to perform one operation if the three strings are already equal.
The average-case scenario is somewhere in between the worst-case and best-case scenarios.
Therefore, the overall time complexity of the solution is O(n).

The space complexity of the solution is constant because we only use a constant amount of additional memory, regardless of the input size. The additional memory is used to store the three strings and the count variable.
