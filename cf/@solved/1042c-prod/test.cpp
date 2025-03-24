#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;

    vector<ll> a(n);
    vector<ll> zeros, negatives, positives;
    vector<ll> negativeValues;
    ll removedNegative = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if(a[i] == 0) zeros.push_back(i + 1);
        else if (a[i] < 0) {
            negatives.push_back(i + 1);
            negativeValues.push_back(a[i]);
        }
        else positives.push_back(i + 1);
    }

    if(zeros.size() == n || (zeros.size() == n - 1 && negatives.size() == 1)){
        for (int i = 2; i <= n; ++i) {
            cout << 1 << ' ' << i << ' ' << 1 << '\n';
        }
    }
    else {
        sort(negativeValues.begin(), negativeValues.end());
        if(negatives.size() % 2 != 0) {
            auto itr = find(negatives.begin(), negatives.end(), negativeValues[0]);

            removedNegative = itr - negatives.begin() + 1;
            negatives.erase(itr);
        }

        for (int i = 1; i < positives.size(); ++i) {
            cout << 1 << ' ' << positives[i] << ' ' << positives[0] << '\n';
        }

        for (int i = 1; i < zeros.size(); ++i) {
            cout << 1 << ' ' << zeros[i] << ' ' << zeros[0] << '\n';
        }

        for (int i = 1; i < negatives.size(); ++i) {
            cout << 1 << ' ' << negatives[i] << ' ' << negatives[0] << '\n';
        }

        if (!zeros.empty() && removedNegative != -1) {
            cout << 1 << ' ' << zeros[0] << ' ' << removedNegative << '\n';
        } else if (!zeros.empty() && removedNegative == -1) {
            removedNegative = zeros[0];
        }

        if (removedNegative != -1) {
            cout << 2 << ' ' << removedNegative << '\n';
        }

        if (!negatives.empty() && !positives.empty()) {
            cout << 1 << ' ' << negatives[0] << ' ' << positives[0] << '\n';
        }
    }
}