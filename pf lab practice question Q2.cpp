#include <stdio.h>
#include <math.h>  // For pow() in Nilpotent check


void inputMatrix(int matrix[5][5], int *rows, int *cols);
void printMatrix(int matrix[5][5], int rows, int cols);
int isSquare(int rows, int cols);
int isZero(int matrix[5][5], int rows, int cols);
int isIdentity(int matrix[5][5], int rows, int cols);
int isDiagonal(int matrix[5][5], int rows, int cols);
int isScalar(int matrix[5][5], int rows, int cols);
int isUpperTriangular(int matrix[5][5], int rows, int cols);
int isLowerTriangular(int matrix[5][5], int rows, int cols);
int isSymmetric(int matrix[5][5], int rows, int cols);
int isSkewSymmetric(int matrix[5][5], int rows, int cols);
int isSingular(int matrix[5][5], int n);
int isIdempotent(int matrix[5][5], int n);
int isNilpotent(int matrix[5][5], int n);
void multiplyMatrix(int a[5][5], int b[5][5], int result[5][5], int n);

int main() {
    int matrix[5][5];
    int rows, cols;

    
    printf("       MATRIX TYPE IDENTIFICATION        \n");
    
    inputMatrix(matrix, &rows, &cols);
    printMatrix(matrix, rows, cols);

    printf("\nMatrix Properties:\n");
    

    
    if (isSquare(rows, cols))
        printf("? Square Matrix\n");
    else
        printf("? Rectangular Matrix\n");

    if (isZero(matrix, rows, cols))
        printf("? Zero Matrix\n");

    if (isIdentity(matrix, rows, cols))
        printf("? Identity Matrix\n");

    if (isDiagonal(matrix, rows, cols))
        printf("? Diagonal Matrix\n");

    if (isScalar(matrix, rows, cols))
        printf("? Scalar Matrix\n");

    if (isUpperTriangular(matrix, rows, cols))
        printf("? Upper Triangular Matrix\n");

    if (isLowerTriangular(matrix, rows, cols))
        printf("? Lower Triangular Matrix\n");

    if (isSymmetric(matrix, rows, cols))
        printf("? Symmetric Matrix\n");

    if (isSkewSymmetric(matrix, rows, cols))
        printf("? Skew-Symmetric Matrix\n");

    if (rows == 1)
        printf("? Row Matrix\n");

    if (cols == 1)
        printf("? Column Matrix\n");

    if (isSquare(rows, cols)) {
        if (isSingular(matrix, rows))
            printf("? Singular Matrix\n");
        else
            printf("? Non-Singular Matrix\n");

        if (isIdempotent(matrix, rows))
            printf("? Idempotent Matrix\n");

        if (isNilpotent(matrix, rows))
            printf("? Nilpotent Matrix\n");
    }

   
    printf("Matrix classification complete!\n");

    return 0;
}



void inputMatrix(int matrix[5][5], int *rows, int *cols) {
    printf("\nEnter number of rows (max 5): ");
    scanf("%d", rows);
    printf("Enter number of columns (max 5): ");
    scanf("%d", cols);

    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[5][5], int rows, int cols) {
    printf("\nYour Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int isSquare(int rows, int cols) {
    return rows == cols;
}

int isZero(int matrix[5][5], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                return 0;
    return 1;
}

int isIdentity(int matrix[5][5], int rows, int cols) {
    if (!isSquare(rows, cols)) return 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (i == j && matrix[i][j] != 1)
                return 0;
            else if (i != j && matrix[i][j] != 0)
                return 0;
        }
    return 1;
}

int isDiagonal(int matrix[5][5], int rows, int cols) {
    if (!isSquare(rows, cols)) return 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (i != j && matrix[i][j] != 0)
                return 0;
    return 1;
}

int isScalar(int matrix[5][5], int rows, int cols) {
    if (!isDiagonal(matrix, rows, cols)) return 0;
    int val = matrix[0][0];
    for (int i = 1; i < rows; i++)
        if (matrix[i][i] != val)
            return 0;
    return 1;
}

int isUpperTriangular(int matrix[5][5], int rows, int cols) {
    if (!isSquare(rows, cols)) return 0;
    for (int i = 1; i < rows; i++)
        for (int j = 0; j < i; j++)
            if (matrix[i][j] != 0)
                return 0;
    return 1;
}

int isLowerTriangular(int matrix[5][5], int rows, int cols) {
    if (!isSquare(rows, cols)) return 0;
    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < cols; j++)
            if (matrix[i][j] != 0)
                return 0;
    return 1;
}

int isSymmetric(int matrix[5][5], int rows, int cols) {
    if (!isSquare(rows, cols)) return 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != matrix[j][i])
                return 0;
    return 1;
}

int isSkewSymmetric(int matrix[5][5], int rows, int cols) {
    if (!isSquare(rows, cols)) return 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != -matrix[j][i])
                return 0;
    return 1;
}


int isSingular(int matrix[5][5], int n) {
    if (n != 2) return 0;  
    int det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    return det == 0;
}

void multiplyMatrix(int a[5][5], int b[5][5], int result[5][5], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

int isIdempotent(int matrix[5][5], int n) {
    if (!isSquare(n, n)) return 0;
    int product[5][5];
    multiplyMatrix(matrix, matrix, product, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (product[i][j] != matrix[i][j])
                return 0;
    return 1;
}

int isNilpotent(int matrix[5][5], int n) {
    if (!isSquare(n, n)) return 0;
    int product[5][5];
    multiplyMatrix(matrix, matrix, product, n);

   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (product[i][j] != 0)
                return 0;
    return 1;
}
