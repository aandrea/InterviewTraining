#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
	std::stack<char> stack;
	std::set<char> openers = { '(', '[', '{' };
	for(int i =0; i < s.size() ; ++i)
	{
		// OPTIMIZATION
		// If there are more elements in the stack that
		// length/2 it means that there are more openers
		// than closers => unbalanced 
		if (stack.size() > s.length() / 2) 
		{
			return "NO";
		}

		// STRATEGY: Pile up openers and un-pile them when
		// a closer arrives
		if(openers.find(s[i])!= openers.end())
		{
			stack.push(s[i]);            
		}
		else 
		{
			// Stack is already empty and the next
			// character is a closer => Unbalanced
			if (stack.empty()) 
			{
				return "NO";
			}
			else
			{
				// Un-pile the top, if top is an opener
				// find the matching closer
				char closer =' ';      
				switch(stack.top())
				{
					case '(': closer=')';break;
					case '{': closer='}';break;
					case '[': closer=']';break;
					default: break;                
				}
				stack.pop();
				// If the found closer is different to
				// the current character of the string
				// => Unbalanced
				if(closer!=s[i])
				{
					return "NO";
				}
			}
		}
	}
	
	// If the stack is empty after all the string was visited
	if (stack.empty())
		return "YES"; 	// => Balanced
	else
		return "NO";	// => Unbalanced

	return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

