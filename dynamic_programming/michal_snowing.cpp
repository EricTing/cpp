#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

constexpr bool DEBUG {false};

struct StartingPoint
{
  int height;
  int longest_from_here;
  int x_idx;
  int y_idx;
};

int main()
{

  int nr {0};
  int nc {0};

  const int VIRTUAL_HEIGHT {10001};

  cin >> nr >> nc;
  assert(nr > 0);
  assert(nc > 0);


  vector<vector<int> > heights;
  vector<int> virtual_heights(nc, VIRTUAL_HEIGHT);

  heights.push_back(virtual_heights);

  string cmd;
  while (getline(cin, cmd)) {
    if (!cmd.empty()) {
      stringstream ss {cmd};
      vector<int> vals;
      vals.push_back(VIRTUAL_HEIGHT);
      for (int val; ss >> val; )
        vals.push_back(val);
      vals.push_back(VIRTUAL_HEIGHT);
      heights.push_back(vals);
    }
  }
  heights.push_back(virtual_heights);

  ostream_iterator<int> out_it (cout, " ");

  if (DEBUG) {
    for (auto row : heights) {
      copy(row.begin(), row.end(), out_it);
      cout << endl;
    }
  }

  vector<vector<int> > longest (heights.size());
  for (auto& row : longest)
    row = vector<int> (nc + 2, 1);

  if (DEBUG) {
    for (auto row : longest) {
      copy(row.begin(), row.end(), out_it);
      cout << endl;
    }
  }


  vector<StartingPoint> pts;
  for (int i = 0; i < heights.size(); i++) {
    for (int j = 0; j < heights[i].size(); j ++) {
      auto height = heights[i][j];
      StartingPoint pt {height, 1, i, j};
      pts.push_back(pt);
    }
  }

  sort(pts.begin(), pts.end(),
       [](const StartingPoint& a, const StartingPoint& b) {return a.height < b.height;});

  if (DEBUG) {
    for(auto pt: pts) {
      cout << pt.height << endl;
    }
  }

  for(auto& pt: pts) {
    if (pt.height != VIRTUAL_HEIGHT) { // not a virtual point
      int my_x = pt.x_idx;
      int my_y = pt.y_idx;
      int my_height = pt.height;

      vector<pair<int, int> > indices {
        {my_y, my_x + 1},
          {my_y - 1, my_x},
            {my_y + 1, my_x},
              {my_y, my_x - 1}};

      int chosen_x = -1, chosen_y = -1, chosen_path = -1;

      for(auto xy : indices) {
        auto tmp_x = xy.second;
        auto tmp_y = xy.first;
        auto tmp_h = heights[tmp_x][tmp_y];
        if (tmp_h < my_height) {
          auto tmp_path = longest[tmp_y][tmp_x];
          if (tmp_path > chosen_path) {
            chosen_path = tmp_path;
            chosen_x = tmp_x;
            chosen_y = tmp_h;
          }
        }
      }

      if (-1 == chosen_x) {
        longest[my_y][my_x] = 1;
        pt.longest_from_here = 1;
      }
      else {
        longest[my_y][my_x] = 1 + chosen_path;
        pt.longest_from_here = 1 + chosen_path;
      }
    }
  }

  sort(pts.begin(), pts.end(),
       [](const StartingPoint& a, const StartingPoint& b) {return a.longest_from_here > b.longest_from_here;});

  cout << pts[0].longest_from_here << endl;


  return 0;
}
