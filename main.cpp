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
        vector<double> v = leEntrada(A, S);
        resposta r = subArranjoMaximo(v, 0, v.size() - 1);
        cout << r.i_left + 1 << " " << r.i_right + 1 << '\n';
        
        std::cin >> A >> S;
        if (A == 0)
            break;
    }

    return (0);
}
