#include <iostream>
#include <string>
#include <vector>

long long int hash(const std::string& s, long long int m) {
    long long int p = 1000000007, x = 263, h = 0;
    for (long long int i = s.size() - 1; i >= 0; i--) {
        h = (h * x + (long long int)(s[i])) % p;
    }
    return h % m;
}

struct HashNode {
    std::string str;
    HashNode* next;

    HashNode(std::string s) : str(s), next(nullptr) {}
};

class HashTable {
   private:
    long long int size;
    std::vector<HashNode*> ht;

   public:
    HashTable(long long int m) {
        size = m;
        ht.resize(m);
        for (long long int i = 0; i < m; i++) ht[i] = nullptr;
    }

    void add(std::string s) {
        long long int h = hash(s, size);
        if (!find(s)) {
            HashNode* hn = new HashNode(s);
            if (ht[h] == nullptr) {
                ht[h] = hn;
            } else {
                hn->next = ht[h];
                ht[h] = hn;
            }
        }
    }

    void check(long long int i) {
        HashNode* ptr = ht[i];
        while (ptr != nullptr) {
            std::cout << ptr->str << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    void remove(std::string s) {
        long long int h = hash(s, size);
        HashNode *ptr = ht[h], *ptr_before = ht[h];
        while (ptr != nullptr) {
            if (ptr->str == s) {
                // found a match!
                if (ptr_before->str == s) {
                    // we're at the start of the list; simply make the head
                    // pointer point to the next item in the list
                    ht[h] = ht[h]->next;
                } else {
                    // we're somewhere in the middle of the list; simply
                    // make the pointer to the previous node jump over the
                    // current node
                    ptr_before->next = ptr->next;
                }
                // in any case, free the deleted node
                free(ptr);
                // then exit
                return;
            }
            ptr_before = ptr;
            ptr = ptr->next;
        }
        // if we've reached this point, the item isn't in the list. don't do
        // anything
    }

    bool find(std::string s) {
        long long int h = hash(s, size);
        HashNode* ptr = ht[h];
        while (ptr != nullptr) {
            if (ptr->str == s) {
                // found a match!
                return true;
            }
            ptr = ptr->next;
        }
        // if we've reached this point, the item isn't in the list
        return false;
    }
};

int main() {
    long long int sz, q;
    std::cin >> sz >> q;
    HashTable ht(sz);
    while (q--) {
        std::string query;
        std::cin >> query;
        if (query == "add") {
            std::string w;
            std::cin >> w;
            ht.add(w);
        } else if (query == "check") {
            int i;
            std::cin >> i;
            ht.check(i);
        } else if (query == "find") {
            std::string w;
            std::cin >> w;
            if (ht.find(w)) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        } else if (query == "del") {
            std::string w;
            std::cin >> w;
            ht.remove(w);
        }
    }
    return 0;
}
