#include<iostream>
#include<stack>
#include<fstream>
using namespace std;
void PolskiZapis(ifstream& f)
{

	stack<int> st;
	int a, b, c;
	char p;
	int n;
	char op;
	while (!f.eof())
	{
		p = f.peek();
		if (p >='0' && p <= '9')
		{
			f >> n;
			st.push(n);
		
			
		}
		else {
			f >> op;
			switch (op)
			{
			case '+': {
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					a = st.top();
					
					st.pop();
				}
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					b = st.top();
					
					st.pop();
				}
				c = a + b;

				st.push(c);
			}break;
			case '-': {
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					a = st.top();
					st.pop();
				}
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					b = st.top();
					st.pop();
				}
				c = b - a;
				st.push(c);
			}break;
			case '/': {
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					a = st.top();
					st.pop();
				}
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					b = st.top();
					st.pop();
				}
				c = b /a ;
				st.push(c);
			}break;
			case '*': {
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					a = st.top();
					st.pop();
				}
				if (st.empty())
				{
					cout << "error!";
				}
				else
				{
					b = st.top();
					st.pop();
				}
				c = a * b;
				st.push(c);
			}break;
			}
		}
		if (f.peek() == ';') {
			cout << st.top() << " ";
			st.pop();
			f.ignore();
		}

		f.ignore(1, ' ');
	}
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

}
int main()
{
	ifstream f("exp.txt");
	PolskiZapis(f);


	system("pause");
	return 0;
}
