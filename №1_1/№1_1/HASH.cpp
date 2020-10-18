//#include <iostream>
//#include <vector>
//
//const size_t DEFAULT_SIZE = 8;
//const size_t MAX_ALPHA = 3;
//
//template <typename T>
//struct HashTableNode
//{
//    HashTableNode() : next(nullptr) {}
//    HashTableNode(const T& key, HashTableNode<T>* next) : data(key), next(next) {}
//    T data;
//    HashTableNode<T>* next;
//};
//
//class StringHasher
//{
//public:
//    StringHasher(size_t prime = 71) : prime(prime) {}
//    size_t operator()(const std::string& str)
//    {
//        size_t hash = 0;
//        for (int i = 0; i < str.size(); i++)
//        {
//            hash = hash * prime + str[i];
//        }
//
//        return hash;
//    }
//private:
//    size_t prime;
//};
//
//template <typename T, typename Hasher>
//class HashTable
//{
//public:
//    HashTable(size_t initial_size = DEFAULT_SIZE) : size(0), table(initial_size, nullptr) {}
//
//    ~HashTable()
//    {
//        for (int i = 0; i < table.size(); i++)
//        {
//            HashTableNode<T>* node = table[i];
//
//            while (node != nullptr)
//            {
//                HashTableNode<T>* tmpNext = node->next;
//                delete node;
//                node = tmpNext;
//            }
//        }
//    }
//
//    bool Add(const T& key)
//    {
//        if (size > table.size()* MAX_ALPHA)
//        {
//            grow();
//        }
//
//        size_t hash = hasher(key) % table.size();
//
//        HashTableNode<T>* node = table[hash];
//
//        while (node != nullptr)
//        {
//            if (node->data == key)
//                return false;
//            node = node->next;
//        }
//
//        table[hash] = new HashTableNode<T>(key, table[hash]);
//
//        size++;
//        return true;
//    }
//
//    bool Delete(const T& key)
//    {
//        size_t hash = hasher(key) % table.size();
//
//        HashTableNode<T>* node = table[hash];
//        HashTableNode<T>* prev = nullptr;
//
//        while (node != nullptr)
//        {
//            if (node->data == key)
//                break;
//            prev = node;
//            node = node->next;
//        }
//
//        if (node == nullptr)
//            return false;
//
//        if (prev == nullptr)
//        {
//            table[hash] = node->next;
//        }
//        else
//        {
//            prev->next = node->next;
//        }
//
//        size--;
//        delete node;
//        return true;
//    }
//
//    bool Has(const T& key)
//    {
//        size_t hash = hasher(key) % table.size();
//
//        HashTableNode<T>* node = table[hash];
//
//        while (node != nullptr)
//        {
//            if (node->data == key)
//                return true;
//            node = node->next;
//        }
//
//        return false;
//    }
//
//private:
//    void grow()
//    {
//        std::vector<HashTableNode<T>*> newTable(table.size() * 2, nullptr);
//
//        for (int i = 0; i < table.size(); i++)
//        {
//            HashTableNode<T>* node = table[i];
//
//            while (node != nullptr)
//            {
//                HashTableNode<T>* tmpNext = node->next;
//
//                size_t newHash = hasher(node->data) % newTable.size();
//                node->next = newTable[newHash];
//                newTable[newHash] = node;
//
//                node = tmpNext;
//            }
//        }
//
//        table = std::move(newTable);
//    }
//
//    Hasher hasher;
//
//    size_t size;
//    std::vector<HashTableNode<T>*> table;
//};
//
//int main(int argc, const char* argv[]) {
//
//    HashTable<std::string, StringHasher> table;
//
//    char op;
//    std::string str;
//
//    while (std::cin >> op >> str)
//    {
//        switch (op)
//        {
//        case '?':
//        {
//            std::cout << (table.Has(str) ? "OK" : "FAIL") << std::endl;
//            break;
//        }
//        case '+':
//        {
//            std::cout << (table.Add(str) ? "OK" : "FAIL") << std::endl;
//            break;
//        }
//        case '-':
//        {
//            std::cout << (table.Delete(str) ? "OK" : "FAIL") << std::endl;
//            break;
//        }
//        }
//    }
//
//    return 0;
//}
