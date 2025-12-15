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
double determinant_2x2(double a, double b, double c, double d) {
    return (a * d) - (b * c);
}
double determinant_3x3(Matrix A) {
    // 使用第一行展開
    double det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) 
               - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
               + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    return det;
}
void adjoint_matrix(Matrix A, Matrix Adjoint) {
    Matrix TempCofactor; // 暫存餘子矩陣
    int i, j, k_row, k_col;
    int sign = 1;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Matrix Submatrix; // 用於存放 2x2 子矩陣

            // 建立 Submatrix (移除第 i 行和第 j 列)
            int sub_i = 0;
            for (k_row = 0; k_row < SIZE; k_row++) {
                if (k_row == i) continue;
                int sub_j = 0;
                for (k_col = 0; k_col < SIZE; k_col++) {
                    if (k_col == j) continue;
                    Submatrix[sub_i][sub_j] = A[k_row][k_col];
                    sub_j++;
                }
                sub_i++;
            }

            // 計算餘子式 (Cofactor = (-1)^(i+j) * det(Submatrix))
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            TempCofactor[i][j] = sign * determinant_2x2(Submatrix[0][0], Submatrix[0][1], 
                                                      Submatrix[1][0], Submatrix[1][1]);
        }
    }

    // 伴隨矩陣 = 餘子矩陣的轉置
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Adjoint[i][j] = TempCofactor[j][i];
        }
    }
}
int inverse_matrix(Matrix A, Matrix Inverse) {
    double det = determinant_3x3(A);

    // 檢查是否可逆 (行列式不為零)
    if (det == 0) {
        printf("Error: Matrix is singular. Inverse does not exist.\n");
        return 0; // 不可逆
    }

    Matrix Adjoint;
    adjoint_matrix(A, Adjoint); // 計算伴隨矩陣

    // 逆矩陣 = (1 / Det(A)) * Adjoint(A)
    double det_inv = 1.0 / det;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Inverse[i][j] = Adjoint[i][j] * det_inv;
        }
    }
    return 1; // 可逆
}
