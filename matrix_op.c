#include "matrix_op.h" 
#include <stdio.h>

[cite_start]
void add_matrices(Matrix A, Matrix B, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void print_matrix(Matrix M) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f\t", M[i][j]);
        }
        printf("\n");
    }
}

void sub_matrices(Matrix A, Matrix B, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[i][j] - B[i][j];
        }
    }
}

    sub_matrices(A, B, Result);

    printf("\n--- A - B 的結果 ---\n");
    print_matrix(Result); 

    return 0;
}

// A^T = [a_ji]
void transpose_matrix(Matrix A, Matrix Result) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Result[i][j] = A[j][i]; // 核心邏輯：交換 i 和 j 索引
        }
    }
}

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
            Matrix Submatrix; 

            
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

            
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            TempCofactor[i][j] = sign * determinant_2x2(Submatrix[0][0], Submatrix[0][1], 
                                                      Submatrix[1][0], Submatrix[1][1]);
        }
    }

    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Adjoint[i][j] = TempCofactor[j][i];
        }
    }
}
int inverse_matrix(Matrix A, Matrix Inverse) {
    double det = determinant_3x3(A);

    
    if (det == 0) {
        printf("Error: Matrix is singular. Inverse does not exist.\n");
        return 0; // 不可逆
    }

    Matrix Adjoint;
    adjoint_matrix(A, Adjoint); 

    
    double det_inv = 1.0 / det;
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            Inverse[i][j] = Adjoint[i][j] * det_inv;
        }
    }
    return 1; // 可逆
}
