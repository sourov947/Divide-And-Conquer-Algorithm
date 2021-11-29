#include<bits/stdc++.h>
using namespace std;
void countingsort(int input_arr[],int s,int r){
    int counting_array[r];
    int output_array[s];
    for (int i = 0; i < r;i++){
        counting_array[i] = 0;
    }
    for (int i = 0; i < s;i++){
        ++counting_array[input_arr[i]];
    }
    for (int i = 1; i < r;i++){
        counting_array[i] = counting_array[i] + counting_array[i - 1];
    }
    for (int i = 0; i < s;i++){
        output_array[--counting_array[input_arr[i]]] = input_arr[i];
    }
    for (int i = 0; i < s;i++){
        input_arr[i] = output_array[i];
    }
}
int main(void){
    int range = 10;
    int size = 0;
    cout << "Enter the array size " << endl;
    cin >> size;
    int myarr[size];
    cout << "Enter " << size << " integer in any order in ssale of 0-9" << endl;
    for (int i = 0; i < size;i++){
        cin >> myarr[i];
    }
    countingsort(myarr,size,range);
    cout <<endl<< "After sorting " << endl;
    for (int i = 0; i < size;i++){
        cout<< myarr[i]<<" ";
    }

    return 0;
}