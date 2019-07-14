/*
 * Complete the function below.
 */
string sortCharacters(string inString) {
    size_t counts[257] = {0};
    string results = inString;
    //count occurenecs of each character
    for(char c:inString)
    {
        //cout << c;
        counts[c+1]++;
    }
    //update cumulative counts
    for(size_t i = 0; i < 256; i++)
    {
        counts[i+1] += counts[i];
    }
    //copy each char in inString to correct location in outString
    for(char c:inString)
    {
        results[counts[c]++] =  c;
        
    }
    return results;

}

