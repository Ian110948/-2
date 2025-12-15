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

// (之後會新增乘法、轉置、行列式等所有函數宣告)

#endif
