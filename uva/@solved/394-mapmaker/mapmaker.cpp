#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, r, i = 0;
    cin >> n >> r;
    cin.ignore();

    map<string, int> index;  // name of array -> idx in the following arrays
    int dim[n];              // no of dimensions
    vector<int> c[n];        // constants c

    while (n--) {
        string name;
        cin >> name;
        index[name] = i;
        int base_i, sz_i, dim_i;
        vector<int> lb_i, ub_i;
        cin >> base_i >> sz_i >> dim_i;
        dim[i] = dim_i;
        for (int i = 0; i < dim_i; i++) {
            int lb_id, ub_id;
            cin >> lb_id >> ub_id;
            lb_i.push_back(lb_id);
            ub_i.push_back(ub_id);
        }
        // initialize vector c
        c[i].resize(dim_i + 1);
        c[i][dim_i] = sz_i;
        for (int j = dim_i - 1; j > 0; j--) {
            c[i][j] = c[i][j + 1] * (ub_i[j] - lb_i[j] + 1);
        }
        int c0 = base_i;
        for (int j = 0; j < dim_i; j++) {
            c0 -= c[i][j + 1] * lb_i[j];
        }
        c[i][0] = c0;
        i++;
    }

    while (r--) {
        string arr;
        vector<int> ref;
        cin >> arr;
        int arr_i = index[arr], dim_i = dim[arr_i];

        for (int i = 0; i < dim_i; i++) {
            int d;
            cin >> d;
            ref.push_back(d);
        }

        int addr = c[arr_i][0];

        for (int i = 0; i < ref.size(); i++) {
            addr += c[arr_i][i + 1] * ref[i];
        }

        cout << arr << "[";
        for (int i = 0; i < ref.size(); i++) {
            cout << ref[i];
            if (i != ref.size() - 1) cout << ", ";
        }
        cout << "] = " << addr << endl;
    }

    return 0;
}
