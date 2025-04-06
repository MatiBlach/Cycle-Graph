#include <iostream>
using namespace std;

const int N = 100;

void dfs(int macierz_s[][N], int w, bool odwiedzono[], int v) {
    odwiedzono[v] = true;
    for (int i = 0; i < w; i++) {
        if (macierz_s[v][i] == 1 && !odwiedzono[i]) {
            dfs(macierz_s, w, odwiedzono, i);
        }
    }
}

bool czyCykl(int macierz_s[][N], int w) {
    int krawedzie = 0;
    int stopien_w[N] = { 0 };
    bool odwiedzono[N] = { false };

    dfs(macierz_s, w, odwiedzono, 0); // czy graf spojny
    for (int i = 0; i < w; i++) {
        if (!odwiedzono[i]) {
            return false;
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = i + 1; j < w; j++) {
            if (macierz_s[i][j] == 1) {
                stopien_w[i]++;
                stopien_w[j]++;
                krawedzie++;
            }
        }
    }

    if (krawedzie != w) {
        return false;
    }

    for (int i = 0; i < w; i++) { //czy wychodza 2 krawedzie
        if (stopien_w[i] != 2) {
            return false;
        }
    }

    return true;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int w; 
        cin >> w;
        int macierz_s[N][N] = { false };
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                macierz_s[i][j] = c - '0';
            }
        }
        cout << (czyCykl(macierz_s, w) ? 1 : 0) << endl;
    }
    return 0;
}
