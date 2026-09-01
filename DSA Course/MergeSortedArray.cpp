#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void Merge(vector<int>& A, vector<int>& B) {
    int m = 3;  // number of actual elements in A
    int n = 3;  // number of elements in B

    int index = m + n - 1; // last index of A
    int i = m - 1;         // last actual element in A
    int j = n - 1;         // last element in B

    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[index] = A[i];
            i--;
        } else {
            A[index] = B[j];
            j--;
        }
        index--;
    }

    while (j >= 0) {
        A[index] = B[j];
        index--;
        j--;
    }
}

void display(const vector<int>& A) {
    for (int val : A) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3, 0, 0, 0};
    vector<int> B = {2, 5, 6};

    Merge(A, B);
    cout << "Merged Sorted Array: ";
    display(A);

    return 0;
}
