#include <iostream>
#include <queue>

int main() 
{
	//Siehe auch: queue | dqueue
	std::priority_queue<int> pQueue;
	pQueue.push(2);
	pQueue.push(33);
	pQueue.push(12);
	pQueue.push(-1);
	pQueue.push(45);
	pQueue.push(8);

	while (!pQueue.empty())
	{
		std::cout << pQueue.top() << std::endl;
		pQueue.pop();
	}
}