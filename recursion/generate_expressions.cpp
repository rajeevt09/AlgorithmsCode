bool isOperand(char c)
{
    if( c >= '0' && c <= '9')
       return true;
    return false;
}

bool isOp(char c)
{
   if(c == '#' || c == '*' || c == '+' )
     return true;
   return false;
}


typedef enum _e_op
{
   eAdd = 0,
   eMult,
   ejoin
}eop;

int opTable[] = {1,2,3};
                

int getPrec(char c)
{
     int myop;
     switch(c)
     {
         case '+' :
	       myop = 0;
               break;
         case '*' :
                myop = 1;
                break;
         case '#' :
                myop = 2;
                break;
         
     }
    return opTable[myop];
}

void get_postfix(string &result,string &postfix)
{
    stack<char> st;
    for(char c:result)
    {
        //cout << c << "," ;
        if(isOperand(c))
        {
            postfix.push_back(c);
        }
        else if(isOp(c))
        {
            int prec = getPrec(c);
            while(!st.empty() && (getPrec(st.top()) >= prec))
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
}

long evaluate_expr(string &expr)
{
     long result = 0;
     stack<long> s;
     string postfix;
     get_postfix(expr,postfix);
     cout << endl << "P " << postfix << endl;

     for(char c:postfix)
     {
          if(isOperand(c))
          {
             long val = atoi(&c);       
             s.push(val);
          }
          else if(isOp(c) && s.size() >= 2)
          {
              long aval = s.top();
              s.pop();   
              long bval = s.top();
              s.pop();
              long expr;
              switch(c)
              {
                   case '+':
                      expr = aval + bval;
                      break;
                   case '*':
                      expr = aval * bval;
                      break;
                   case '#':
                      expr = bval*10 + aval;
                      break;                   
                }
                s.push(expr);
             }
     }
     result = s.top();
     s.pop();

     return result;          
}

vector<char> operators = {{'+'},{'*'},{'#'}};
void generate(string s,size_t index,string pattern,vector<string> &solutions,long target)
{
    if(s.length() == 0) return;
    if(index  >= s.length() -1)
    {
        pattern.push_back(s[index]);    
        if(evaluate_expr(pattern) == target)
        {
            string out;
            for(char c:pattern)
            {
                if(c != '#') out.push_back(c);    
            }
            cout << out << endl;
            solutions.push_back(out);
        }
        return;
    }
    pattern.push_back(s[index]);
    for(char op:operators)
    {
        pattern.push_back(op);
        generate(s,index+1,pattern,solutions,target);
        pattern.pop_back();
    }
}

/*
 * Complete the function below.
 */
vector <string> generate_all_expressions(string s, long target) {
     string pattern = "";
     vector<string> solutions;
     generate(s,0,pattern,solutions,target);
     return solutions;
}

