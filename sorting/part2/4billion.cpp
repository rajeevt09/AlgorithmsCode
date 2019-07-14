#include <vector>
#include <string>
using namespace std;

/*
// we need to find missing number in 4 Billion Integers
// we have 10 Mb of available memory 
*/

// Available memory = 10 Mb
#define AVAIL_MEM 10 * 2^20

// divide the integers into blocks of Range size 4 Kb 
#define RANGE_SIZE 4 * 2^10
int main()
{
   cout << "Find misisng integer in a Billion Integers";
}

/*
 * Complete the find_an_integer_not_among_given_integers function below.
 */
int find_an_integer_not_among_given_integers(vector<int> nos) {
    /*
     * Write your code here.
     */
    
    
    //Lets examine Nibble by Nibble if there is a number missing
    for(int offset = 0 ; offset <= 12 ;offset+=4)
    {
        size_t map[16] = {0};
        for(int number :nos)
        {
            //get the nibble value at the bucket we are interested in
            int index = (number >> offset) & 0xf;
            map[index] = 1;
        }
        //check if the current bucket has a missing number
        for(size_t i =0; i < 16; i++)
        {
            if(map[i] == 0)
            {
                //bucket 'offset' has missing number
                return i<<offset;
            }
        }
    }
    return -1;    

}
