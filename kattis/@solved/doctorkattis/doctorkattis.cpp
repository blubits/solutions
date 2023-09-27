#include <bits/stdc++.h>

using namespace std;

set<tuple<int, int, string>> cats;
map<string, int> catmap;
map<string, int> catpri;

char name[20];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int command, inf;
        string cat_name;
        scanf(" %d", &command);
        //cout << "!!" << command << "!!" << endl;
        switch (command) {
            case 0:
                scanf(" %s %d", name, &inf);
                cat_name = name;
                cats.insert({inf, N, cat_name});
                catmap[cat_name] = inf;
                catpri[cat_name] = N;
                // for_each(cats.cbegin(), cats.cend(), [](auto x) {
                //     std::cout << get<0>(x) << '-' << get<2>(x) << endl;
                // });
                //cout << endl;
                break;
            case 1:
                scanf(" %s %d", name, &inf);
                cat_name = name;
                cats.erase({catmap[cat_name], catpri[cat_name], cat_name});
                catmap[cat_name] = min(100, catmap[cat_name] + inf);
                cats.insert({catmap[cat_name], catpri[cat_name], cat_name});
                // for_each(cats.cbegin(), cats.cend(), [](auto x) {
                //     std::cout << get<0>(x) << '-' << get<2>(x) << endl;
                // });
                //cout << endl;
                break;
            case 2:
                scanf(" %s", name);
                cat_name = name;
                cats.erase({catmap[cat_name], catpri[cat_name], cat_name});
                break;
            case 3:
                if (!cats.empty()) printf("%s\n", get<2>(*cats.rbegin()).c_str());
                else printf("The clinic is empty\n");
                break;
        }
    }
    return 0;
}