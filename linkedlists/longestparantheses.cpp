/*
 * Complete the function below.
 */
int find_max_length_of_matching_parentheses(string brackets) {
    std::stack<char> ss;
    int max_so_far = 0;
    int local_max = 0;
    for(char c:brackets)
    {
        if(c == '(') 
        {
            ss.push(c);
            local_max = 0;
        }
        else if(!ss.empty() && (c == ')'))
        {
          if(ss.top() != '(')
          {
              local_max = ss.top();
              ss.pop();
          }
          if(!ss.empty() && ss.top() == '(')
          {
             ss.pop();
             local_max++;
          }
          while(!ss.empty() && ss.top() != '(')
          {
              local_max = local_max + ss.top();
              ss.pop();
          }
          ss.push(local_max);
        }
        if(max_so_far < local_max) max_so_far = local_max;
    }
    return max_so_far*2;          
}
