//#include <iostream>
//
//#include <algorithm>
//#define NOMINMAX
//
//template <typename T>
//class AvlTree
//{
//    struct Node
//    {
//        Node(const T& data) : data(data), left(nullptr), right(nullptr), height(1) {}
//        T data;
//        Node* left, * right;
//        size_t height;
//    };
//
//public:
//    AvlTree() : root(nullptr) {}
//    ~AvlTree()
//    {
//        destroyTree(root);
//    }
//
//    bool Has(const T& data)
//    {
//        Node* tmp = root;
//        while (tmp)
//        {
//            if (tmp->data == data)
//                return true;
//            else if (tmp->data < data)
//                tmp = tmp->right;
//            else
//                tmp = tmp->left;
//        }
//        return false;
//    }
//
//    void Add(const T& data)
//    {
//        root = addInternal(root, data);
//    }
//
//    void Remove(const T& data)
//    {
//        root = removeInternal(root, data);
//    }
//
//private:
//    Node* root;
//
//    void fixHeight(Node* node)
//    {
//        node->height = 1 + std::max (getHeight(node->left), getHeight(node->right));
//    }
//
//    size_t getHeight(Node* node)
//    {
//        return node ? node->height : 0;
//    }
//
//    int getBalance(Node* node)
//    {
//        return getHeight(node->right) - getHeight(node->left);
//    }
//
//    Node* rotateLeft(Node* node)
//    {
//        Node* tmp = node->right;
//        node->right = tmp->left;
//        tmp->left = node;
//
//        fixHeight(node);
//        fixHeight(tmp);
//
//        return tmp;
//    }
//
//    Node* rotateRight(Node* node)
//    {
//        Node* tmp = node->left;
//        node->left = tmp->right;
//        tmp->right = node;
//
//        fixHeight(node);
//        fixHeight(tmp);
//
//        return tmp;
//    }
//
//    Node* doBalance(Node* node)
//    {
//        fixHeight(node);
//
//        switch (getBalance(node))
//        {
//        case 2:
//        {
//            if (getBalance(node->right) < 0)
//                node->right = rotateRight(node->right);
//            return rotateLeft(node);
//        }
//        case -2:
//        {
//            if (getBalance(node->left) > 0)
//                node->left = rotateLeft(node->left);
//            return rotateRight(node);
//        }
//        default:
//            return node;
//        }
//    }
//
//    Node* findMin(Node* node)
//    {
//        while (node->left)
//            node = node->left;
//        return node;
//    }
//
//    Node* removeMin(Node* node)
//    {
//        if (!node->left)
//            return node->right;
//        node->left = removeMin(node->left);
//        return doBalance(node);
//    }
//
//    Node* addInternal(Node* node, const T& data)
//    {
//        if (!node)
//            return new Node(data);
//        if (node->data <= data)
//            node->right = addInternal(node->right, data);
//        else
//            node->left = addInternal(node->left, data);
//        return doBalance(node);
//    }
//
//    Node* removeInternal(Node* node, const T& data)
//    {
//        if (!node)
//            return nullptr;
//        if (node->data < data)
//        {
//            node->right = removeInternal(node->right, data);
//        }
//        else if (node->data > data)
//        {
//            node->left = removeInternal(node->left, data);
//        }
//        else
//        {
//            Node* left = node->left;
//            Node* right = node->right;
//
//            delete node;
//
//            if (!right)
//                return left;
//
//            /*
//             Необходимо сделать 2 модификации:
//             1. Из двух функций findMin и removeMin сделать одну -- findAndRemoveMin, которая делает работу этих двух за один проход.
//             2. Я вместо удаляемого подставляю минимальный элемент из правого поддерева. Вам нужно посмотреть на высоты правого и левого поддеревьев и использовать либо максимальный из левого, либо минимальный из правого, в зависимости от того, какое поддерево более глубокое (брать более глубокое).
//             */
//
//            Node* min = findMin(right);
//            min->right = removeMin(right);
//            min->left = left;
//
//            return doBalance(min);
//        }
//        return doBalance(node);
//    }
//
//    void destroyTree(Node* node)
//    {
//        if (node)
//        {
//            destroyTree(node->left);
//            destroyTree(node->right);
//            delete node;
//        }
//    }
//};
//
//int main(int argc, const char* argv[]) {
//    AvlTree<std::string> avlTree;
//
//    char op;
//    std::string str;
//    while (std::cin >> op >> str)
//    {
//        switch (op)
//        {
//        case '+':
//        {
//            avlTree.Add(str);
//            std::cout << "OK" << std::endl;
//            break;
//        }
//        case '-':
//        {
//            avlTree.Remove(str);
//            std::cout << "OK" << std::endl;
//            break;
//        }
//        case '?':
//        {
//            std::cout << (avlTree.Has(str) ? "YES" : "NO") << std::endl;
//        }
//        }
//    }
//    return 0;
//}
