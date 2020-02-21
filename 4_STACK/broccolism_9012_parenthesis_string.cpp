#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<bool> STACK;



string vps(string input)
{
    while (!STACK.empty())
    {
        STACK.pop();
    }

    int len = input.length();

    for (int i = 0; i < len; ++i)
    {
        if (input[i] == '(')
            STACK.push(true);
        else if (input[i] == ')' && !STACK.empty())
            STACK.pop();
        else if (input[i] == ')' && STACK.empty())
            return "NO";
    }

    if (STACK.empty())
        return "YES";
    else
        return "NO";  
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int how_many;
    cin >> how_many;

    string input = "";
    while (how_many > 0)
    {
        //get an input.
        cin >> input;
        cout << vps(input) << '\n';

        --how_many;
    }

}