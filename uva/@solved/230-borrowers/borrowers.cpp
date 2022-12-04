#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    vector<pair<string, string>> books;
    string book;
    while (getline(cin, book) && book != "END") {
        string title, author, token;
        bool is_title = false, is_title_end = false;
        stringstream ss(book);
        while (ss >> token) {
            if (token == "by") continue;
            if (token[0] == '"') {
                is_title = true;
            } else if (is_title_end) {
                is_title_end = false;
                is_title = false;
            }
            if (token[token.size() - 1] == '"') {
                is_title_end = true;
            }
            if (is_title) {
                if (title.empty())
                    title += token;
                else
                    title += " " + token;
            } else {
                if (author.empty())
                    author += token;
                else
                    author += " " + token;
            }
        }
        books.push_back(make_pair(author, title));
    }
    sort(books.begin(), books.end());
    // for (auto book : books) {
    //     cout << book.first << "-" << book.second << endl;
    // }
    bool loaned[books.size()];
    for (int i = 0; i < books.size(); i++) loaned[i] = false;
    vector<pair<string, string>> returned;
    string command;
    // commands
    while (getline(cin, command) && command != "END") {
        stringstream ss(command);
        string ins;
        ss >> ins;
        if (ins == "BORROW") {
            string book;
            getline(ss, book);
            book.erase(0, 1);
            for (int i = 0; i < books.size(); i++) {
                if (books[i].second == book) {
                    loaned[i] = true;
                    break;
                }
            }
        } else if (ins == "RETURN") {
            string book, author;
            getline(ss, book);
            book.erase(0, 1);
            for (int i = 0; i < books.size(); i++) {
                if (books[i].second == book) {
                    author = books[i].first;
                    break;
                }
            }
            returned.push_back(make_pair(author, book));
        } else if (ins == "SHELVE") {
            sort(returned.begin(), returned.end());
            for (auto pair : returned) {
                string book = pair.second;
                // find index in array
                int idx = 0, idx_before;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].second == book) {
                        idx = i;
                        break;
                    }
                }
                loaned[idx] = false;
                for (int i = idx - 1; i >= -1; i--) {
                    if (i == -1)
                        idx_before = -1;
                    else if (!loaned[i]) {
                        idx_before = i;
                        break;
                    }
                }
                if (idx_before == -1) {
                    cout << "Put " << books[idx].second << " first" << endl;
                } else {
                    cout << "Put " << books[idx].second << " after "
                         << books[idx_before].second << endl;
                }
            }
            returned.clear();
            cout << "END" << endl;
        }
    }
}
