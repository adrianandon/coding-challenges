#include <iostream>
#include <memory>

template <typename T>
class Node
{
    public: 
    T data;
    std::shared_ptr<Node<T>> next;
};

template <typename T>
class Stack
{
    private:
    std::shared_ptr<Node<T>> head;

    public:
    Stack()
    {
        head = nullptr;
    }

    void push(T data)
    {
        auto newNode = std::make_shared<Node<T>>();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if(head == nullptr)
            return;

        head = head->next;
    }

    void printStack()
    {
        auto current = head;
        while(current != nullptr)
        {
            std::cout<<current->data<<" ";
            current = current->next;
        }
    }

    T top()
    {
        if(head == nullptr)
            return T();
        
        return head->data;
    }

};

int main()
{
    Stack<std::string> stack;

    stack.push("PLM");
    stack.push("WTF");
    stack.push("LOL");
    stack.push("LMAO");

    stack.printStack();
    std::cout<<std::endl;

    stack.pop();
    stack.pop();

    stack.printStack();
    std::cout<<std::endl;

    std::cout<<stack.top()<<std::endl;

    return 0;
}