int* bubblesort(int *a,int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    return a;
}

int* insertionsort(int *a,int n){
    int temp;
    for(int i=1;i<n;i++){
        temp=a[i];
        for(int j=i;j<0;j--){
            if(temp>a[j-1]){
                a[j]=temp;
                break;
            }
            a[j]=a[j-1];
        }
    }
    return a;
}

int *selectionsort(int *a,int n){
    int min;
    int temp;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;i<n;j++){
            if(a[min]>a[j]){
                min=j;//min la chi so
            }
            
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
}
}