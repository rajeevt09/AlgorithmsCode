class Solution {
public:
    
    bool isPalin(string str)
    {
        int n = str.length();
        for(int i=0;i<n/2;i++)
        {
            if(str[i] != str[n-i-1]) return false;
        }
        return true;
    }
    
    bool checkPalin(string s1,string s2)
    {
        int s1len = s1.length();
        int s2len = s2.length();
        int minlen = std::min(s1len,s2len);
        string sMaxStr;
        if(s1len  > s2len)
        {
           sMaxStr = s1;
        }
        else if(s1len < s2len)
        {
            sMaxStr = s2;
        }
        int i=0;
        while ( i < minlen )
        {
            if(s1[i] != s2[i]) return false;
            i++;
        }
        if(sMaxStr.length() == 0) return true; // all character matched
        //reached end of one string and all characters are matched . check rest is palin
        return isPalin(sMaxStr.substr(i,sMaxStr.length()-i));
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<pair<string,int>> reversedPairs;
        vector<vector<int>> solution;
        int i=0;
        for(auto &word:words) {reversedPairs.push_back(make_pair(word,i++));};
        for(int i=0;i<words.size();i++)
        {
            string strRev = words[i];
            std::reverse(strRev.begin(),strRev.end());         
            reversedPairs.push_back(make_pair(strRev,i));
        }
        std::sort(reversedPairs.begin(),reversedPairs.end(),[]
                  (pair<string,int> &a,pair<string,int> &b){return a.first < b.first;});
            
        //now sequentially process the sorted strings outputting adjacent matches
        for(int i=0;i<reversedPairs.size() - 1;i++)
        {
            //skip strings that are same source
            if(reversedPairs[i].second == reversedPairs[i+1].second) continue;
            //compare strings i and (i+1)
            
            if(checkPalin(reversedPairs[i].first,reversedPairs[i+1].first))
            {
                vector<int> pair;
                pair.push_back(reversedPairs[i].second);
                pair.push_back(reversedPairs[i+1].second);
                solution.push_back(pair);    
            }    
        }
        return solution;
    }
};
