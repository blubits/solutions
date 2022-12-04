#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> phonebook;
    int q;
    std::cin >> q;
    while (q--) {
        std::string query;
        std::cin >> query;
        if (query == "add") {
            int pn;
            std::string name;
            std::cin >> pn >> name;
            phonebook[pn] = name;
        } else if (query == "del") {
            int pn;
            std::cin >> pn;
            phonebook.erase(pn);
        } else if (query == "find") {
            int pn;
            std::cin >> pn;
            auto it = phonebook.find(pn);
            if (it != phonebook.end()) {
                std::cout << it->second << std::endl;
            } else {
                std::cout << "not found" << std::endl;
            }
        }
    }
}
