#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int cs_size, econ_size;
        long long int cs_sum = 0, econ_sum = 0;
        cin >> cs_size >> econ_size;
        long long int cs_arr[cs_size];
        for (int j = 0; j < cs_size; j++) {
            cin >> cs_arr[j];
            cs_sum += cs_arr[j];
        }
        for (int j = 0; j < econ_size; j++) {
            int temp;
            cin >> temp;
            econ_sum += temp;
        }
        double cs_ave = double(cs_sum) / double(cs_size),
               econ_ave = double(econ_sum) / double(econ_size);
        int stud = 0;
        for (int j = 0; j < cs_size; j++) {
            if (cs_arr[j] > econ_ave && cs_arr[j] < cs_ave) stud++;
        }
        cout << stud << endl;
    }
}

// int main() {
//     int cases;
//     cin >> cases;
//     for (int i = 0; i < cases; i++) {
//         int cs, econ;
//         cin >> cs >> econ;
//         int cs_students[cs], cs_sum, econ_sum;
//         double cs_ave, econ_ave;
//         for (int j = 0; j < cs; j++) {
//             int temp;
//             cin >> temp;
//             cs_students[j] = temp;
//             // cout << cs_students[j] << endl;
//             cs_sum += temp;
//         }
//         for (int j = 0; j < econ; j++) {
//             int temp;
//             cin >> temp;
//             econ_sum += temp;
//         }
//         cs_ave = cs_sum / double(cs);
//         econ_ave = econ_sum / double(econ);
//         int stud = 0;
//         for (int j = 0; j < cs; j++) {
//             if (cs_students[j] > econ_ave && cs_students[j] < cs_ave) {
//                 cout << "test" << cs_students[j] << endl;
//             }
//         }
//         cout << stud << " " << econ_ave << " " << cs_ave << endl;
//     }
// }
