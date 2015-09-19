#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}


int main(int argc, char *argv[])
{
  string input;
  map< int, list<int> > dat;

  while (getline(cin, input)) {
    auto cmds = split(input, ' ');
    string& cmd = cmds[0];

    if (cmd == "new"){
      int id = stoi(cmds[1]);
      dat[id] = list<int>();
    }

    else if (cmd == "add"){
      int id = stoi(cmds[1]);
      int num = stoi(cmds[2]);
      dat[id].push_back(num);
    }

    else if (cmd == "out"){
      int id = stoi(cmds[1]);
      dat[id].sort();
      for (auto it = dat[id].begin(); it != dat[id].end(); it++)
        cout << " " << *it;
      cout << endl;
    }

    else if (cmd == "merge"){
      int id1 = stoi(cmds[1]);
      int id2 = stoi(cmds[2]);
      dat[id1].merge(dat[id2]);
    }

    else if (cmd == "unique"){
      int id = stoi(cmds[1]);
      dat[id].sort();
      dat[id].unique();
    }

    else
      cout << "unkown command " << cmd << endl;
  }

  return 0;
}
