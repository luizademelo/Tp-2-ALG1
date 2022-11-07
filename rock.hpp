#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct resposta {
    int i_left; 
    int i_right; 
    double sum; 
} resposta; 

void leEntrada(int A, int S);
resposta subArranjoMaximo(vector<double> v, int left, int right);
resposta subArranjoMaximoMeio(vector<double> v, int left, int mid, int right); 

