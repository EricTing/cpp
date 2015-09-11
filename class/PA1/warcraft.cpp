#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

static vector<string> red_order {"iceman", "lion", "wolf", "ninja", "dragon"};
static vector<string> blue_order {"lion", "dragon", "ninja", "iceman", "wolf"};

class Warrior
{
private:
  string name;
  unsigned int hp;

public:
  Warrior(string n_, unsigned int hp_) {
    name = n_;
    hp = hp_;
  }
};


class HeadQuater
{
private:
  string name;
  unsigned int life_pts;
  int order_idx;
  map<string, unsigned int> counts;
  vector<string> building_order;

public:
  static map<string, unsigned int> life_prices;
  static unsigned int cheapest;

  HeadQuater(string n_, unsigned int l,
             const vector<string>& building_order_) {
    name = n_;
    life_pts = l;
    building_order = building_order_;
    order_idx = 0;
  }

  void produce(string warrior_type);
  void produceWarriors();
  string findNextAvailable();
};


string HeadQuater::findNextAvailable()
{
  string todo = building_order[order_idx % 5];
  for (; ; order_idx++) {
    todo = building_order[order_idx % 5];
    if (life_pts >= life_prices[todo])
      break;
  }
  return todo;
}

void HeadQuater::produceWarriors()
{
  while (true) {
    string todo = building_order[order_idx % 5];
    if (life_pts < HeadQuater::cheapest) {
      cout << name << " headquarter stops making warriors" << endl;
      break;
    }
    if (life_pts < life_prices[todo]) {
      todo = findNextAvailable();
      produce(todo);
      order_idx += 1;
    }
    else {
      produce(todo);
      order_idx += 1;
    }
  }
}


void HeadQuater::produce(string warrior_type)
{
  cout << order_idx << " " << warrior_type << " born with strength " << endl;
  life_pts -= life_prices[warrior_type];
}

map<string, unsigned int> HeadQuater::life_prices {};
unsigned int HeadQuater::cheapest {0};


int main(int argc, char *argv[])
{
  HeadQuater::life_prices["dragon"] = 3;
  HeadQuater::life_prices["ninja"] = 4;
  HeadQuater::life_prices["iceman"] = 5;
  HeadQuater::life_prices["lion"] = 7;
  HeadQuater::life_prices["wolf"] = 7;

  HeadQuater::cheapest = 3;

  HeadQuater red {"red", 20, red_order};
  red.produceWarriors();


  return 0;
}
