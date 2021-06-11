/**
 * Lambda sorting
 * 
 * Copyright (c) 2021, sjkuksee
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
  int id;
};
int main()
{
  std::vector<Student> students = {{400}, {100}, {200}};
  std::sort(students.begin(), students.end(), [](Student &s1, Student &s2)
            { return s1.id < s2.id; });
  for (auto s : students)
  {
    std::cout << "Ids : " << s.id << std::endl;
  }
}