#include <iostream>
#include <vector>
using namespace std;
/* Practise Loops to walk 2D Array in Different Directions
*/


void print_cells_diagonal_up(int n)
{
   for(int col= 0; col < n ;col++)
   {
        int j = col;
        for(int i = 0; i < n - col  ;i++)
        {
            cout << "(" << i << "," << j << ")" << " " << "," << " ";
            j++;    
        }
        cout << endl;
   }
}

int main()
{
    cout << "TEST WALKS" << endl;
    print_cells_diagonal_up(5);
}
