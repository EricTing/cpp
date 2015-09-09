// input:
//
// Tom,18,7817,80,80,90,70
//
// output:
//
// Tom,18,7817,80

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Student
{

private:
  string name;
  unsigned int age;
  string id;
  unsigned int first_year_performance;
  unsigned int second_year_performance;
  unsigned int third_year_performance;
  unsigned int fourth_year_performance;

public:
  void init(string name_,
            unsigned int age_,
            string id_,
            unsigned int first_year_performance_,
            unsigned int second_year_performance_,
            unsigned int third_year_performance_,
            unsigned int fourth_year_performance_)
  {
    name = name_;
    age = age_;
    id = id_;
    first_year_performance = first_year_performance_;
    second_year_performance = second_year_performance_;
    third_year_performance = third_year_performance_;
    fourth_year_performance = fourth_year_performance_;
  }

  unsigned int avePerformance()
  {
    unsigned int sum = first_year_performance
      + second_year_performance
      + third_year_performance
      + fourth_year_performance;

    return (unsigned int) sum / 4.0;
  }

  string getName()
  {
    return name;
  }

  unsigned int getAge()
  {
    return age;
  }

  string getID()
  {
    return id;
  }
};


int main(int argc, char *argv[])
{
  string input;
  cin >> input;
  stringstream ss(input);
  string substr;

  string name;
  unsigned int age;
  string id;
  unsigned int first_year_performance;
  unsigned int second_year_performance;
  unsigned int third_year_performance;
  unsigned int fourth_year_performance;


  getline(ss, name, ',');

  getline(ss, substr, ',');
  age = stoul(substr);

  getline(ss, id, ',');

  getline(ss, substr, ',');
  first_year_performance = stoul(substr);

  getline(ss, substr, ',');
  second_year_performance = stoul(substr);

  getline(ss, substr, ',');
  third_year_performance = stoul(substr);

  getline(ss, substr, ',');
  fourth_year_performance = stoul(substr);

  Student student;
  student.init(name, age, id,
               first_year_performance,
               second_year_performance,
               third_year_performance,
               fourth_year_performance);


  cout << student.getName() << ",";
  cout << student.getAge() << ",";
  cout << student.getID() << ",";
  cout << student.avePerformance() << endl;

  return 0;
}
