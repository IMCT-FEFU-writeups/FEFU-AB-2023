#include <stdio.h>

FILE *fIn, *fOut;
int m_need, n_need;
void path(int m_left, int n_left, int m_right, int n_right) {
    extern FILE *fIn, *fOut;
    extern int m_need,n_need;
    int m_next = m_left + m_right;
    int n_next = n_left + n_right;

    if (m_need == m_next && n_need == n_next) {
        return;
    }
    if (m_need * n_next < m_next * n_need) {
        putc('L',fOut);
        path(m_left, n_left, m_next, n_next);
    }
    else {
        putc('R',fOut);
        path(m_next, n_next, m_right, n_right);
    }
}

int main() {
    extern FILE *fIn, *fOut;
    extern m_need, n_need;

    fIn = fopen("input.txt", "r");
    fOut = fopen("output.txt", "w");

    fscanf(fIn, "%d %d", &m_need, &n_need);

    path(0, 1, 1, 0);

    return 0;
}
