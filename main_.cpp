#include <iostream>
using namespace std;

// Structure to represent a sparse matrix element
struct Element {
    int row, col, val;
};

int main() {
    int m = 4, n = 5; // Matrix dimensions
    int mat[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // Count non-zero elements
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) count++;
        }
    }

    // Create array for storing sparse matrix
    Element sparse[count];
    int k = 0;

    // Store non-zero elements with row, col, value
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = mat[i][j];
                k++;
            }
        }
    }

    // Print sparse matrix representation
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < count; i++) {
        cout << sparse[i].row << "\t"
             << sparse[i].col << "\t"
             << sparse[i].val << endl;
    }

    return 0;
}
