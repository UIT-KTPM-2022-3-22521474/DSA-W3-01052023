#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node* next;
};

bool is_valid_latex(string s) 
{
    stack<char> st;
    Node* head = NULL;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
            Node* newNode = new Node();
            newNode->data = c;
            newNode->next = head;
            head = newNode;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty() || (c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || (c == ']' && st.top() != '['))
            {
                return false;
            }
            st.pop();
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (is_valid_latex(s))
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}