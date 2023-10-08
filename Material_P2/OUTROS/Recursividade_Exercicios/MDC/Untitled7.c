#include <stdio.h>

int mdc(int M, int N) {
    if (N > M) {
        return mdc(N, M);
    } else if (N == 0) {
        return M;
    } else {
        return mdc(N, M % N);
    }
}

int main() {
    int M, N;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &M, &N);
    printf("O MDC de %d e %d eh %d\n", M, N, mdc(M, N));
    return 0;
}
