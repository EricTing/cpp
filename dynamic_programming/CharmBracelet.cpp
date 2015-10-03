/**
 *   \file CharmBracelet.cpp
 *   \brief Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.
 *
 *   \algorithm

 put the charms into a priority queue; those with less weight and greater desirability are of higher priority.

 maxDesirability(MAX_WEIGHT, TOTAL_CHARMS, min_w, its_d)
 cond TOTAL_CHARMS == 0
      0
 cond min_w > MAX_WEIGHT:
      0
 cond min_w == MAX_WEIGHT:
      my_d
 conf min_w < MAX_WEIGHT:
      if choose min_w:
         remove min_w from available list
         return my_d + maxDesirability(MAX_WEIGHT - min_w, TOTAL_CHARMS - 1, min_w, its_d)
      else:
         remove min_w from available list
         return maxDesirability(MAX_WEIGHT, TOTAL_CHARMS, min_w, its_d)

 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;


struct Charm
{
  int weight;
  int desirability;
};

struct LessWeightMoreDesire
{
  bool operator()(const Charm& lhs, const Charm& rhs) const
  {
    if (lhs.weight > rhs.weight)
      return true;
    else if (lhs.weight == rhs.weight)
      return lhs.desirability < rhs.desirability;
    else
      return false;
  }
};


int maxDesirability(int MAX_WEIGHT, int TOTAL_CHARMS,
                    priority_queue<Charm, vector<Charm>, LessWeightMoreDesire> charm_queue)
{
  if (charm_queue.empty())
    return 0;

  if (TOTAL_CHARMS == 0)
    return 0;

  auto charm = charm_queue.top();
  auto weight = charm.weight;
  auto desirability = charm.desirability;

  if (weight > MAX_WEIGHT)
    return 0;


  if (weight == MAX_WEIGHT)
    return desirability;

  if (weight < MAX_WEIGHT) {
    charm_queue.pop();
    int result_if_choose = desirability + maxDesirability(MAX_WEIGHT - weight,
                                                          TOTAL_CHARMS - 1,
                                                          charm_queue);
    int result_if_dismiss = maxDesirability(MAX_WEIGHT,
                                            TOTAL_CHARMS,
                                            charm_queue);

    if (result_if_choose >= result_if_dismiss)
      return result_if_choose;
    else
      return result_if_dismiss;
  }
}


int main(int argc, char *argv[])
{
  int TOTAL_CHARMS {0};
  int MAX_WEIGHT {0};

  cin >> TOTAL_CHARMS >> MAX_WEIGHT;

  priority_queue<Charm, vector<Charm>, LessWeightMoreDesire> charm_queue;

  string line;
  while(getline(cin, line)) {
    if (!line.empty()) {
      stringstream ss {line};
      int weight, desirability;
      ss >> weight >> desirability;
      Charm charm {weight, desirability};
      charm_queue.push(charm);
    }
  }

  cout << maxDesirability(MAX_WEIGHT, TOTAL_CHARMS, charm_queue) << endl;

  return 0;
}


