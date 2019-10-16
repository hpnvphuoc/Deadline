#include"sort.h"
#define n 8
int main(){
    int *a= new int[0,5,6,7,4,3,2,1];
    int *b;
    b=insertionsort(a,n);
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
