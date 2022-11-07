#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"

int main()
{

    // make a vector of ints
    //  std::vector<int> v;

    // make a map of strings to ints
    //  std::map<std::string, int> m;

    int A, S;
    std::cin >> A >> S;
    while (1)
    {
        leEntrada(A,S); 

        std::cin >> A >> S;
        if(A == 0) break; 
    }

    return (0);
}
