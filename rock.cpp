#include "rock.hpp"
#include <bits/stdc++.h>

using namespace std; 

void imprimeVetor(vector<double> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " "; 
    cout << '\n'; 
}

void imprimeResposta(resposta r)
{
    cout << "indice esquerdo: " << r.i_left; 
    cout << "\nindice direito: " << r.i_right;
    cout << "\nsoma: " << r.sum << '\n'; 
}

void leEntrada(int A, int S)
{

    vector<double> v(S,0);

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < S; j++)
        {
            double avaliacao;
            cin >> avaliacao;
            v[j] += avaliacao;
        }
    }

    resposta r = subArranjoMaximo(v, 0, v.size()-1); 
    cout << r.i_left + 1 << " " << r.i_right + 1<< '\n'; 
 
    return; 
}

resposta subArranjoMaximo(vector<double> v, int left, int right)
{
    resposta r; 
    if(left == right)
    {
        r.i_left = r.i_right = left; 
        r.sum = v[left]; 
        return r; 
    }
    int meio = floor((left + right) / 2.0); 
    resposta r_left = subArranjoMaximo(v, left, meio); 
    resposta r_right = subArranjoMaximo(v, meio+1, right); 
    resposta r_meio = subArranjoMaximoMeio(v, left, meio, right);
    if(r_left.sum >= r_right.sum && r_left.sum >= r_meio.sum) return r_left; 
    if(r_right.sum >= r_left.sum && r_right.sum >= r_meio.sum) return r_right; 
    return r_meio; 
    
}

resposta subArranjoMaximoMeio(vector<double> v, int left, int mid, int right)
{
    double left_sum = -100; // nenhuma soma do vetor vai ser menor que -100 
    double right_sum = -100; 
    double sum = 0;
    int max_i_left; 
    int max_i_right; 

    for(int i = mid; i >= left; i--)
    {
        sum += v[i]; 
        if(sum > left_sum)
        {
            left_sum = sum; 
            max_i_left = i; 
        }
    }
    sum = 0; 
    for(int i = mid+1; i <= right; i++)
    {
        sum += v[i]; 
        if(sum > right_sum)
        {
            right_sum = sum; 
            max_i_right = i; 
        }
    }
    resposta r; 
    r.i_left = max_i_left; 
    r.i_right = max_i_right; 
    r.sum = right_sum + left_sum; 
    return r;
}
