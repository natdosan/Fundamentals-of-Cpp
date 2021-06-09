#include <iostream>
#include <vector>

int main()
{
    std::string message;
    while (std::cin >> message)
    {
        std::cout << message << std::endl;
    }

    int num;
    std::cout << "Input a number\n";
    std::cin >> num;
    bool prime = true;
    std::vector<int> primeCalculator;

    for (int i = i; i < num; i++)
    {
        for (int j = 1; j < num; j++)
        {
            if (i % j == 0 || i == 1)
            {
                prime = false;
            }
            else
                prime = true;
        }
        if (prime == true)
        {
            primeCalculator.push_back(i);
            std::cout << primeCalculator[i] << " is prime.\n";
        }
    }
    return prime;
}
