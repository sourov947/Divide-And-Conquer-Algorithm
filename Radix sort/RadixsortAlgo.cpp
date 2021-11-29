#include<bits/stdc++.h>
using namespace std;
int findmax(int arr[],int size){
    int max = arr[0];
    for (int i = 0; i < size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
void countingsort(int arr[],int size,int div){
    int count_arr[10] = {0};
    int output[size];
    for (int i = 0; i < size;i++){
        count_arr[(arr[i] / div) % 10]++;
    }
    for (int i = 1; i < 10;i++){
        count_arr[i] += count_arr[i - 1];
    }
    for (int i = size - 1; i >= 0;i--){
        output[count_arr[(arr[i] / div) % 10] - 1] = arr[i];
        count_arr[(arr[i] / div) % 10]--;
    }
    for (int i = 0; i < size;i++){
        arr[i] = output[i];
    }
}
void radixsort(int arr[],int size){
    int m = findmax(arr, size);
    for (int div = 1; m / div > 0;div*=10){
        countingsort(arr, size, div);
    }
}
int main(void){
    int size;
    cout << "Enter the array size" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the array element" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    radixsort(arr, size);
    cout << "after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}