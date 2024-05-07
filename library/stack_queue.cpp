// Todo : 컨테이너 어댑터 (container adapter)
// '다른 컨테이너를 기반으로 새로운 기능을 제공하는 컨테이너'라고 할 수 있습니다.
// 즉, 기존의 컨테이너를 감싸서 새로운 인터페이스를 제공합니다.

// 1. stack : LIFO 스택
// 2. queue : FIFO 큐

// Todo : 스택 (std::stack)
// Todo : 큐 (std::queue)

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
  // Todo : 스택
  stack<int> myStack;

  myStack.push(1);
  myStack.push(2);

  myStack.pop();

  myStack.size();

  // Todo : 큐
  queue<int> myQueue;
  myQueue.push(1);
  myQueue.push(2);

  myQueue.front();
  myQueue.back();
  return 0;
}
