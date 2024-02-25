#include <iostream>
#include <string>

using namespace std;

int main() {
    int registers[10];
    int ram[1000];
    int t, ram_ptr = 0, ins = 0;
    string line;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--) {
        for (int i = 0; i < 10; i++) registers[i] = 0;
        for (int i = 0; i < 1000; i++) ram[i] = 0;
        ram_ptr = 0;
        ins = 0;
        while (getline(cin, line) && !line.empty()) {
            ram[ram_ptr++] = stoi(line, nullptr);
        }
        ram_ptr = 0;
        while (1) {
            int curr_ins = ram[ram_ptr++];
            int a = curr_ins / 100, b = (curr_ins / 10) % 10, c = curr_ins % 10;
            if (a == 1) {
                if (b == 0 && c == 0) {
                    ins++;
                    break;
                }
            } else if (a == 2) {
                // set register b to c
                registers[b] = c;
            } else if (a == 3) {
                // add c to register b
                registers[b] += c;
            } else if (a == 4) {
                // multiply register b by c
                registers[b] *= c;
            } else if (a == 5) {
                // set register b to the value of register c
                registers[b] = registers[c];
            } else if (a == 6) {
                // add register c to register b
                registers[b] += registers[c];
            } else if (a == 7) {
                // multiply register b by register c
                registers[b] *= registers[c];
            } else if (a == 8) {
                // set register b to RAM value with address (register c)
                registers[b] = ram[registers[c]];
            } else if (a == 9) {
                // set RAM value with address (register c) to value of register
                // b
                ram[registers[c]] = registers[b];
            } else if (a == 0) {
                // goto register b unless value of register c == 0
                if (registers[c] != 0) {
                    ram_ptr = registers[b];
                }
            }
            registers[b] %= 1000;
            ram[registers[c]] %= 1000;
            ins++;
        }
        cout << ins << endl;
        if (t != 0) cout << endl;
    }
}
