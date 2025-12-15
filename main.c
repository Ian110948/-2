#include <stdio.h>
#include "matrix_op.h" // 包含我們的函式庫

int main() {
    // 範例矩陣 (3x3)
    Matrix A = {{1.0, 2.0, 3.0}, 
                {4.0, 5.0, 6.0}, 
                {7.0, 8.0, 9.0}};
    
    Matrix B = {{9.0, 8.0, 7.0}, 
                {6.0, 5.0, 4.0}, 
                {3.0, 2.0, 1.0}};

    Matrix Result;

    printf("--- 矩陣 A ---\n");
    print_matrix(A);

    printf("--- 矩陣 B ---\n");
    print_matrix(B);
    
    [cite_start]// 測試矩陣加法 [cite: 7]
    add_matrices(A, B, Result);

    printf("--- A + B 的結果 ---\n");
    print_matrix(Result); 

    return 0;
}
