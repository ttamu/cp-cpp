#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &ai : A) cin >> ai;
    int id = 0;
    for (int i = 0; i < N; i++) {
        if (id < i) continue;
        id = max(id, min(i + A[i] - 1, N - 1));
    }
    cout << id + 1 << endl;
}
