#include <iostream>
#include <stack>
#include <string>

class Queue {
private:
    std::stack<std::string> stack1, stack2;

    // Transfer elements from stack1 to stack2
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    // Enqueue an element to the queue
    void enqueue(const std::string &item) {
        stack1.push(item);
    }

    // Dequeue an element from the queue
    std::string dequeue() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        if (stack2.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        std::string item = stack2.top();
        stack2.pop();
        return item;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return stack1.empty() && stack2.empty();
    }

    // Display the contents of the queue
    void display() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        std::stack<std::string> tempStack = stack2;
        while (!tempStack.empty()) {
            std::cout << tempStack.top() << "\n";
            tempStack.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue batmanQueue;

    // Add Batman's weapons and shields to the queue
    batmanQueue.enqueue("Batarang");
    batmanQueue.enqueue("Grapple Gun");
    batmanQueue.enqueue("Explosive Gel");
    batmanQueue.enqueue("Batclaw");
    batmanQueue.enqueue("Cape Glide");
    batmanQueue.enqueue("Smoke Pellet");

    // Display the contents of the queue
    std::cout << "Batman's gadgets in the queue:\n";
    batmanQueue.display();

    return 0;
}
