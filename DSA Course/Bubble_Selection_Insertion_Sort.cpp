#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> BubbleSort(vector<int>& vec) {
    int n = vec.size();
    for(int i = 0; i < n - 1; i++) {
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return vec;
        }
    }
    return vec;
}

vector<int> SelectionSort(vector<int>& vec) {
    int n = vec.size();
    for(int i = 0; i < n - 1; i++) {
        int small = i;
        for(int j = i + 1; j < n; j++) {  // fixed inner loop
            if(vec[j] < vec[small]) {
                small = j;
            }
        }
        swap(vec[i], vec[small]);
    }
    return vec;
}

vector<int> InsertionSort(vector<int>& vec){
    int n=vec.size();
    for(int i=1;i<n;i++){
        int current=vec[i];
        int previous=i-1;
        while(previous>=0&&vec[previous]>current){
            vec[previous+1]=vec[previous];
            previous--;
        }
        vec[previous+1]=current;
        
    }
    return vec;
}

int main() {
    vector<int> vec = {4, 1, 5, 2, 3};

    vector<int> vec2 = BubbleSort(vec);
    cout << "Bubble Sort Result:\n";
    for(int i : vec2) {
        cout << i << " ";
    }
    cout << endl << endl;

    vector<int> vec3 = SelectionSort(vec);
    cout << "Selection Sort Result:\n";
    for(int i : vec3) {
        cout << i << " ";
    }
    cout << endl << endl;

    vector<int> vec4 = InsertionSort(vec);
    cout << "Insertion Sort Result:\n";
    for(int i : vec4) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
