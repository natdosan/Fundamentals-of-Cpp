#include <iostream>
#include <cinttypes>
#include <string>

struct Student
{
    // These are "member" vars, followed by the struct "tag" studet
    uint64_t id;
    std::string firstName;
    std::string lastName;
    //  std::string *classes;  // pointer to classes
};

void dump(const Student &s) // pass by ref because do not need to make a copy of it
{
    std::cout << s.id << ": " << s.firstName << " " << s.lastName << std::endl;
}

int main()
{
    // Note that you can yuse the "Student" name as type without the "struct" keyword
    Student s1; // creates a student "instance" with space allocated
    s1.id = 4523123;
    s1.firstName = "Jimmy";
    s1.lastName = "Neutron";
    dump(s1);

    // two ways
    Student s2 = {6789991212, "Lisa", "Connolly"};
    dump(s2);

    Student *s1p = &s1;      // & gives the memory location and assigns it to the pointer *s1p to a student
    s1p->lastName = "Hoffa"; // uses  "arrow" notation when referring to the pointer instead of .
    dump(s1);

    std::cout << &s1 << ": " << &(s1.id) << " " << &(s1.firstName) << " " << &(s1.lastName) << std::endl;
}