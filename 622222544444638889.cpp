#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
int n, k;
int contor_pasi = 0;
ull Pascal(int n, int k) {
    ++contor_pasi;
    if (n == k || k == 0)
        return 1;
    return Pascal(n - 1, k - 1) + Pascal(n - 1, k);
}
ull comb_form_rec(ull**Comb,int n, int k) {
    ++contor_pasi;
    if (n == k || k == 0)
        return 1;
    if (Comb[n - 1][k - 1] == 0)
        Comb[n - 1][k - 1] = comb_form_rec(Comb,n - 1, k - 1);
    if (Comb[n - 1][k] == 0)
        Comb[n - 1][k] = comb_form_rec(Comb,n - 1, k);
    return Comb[n - 1][k - 1] + Comb[n - 1][k];
}
int main() {
    cin >> n >> k;
    ull **Comb = new ull*[n + 1];
    for (int i = 0; i <= n; ++i) Comb[i] = new ull[n + 1];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) Comb[i][j] = 0;

    auto start = high_resolution_clock::now();
    cout << "C("<<n<<","<<k<<")= " << Pascal(n, k) <<
        "\nnumarul de pasi: " << contor_pasi;
    auto stop = high_resolution_clock::now();
    auto timp = duration_cast<microseconds>(stop - start);
    cout << "\nmicrosecunde: " << timp.count() << "\nsecunde: "
        << timp.count() * pow(10, -6);

    contor_pasi = 0;

    start = high_resolution_clock::now();
    cout << "\n\nFolosind memoizare:\nC(" << n << "," << k <<
        ")= " << comb_form_rec(Comb,n, k) <<
        "\nnumarul de pasi: " << contor_pasi;
    stop = high_resolution_clock::now();
    timp = duration_cast<microseconds>(stop - start);
    cout << "\nmicrosecunde: " << timp.count() << "\nsecunde: "
        << timp.count() * pow(10, -6);

    for (int i = 1; i <= n; ++i)
        delete[]Comb[i];
    delete[]Comb;
    Comb = NULL;
    return 0;
}