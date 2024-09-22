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
        root = insert(root, data);
    }

    void printInOrder()
    {
        printInOrder(root);
    }

    void printPreOrder()
    {
        printPreOrder(root);
    }
    
    void printPostOrder()
    {
        printPostOrder(root);
    }

    bool search(T data)
    {
        return search(root, data);
    }

    T findMin()
    {
        return findMin(root);
    }

    void remove(T data)
    {
        root = remove(root, data);
    }

    private:

    void printInOrder(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return;

        printInOrder(current->left);
        std::cout<<current->data<<" ";
        printInOrder(current->right);
    }

    void printPreOrder(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return;

        std::cout<<current->data<<" ";
        printPreOrder(current->left);
        printPreOrder(current->right);
    }

    bool search(std::shared_ptr<Node<T>> current, T data)
    {
        if(current == nullptr)
            return false;

        if(current->data == data)
            return true;

        if(data < current->data)
            return search(current->left, data);
        else
            return search(current->right, data);
    }

    void printPostOrder(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return;

        printPostOrder(current->left);
        printPostOrder(current->right);
        std::cout<<current->data<<" ";
    }


    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> current, T data)
    {
        if(current == nullptr)
        {
            auto newNode = std::make_shared<Node<T>>();
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if(data < current->data)
        {
            current->left = insert(current->left, data);
        }
        else
        {
            current->right = insert(current->right, data);
        }

        return current;
    }

    T findMin(std::shared_ptr<Node<T>> current)
    {
        if(current == nullptr)
            return T();

        if(current->left == nullptr)
            return current->data;

        return findMin(current->left);
    }

    std::shared_ptr<Node<T>> remove(std::shared_ptr<Node<T>> current, T data)
    {
        if(current == nullptr)
            return nullptr;

        if(data < current->data)
        {
            current->left = remove(current->left, data);
        }
        else if(data > current->data)
        {
            current->right = remove(current->right, data);
        }
        else
        {
            if(current->left == nullptr && current->right == nullptr)
            {
                return nullptr;
            }
            else if(current->left == nullptr)
            {
                return current->right;
            }
            else if(current->right == nullptr)
            {
                return current->left;
            }
            else
            {
                current->data = findMin(current->right);
                current->right = remove(current->right, current->data);
            }
        }

        return current;
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

    std::cout<<bst.search(5)<<std::endl;
    std::cout<<bst.search(100)<<std::endl;

    std::cout<<bst.findMin()<<std::endl;

    bst.remove(5);
    bst.printInOrder();
    std::cout<<std::endl;

    bst.remove(10);
    bst.printInOrder();
    std::cout<<std::endl;

    return 0;
}