#include<stdio.h>
   
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[100],int lb,int ub){
    int pivot = array[lb],start=lb,end=ub;
    while(start<end){
        while(array[start]<=pivot)
            start++;
        while(array[end]>pivot)
            end--;
        if(start<end)
            swap(&array[start],&array[end]);
    }
    swap(&array[lb],&array[end]);
    return end;
}

int QuickSort(int array[100],int lb,int ub){
    if(lb<ub){
        int loc = partition(array,lb,ub);
        QuickSort(array,lb,loc-1);
        QuickSort(array,loc+1,ub);
    }
}

void merge(int array[100],int lb,int mid,int ub){
    int temp[100];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub){
        if(array[i]<array[j]){
            temp[k]=array[i];
            i++;
        }
        else{
            temp[k]=array[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=array[i];
        i++;
        k++;
    }
    while(j<=ub){
        temp[k]=array[j];
        j++;
        k++;
    }
    for(int i=lb;i<=ub;i++){
        array[i]=temp[i];
    }
}

void mergeSort(int array[100],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(array,lb,mid);
        mergeSort(array,mid+1,ub);
        merge(array,lb,mid,ub);
    }
}

void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}    
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  
/* function to print the array elements */  
void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}

void main()
{
    int array[100],n,i,op;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    do
    {
        printf("\n1.Enter the elements\n2.Quick sort\n3.Merge sort\n4.Heap sort\n5.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
               for(i=0;i<n;i++)
                  scanf("%d",&array[i]);
                break;
        case 2:
            QuickSort(array,0,n-1);
            printf("sorted array is\n");
            printArr(array, n);
            break;
        case 3:
            mergeSort(array,0,n-1);
            printf("sorted array is\n");
            printArr(array, n);
            break;
        case 4:
            heapSort(array,n);
            printArr(array, n);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }while(op !=5 );
}