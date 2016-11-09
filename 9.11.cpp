#include<iostream>
#include<queue>
using namespace std;
int minElement(queue<int> &q)
{
	int min = q.front();
	q.pop();
	queue<int> newqueue;
	while (!q.empty())
	{
		
		
		if (min > q.front())
		{
			newqueue.push(min);
			min = q.front();
		}
		else
		{
          newqueue.push(q.front());
		}
		q.pop();
	}
	q = newqueue;
	return min;
}
int main()
{
	queue<int> qu;
	qu.push(1);
	qu.push(-1);
	qu.push(3);
	qu.push(-3);
	qu.push(-6);
	cout << "Min: " << minElement(qu) << "\n";
	system("pause");
	return 0;
}
