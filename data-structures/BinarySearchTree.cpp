#include <iostream>
#include <memory>

template <typename T>
class Node
{
    public: 
    T data;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
};

template <typename T>
    class BinarySearchTree
{

    private:
    std::shared_ptr<Node<T>> root;

    public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        auto newNode = std::make_shared<Node<T>>();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if(root == nullptr)
        {
            root = newNode;
            return;
        }

        autor current = root;
        while(true)
        {
            if(data < current->data)
            {
                if(current->left == nullptr)
                {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            else
            {
                if(current->right == nullptr)
                {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }

        }
    }


    void printInOrder()
    {
        printInOrder(root);
    }

    void printInOrder(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return;

        printInOrder(current->left);
        std::cout<<current->data<<" ";
        printInOrder(current->right);
    }

    void printPreOrder()
    {
        printPreOrder(root);
    }

    void printPreOrder(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return;

        std::cout<<current->data<<" ";
        printPreOrder(current->left);
        printPreOrder(current->right);
    }

    void printPostOrder()
    {
        printPostOrder(root);
    }

    void printPostOrder(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return;

        printPostOrder(current->left);
        printPostOrder(current->right);
        std::cout<<current->data<<" ";
    }

};

int main()
{
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    bst.printInOrder();
    std::cout<<std::endl;

    bst.printPreOrder();
    std::cout<<std::endl;

    bst.printPostOrder();
    std::cout<<std::endl;

    return 0;
}