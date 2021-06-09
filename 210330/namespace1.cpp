/*
*
* Namespaces
*
*/

#include <cstring>
#include <string>

// Only to show name clashes, do not do this in regular code
using std::string;

// nested namespaces
namespace ns1
{
  namespace ns2
  {
    // Rough Implimentation
    // Supports lengths only until 255
    class string
    {
    private:
      char _value[0x100];

    public:
      explicit string(const char *v)
      {
        // Always check for nullptr before using!
        if (v == nullptr)
        {
          _value[0] = '\0';
        }
        strncpy(_value, v, strlen(v));
      }
      const char *value()
      {
        return _value;
      }
    };
  } // namespace ns2
} // namespace ns1

int main()
{
  string s1("hi");
  ns1::ns2::string s2("hi");
  printf("s1 = %s, s2 = %s\n", s1.c_str(), s2.value());
}