#include <iostream>
#include <stack>
#include <algorithm>
#define NOMINMAX




template <typename T>
class AvlTree {

 class Node
{
public:
    Node(const T& data) : data(data), left(nullptr), right(nullptr), height(1), count_nodes(0) {}
    Node* left;
    Node* right;
    int height;
    int countNodes;
    T data;
};
public:
    AvlTree() : root(nullptr) {}
    ~AvlTree()
    {
        destroyTree(root);
    }

    bool Find(const T& data)
    {
        Node* tmp = root;
        while (tmp)
        {
            if (tmp->data == data)
                return true;
            else if (tmp->data < data)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }
        return false;
    }
    Node& kStatistic(Node* node, int k, bool a)//а = для определения из какой ветки пришло
    {
        Node* l = node->left;
        Node* r = node->right;
        if(k == l.countNodes && a)
        {
            return *this;
        }
        if (k == node.countNodes)
        {
            return (*node);
        }
        if (l < k)
        {
            kStatistic(node->left, k);
        }
        
    }
    void Add(const T& data)
    {
        root = addInternal(root, data);
    }

    void Remove(const T& data)
    {
        root = removeInternal(root, data);
    }

private:
    Node* root;

    void fixHeight(Node* node)
    {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
    void fixCountNodes(Node* node)
    {
        node->count_nodes = getCountNodes(node -> left) + getCountNodes(node -> right) + 1;
    }

    int getCountNodes(Node* node)
    {
        return node ? node->count_nodes : 0;
    }
    size_t getHeight(Node* node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node* node)
    {
        return getHeight(node->right) - getHeight(node->left);
    }

    Node* rotateLeft(Node* node)
    {
        Node* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;

        fixHeight(node);
        fixCountNodes(node);
        fixHeight(tmp);
        fixCountNodes(tmp);

        return tmp;
    }

    Node* rotateRight(Node* node)
    {
        Node* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;

        fixHeight(node);
        fixCountNodes(node);
        fixHeight(tmp);
        fixCountNodes(tmp);

        return tmp;
    }

    Node* doBalance(Node* node)
    {
        fixHeight(node);
        fixCountNodes(node);
        switch (getBalance(node))
        {
        case 2:
        {
            if (getBalance(node->right) < 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        case -2:
        {
            if (getBalance(node->left) > 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        default:
            return node;
        }
    }

    Node* findMin(Node* node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* removeMin(Node* node)
    {
        if (!node->left)
            return node->right;
        node->left = removeMin(node->left);
        return doBalance(node);
    }

    Node* addInternal(Node* node, const T& data)
    {
        if (!node)
            return new Node(data);
        if (node->data <= data)
            node->right = addInternal(node->right, data);
        else
            node->left = addInternal(node->left, data);
        return doBalance(node);
    }

    Node* removeInternal(Node* node, const T& data)
    {
        if (!node)
            return nullptr;
        if (node->data < data)
        {
            node->right = removeInternal(node->right, data);
        }
        else if (node->data > data)
        {
            node->left = removeInternal(node->left, data);
        }
        else
        {
            Node* left = node->left;
            Node* right = node->right;

            delete node;

            if (!right)
                return left;

            /*
             Необходимо сделать 2 модификации:
             1. Из двух функций findMin и removeMin сделать одну -- findAndRemoveMin, которая делает работу этих двух за один проход.
             2. Я вместо удаляемого подставляю минимальный элемент из правого поддерева. Вам нужно посмотреть на высоты правого и левого поддеревьев и использовать либо максимальный из левого, либо минимальный из правого, в зависимости от того, какое поддерево более глубокое (брать более глубокое).
             */

            Node* min = findMin(right);
            min->right = removeMin(right);
            min->left = left;

            return doBalance(min);
        }
        return doBalance(node);
    }

    void destroyTree(Node* node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main(int argc, const char* argv[]) {
    AvlTree<std::string> avlTree;

    char op;
    std::string str;
    while (std::cin >> op >> str)
    {
        switch (op)
        {
        case '+':
        {
            avlTree.Add(str);
            std::cout << "OK" << std::endl;
            break;
        }
        case '-':
        {
            avlTree.Remove(str);
            std::cout << "OK" << std::endl;
            break;
        }
        case '?':
        {
            std::cout << (avlTree.Find(str) ? "YES" : "NO") << std::endl;
        }
        }
    }
    return 0;
}
