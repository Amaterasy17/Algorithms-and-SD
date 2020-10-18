//#include <iostream>
//#include <vector>
//
//
//
//class StringHasher
//{
//public:
//    StringHasher(size_t prime = 17) : prime(prime) {}
//    size_t operator()(const std::string& str, const int& m)
//    {
//        int hash = 0;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            hash = (hash * prime + str[i]) % m;
//        }
//        return hash;
//    }
//private:
//    size_t prime;
//};
//
//class HashTable
//{
//public:
//    HashTable(int size): m(size), current_size(0) {
//        str.resize(m, "NIL");
//    }
//    ~HashTable()
//    {}
//    int Find(std::string& elem)
//    {
//        StringHasher hasher;
//        int hash = hasher(elem, m);
//        int stand_hash = hash;
//        int counter = 0;
//        int i = 1;
//        double c = 0.5;
//        while (str[hash] != "NIL")
//        {
//
//            if (counter - 1 == m)
//            {
//                return -1;
//            }
//            if (str[hash] == elem)
//            {
//                return hash;
//            }
//            hash = (int)(stand_hash + c * i + c * i * i) % m;
//            ++i;
//            ++counter;
//        }
//        std::string fail = "FAIL";
//        return -1;
//    }
//    std::string Delete(std::string& elem)
//    {
//        std::string ok = "OK";
//        std::string fail = "FAIL";
//        int number = Find(elem);
//        if (number == -1)
//        {
//            return fail;
//        }
//        str[number] = "DEL";
//        --current_size;
//        return ok;
//    }
//    std::string Add(std::string& elem)
//    {
//        if (Find(elem) != -1)
//        {
//            std::string fail = "FAIL";
//            return fail;
//        }
//        double a = (double)current_size / (double)m;
//        if (a >= 0.75)
//        {
//            std::vector<std::string> new_str (2 * m, "NIL");
//            str = std::move(ReHash(new_str));
//            m *= 2;
//        }
//        StringHasher hasher;
//        int hash = hasher(elem, m);
//        hash = Collision(hash, this->str);
//        str[hash] = std::move(elem);
//        ++current_size;
//        std::string ok = "OK";
//        return ok;
//    }
//    std::vector<std::string>& ReHash(std::vector<std::string>& vect)
//    {
//        StringHasher hasher;
//        int hash;
//        for (int i = 0; i < m; ++i)
//        {
//            if (str[i] != "NIL" && str[i] != "DEL")
//            {
//                hash = hasher(str[i], 2 * m);
//                hash = Collision(hash, vect);
//                vect[hash] = str[i];
//            }
//        }
//
//        return vect;
//    }
//    int Collision(int hash, std::vector<std::string>& buf)
//    {
//        int stand_hash = hash;
//        double c = 0.5;
//        int i = 1;
//        while (buf[hash] != "NIL" && buf[hash] != "DEL")//пока что del считается заполненной (занятой)
//        {
//            hash = (int)(stand_hash + c * i + c * i * i) % buf.size();
//            ++i;
//        }
//        return hash;
//    }
//private:
//    std::vector<std::string> str;
//    int m;
//    int current_size;
//
//
//};
//
//
//int main(int argc, const char* argv[]) {
//
//    HashTable table(8);
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
//            if (table.Find(str) == -1)
//                std::cout << "FAIL" << std::endl;
//            else
//                std::cout << "OK" << std::endl;
//            break;
//        }
//        case '+':
//        {
//            std::cout << (table.Add(str)) << std::endl;
//            break;
//        }
//        case '-':
//        {
//            std::cout << (table.Delete(str)) << std::endl;
//            break;
//        }
//        }
//    }
//
//    return 0;
//}
