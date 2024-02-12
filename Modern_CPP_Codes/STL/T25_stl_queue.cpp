#include <iostream>
#include <queue>

template <typename T>
class StackUsingQueues {
    private:
        std::queue<T> queue1;
        std::queue<T> queue2;

    public:
        void push(T value) {
            while (!queue1.empty()) {
                queue2.push(queue1.front());
                queue1.pop();
            }

            queue1.push(value);     // new value

            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        }

        void pop() {
            if (empty()) {
                std::cout << "Stack is empty. Cannot pop.\n";
                return;
            }
            queue1.pop();
        }

        T top() {
            if (empty()) {
                std::cout << "Stack is empty. No top element.\n";
                return NULL;
            }
            return queue1.front();   // return the front element of queue1
        }

        bool empty() const {
            return queue1.empty();
        }
};

int main() {
    StackUsingQueues<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << "\n";

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << "\n";

    return 0;
}
