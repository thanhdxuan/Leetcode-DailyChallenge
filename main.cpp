#include <iostream>
#include "March2023/17-Trie.h"
using namespace std;

int main() {
  Trie* obj = new Trie();
  string word = "apple";
  string prefix = "app";
  obj->insert(word);
  bool param_2 = obj->search(word);
  if (param_2 == true) cout << "true" << endl;
  else cout << "false" << endl;
  bool param_3 = obj->startsWith(prefix);
  if (param_3 == true) cout << "true" << endl;
  else cout << "false" << endl;
  return 0;
}
