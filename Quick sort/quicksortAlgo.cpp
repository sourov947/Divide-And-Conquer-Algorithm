#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int s,int e){
    int pivote = arr[e];
    int pindex = s;
    for (int i = s; i < e;i++){
        if(arr[i]<=pivote){
            int temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
            pindex++;
        }
        
    }
    int temp = arr[e];
        arr[e] = arr[pindex];
        arr[pindex] = temp;
        return pindex;
}
void quicksort(int arr[],int s,int e){
    if(s<e){
        int p = partition(arr, s, e);
        quicksort(arr, s, (p - 1));
        quicksort(arr, (p + 1), e);
    }
}
int main(void){
    int myarr[20];
    int size;
    cout << "Enter size of the array " << endl;
    cin >> size;
    cout << "Enter the element of the array in any order " << endl;
    for (int i = 0; i < size;i++){
        cin >> myarr[i];
    }
    cout << "Array before sort" << endl;
    for (int i = 0; i < size;i++){
        cout<< myarr[i]<< " ";
    }
    quicksort(myarr,0,size-1);
    cout << "Array after sort" << endl;
    for (int i = 0; i < size;i++){
        cout<< myarr[i]<<" ";
    }
}