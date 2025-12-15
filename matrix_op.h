#ifndef MATRIX_OP_H // 避免重複包含 (Include Guard)
#define MATRIX_OP_H 

[cite_start]#define SIZE 3 // 定義矩陣是 3x3 [cite: 8, 28]

// 使用 typedef 定義一個 3x3 的矩陣型態，這樣在函數參數中會更方便
typedef double Matrix[SIZE][SIZE]; 

// --- 函數宣告 (Function Declarations) ---
// 1. 輔助函數：用於顯示矩陣
void print_matrix(Matrix M);

[cite_start]// 2. 基礎運算：加法 [cite: 7]
void add_matrices(Matrix A, Matrix B, Matrix Result);

[cite_start]// 3. 基礎運算：減法 [cite: 13]
void sub_matrices(Matrix A, Matrix B, Matrix Result);

// 4. 線性運算：矩陣乘法
void multiply_matrices(Matrix A, Matrix B, Matrix Result);

// 5. 線性運算：轉置
void transpose_matrix(Matrix A, Matrix Result);

// 6. 線性運算：元素級乘法
void elementwise_multiply(Matrix A, Matrix B, Matrix Result);
// 7. 進階運算：計算 2x2 矩陣行列式 (輔助函數)
double determinant_2x2(double a, double b, double c, double d);

// 8. 進階運算：計算 3x3 矩陣行列式
double determinant_3x3(Matrix A);

// 9. 進階運算：計算餘子矩陣 (Cofactor Matrix)
void cofactor_matrix(Matrix A, Matrix Cofactor);

// 10. 進階運算：計算伴隨矩陣 (Adjoint Matrix)
void adjoint_matrix(Matrix A, Matrix Adjoint);

// 11. 進階運算：計算逆矩陣 (Inverse Matrix)
int inverse_matrix(Matrix A, Matrix Inverse); // 回傳值 int 用於表示是否可逆 (0=不可逆, 1=可逆)
