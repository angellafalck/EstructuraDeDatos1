/*
Tarea 1: Evaluador de expresiones de infijas a postfijas
y mostrar resultado
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
int prioridad(char op) {

 switch (op) {
    case '*':
    case '/': return 2;
    case '+': 
    case '-': return 1;
    default: return 0;
 }
} 
string convertir(string in) {
    stack<char> pila;
    string posf = "";
    for (int i=0; i < in.size(); i++) {
    switch (in[i]) {
    case '+':
    case '-':
    case '*':
    case '/':
        while (!pila.empty() && prioridad(in[i]) <= prioridad(pila.top())) {
        posf += string(1,pila.top()) + " ";
        pila.pop();
        }
        pila.push(in[i]);
        break;
    default:
        while (isdigit(in[i]) || in[i] == '.') 
        posf += string(1, in[i++]);
        posf += " ";
        i--;
    }
    }
    while (!pila.empty()) {
    posf += string(1, pila.top()) + " ";
    pila.pop();
    }
    return posf;
}
double evaluar(string p) {
    stack<double> pila;
    double op1, op2;
    for (int i=0; i < p.size(); i+=2) {
    switch (p[i]) {

    case '*':
        op2 = pila.top(); pila.pop();
        op1 = pila.top(); pila.pop();
        pila.push(op1*op2);
        break;
    case '/':
        op2 = pila.top(); pila.pop();
        op1 = pila.top(); pila.pop();
        pila.push(op1 / op2);
        break;
    case '+':
        op2 = pila.top(); pila.pop();
        op1 = pila.top(); pila.pop();
        pila.push(op1 + op2);
        break;
    case '-':
        op2 = pila.top(); pila.pop();
        op1 = pila.top(); pila.pop();
        pila.push(op1 - op2);
        break;
    default:
        string aux = "";
        while (p[i] != ' ')
        aux += string(1, p[i++]);
        pila.push(atof(aux.c_str()));
        i--;
    }
    }
    return pila.top();
}
int main() {
    string s, p;
    cin >> s;
    p = convertir(s);
    cout << "Posfija: " << p << endl;
    cout << "Evaluada: " << evaluar(p) << endl;
    return 0;
}


