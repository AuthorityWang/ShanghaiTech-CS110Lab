#include <emmintrin.h> /* header file for the SSE intrinsics */
#include <time.h>
#include <stdio.h>

float **a;
float **b;
float **c;
float **c2;

int n = 40000;
int p = 20000;

void init(void) {
    a = malloc(n * sizeof(float *));
    b = malloc(4 * sizeof(float *));
    c = malloc(n * sizeof(float *));
    c2 = malloc(n * sizeof(float *));
    for (int i = 0; i < n; ++i) {
        a[i] = malloc(4 * sizeof(float));
        c[i] = malloc(p * sizeof(float));
        c2[i] = malloc(p * sizeof(float));
    }
    for (int i = 0; i < 4; ++i) {
        b[i] = malloc(p * sizeof(float));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i][j] = (float) rand() / (float) RAND_MAX;
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < p; ++j) {
            b[i][j] = (float) rand() / (float) RAND_MAX;
        }
    }
}

void check_correctness(char *msg) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            if (c[i][j] != c2[i][j]) {
                printf("%s incorrect!\n", msg);
                return;
            }
        }
    }
}

void naive_matmul(void) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // c = a * b
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("naive: %f\n", (float) (end.tv_sec - start.tv_sec) + (float) (end.tv_nsec - start.tv_nsec) / 1000000000.0f);
}

void loop_unroll_matmul(void) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // c2 = a * b
    // TODO: implement me!

    // -------------------------------------------
    // to delete
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            c2[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                c2[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // -------------------------------------------


    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("unroll: %f\n", (float) (end.tv_sec - start.tv_sec) + (float) (end.tv_nsec - start.tv_nsec) / 1000000000.0f);
    check_correctness("loop_unroll_matmul");
}

void simd_matmul(void) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    // c2 = a * b
    // TODO: implement me!
    float **transform;
    transform = malloc(p * sizeof(float *));
    for (int i = 0; i < p; ++i) 
        transform[i] = malloc(4 * sizeof(float));
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < 4; ++j)
            transform[i][j] = b[j][i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            __m128 A = _mm_loadu_ps(a[i]);
            __m128 B = _mm_loadu_ps(transform[j]);
            __m128 C = _mm_mul_ps(A, B);
            c2[i][j] = C[0] + C[1] + C[2] + C[3];
        }
    }

    for (int i = 0; i < p; ++i)
        free(transform[i]);
    free(transform);

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("simd: %f\n", (float) (end.tv_sec - start.tv_sec) + (float) (end.tv_nsec - start.tv_nsec) / 1000000000.0f);
    check_correctness("simd_matmul");
}

void loop_unroll_simd_matmul(void) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    // c2 = a * b
    // TODO: implement me!

     // -------------------------------------------
    // to delete
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            c2[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                c2[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // -------------------------------------------

    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("unroll+simd: %f\n", (float) (end.tv_sec - start.tv_sec) + (float) (end.tv_nsec - start.tv_nsec) / 1000000000.0f);
    check_correctness("loop_unroll_simd_matmul");
}


int main(void) {
    init();

    naive_matmul();
    simd_matmul();
    loop_unroll_matmul();
    loop_unroll_simd_matmul();

    return 0;
}

