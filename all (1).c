#include <stdio.h>
void BubbleSort(int arr[],int n){
    int temp;
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>=arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[]={46,31,424,664};
    int n=sizeof(arr)/sizeof(arr[0]);
   
    BubbleSort(arr,n);
    printArray(arr,n);
    printf("This Program was executed by Samridh Chaudhary\nRoll No- 2400320100976");
	

}

