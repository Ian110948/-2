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
