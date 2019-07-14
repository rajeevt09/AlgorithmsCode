#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
       string expr("1*2+3+5*4/2-3*2");
       long val = evaluate_expr(expr);
       cout << val;
}

