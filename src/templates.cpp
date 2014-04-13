#include<vector>
#include<iostream>

using namespace std;

void test() {
  vector<int> v(0);
  v.push_back(5);
  v.push_back(3);
  v.push_back(6);
  v.push_back(2);

  cout << v[0];
}
