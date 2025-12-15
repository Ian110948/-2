#include "matrix_op.h" // 包含我們剛才定義的標頭檔
#include <stdio.h>

[cite_start]// 範例實作：矩陣加法 [cite: 7]
void add_matrices(Matrix A, Matrix B, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 範例實作：顯示矩陣
void print_matrix(Matrix M) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f\t", M[i][j]);
        }
        printf("\n");
    }
}
// 實作：矩陣減法 (A - B)
void sub_matrices(Matrix A, Matrix B, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[i][j] - B[i][j];
        }
    }
}
// 測試矩陣減法
    sub_matrices(A, B, Result);

    printf("\n--- A - B 的結果 ---\n");
    print_matrix(Result); 

    return 0;
}
// 實作：轉置矩陣 (A -> Result)
// A^T = [a_ji]
void transpose_matrix(Matrix A, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[j][i]; // 核心邏輯：交換 i 和 j 索引
        }
    }
}
// 實作：矩陣乘法 (A * B)
// Result[i][j] = Sum(A[i][k] * B[k][j]) for k=0 to SIZE-1
void multiply_matrices(Matrix A, Matrix B, Matrix Result) {
    int i, j, k;
    double sum;
    for (i = 0; i < SIZE; i++) { // 遍歷 Result 的行
        for (j = 0; j < SIZE; j++) { // 遍歷 Result 的列
            sum = 0.0;
            for (k = 0; k < SIZE; k++) { // 計算點積
                sum += A[i][k] * B[k][j];
            }
            Result[i][j] = sum;
        }
    }
}
// 實作：元素級乘法 (A ∘ B)
// Result[i][j] = A[i][j] * B[i][j]
void elementwise_multiply(Matrix A, Matrix B, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[i][j] * B[i][j];
        }
    }
}
