#include <stdio.h>
#include <stdlib.h>
// use when we want to take size as user input
// stores in heap
struct Array
{
    int *A;
    int size;
    int length; // no of elements in array
};

void swap(int *i, int *j){
    int temp = *j;
    *j = *i;
    *i = temp;
}

struct Array mergeTwoArrays(struct Array arr1, struct Array arr2){
    struct Array arr3;
    arr3.size = 2*arr1.size;
    arr3.A = (int*)malloc(arr3.size*sizeof(int));
    int i = 0, j = 0, k = 0;

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k] = arr1.A[i];
            i++;
            
        }
        else{
            arr3.A[k] = arr2.A[j];
            j++;
            
        }
        k++;
    }

    while(i < arr1.length){
        arr3.A[k] = arr1.A[i];
        i++;
        k++;
    }

    while(j < arr2.length){
        arr3.A[k] = arr2.A[i];
        j++;
        k++;
    }
    arr3.length = i+j;
    return arr3;

}

// Rearranges -ve numbers on left and +ve numbers on right side
void Rearrange(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while(i < j){
        while(arr->A[i] < 0){
            i++;
        }
        while(arr->A[j] > 0){
            j--;
        }

        if (i<j){
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

// checks in increasing order
int isSorted(struct Array arr){
    for(int i = 0; i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return -1;
        }
    }
    return 1;

}

// puts in increasing order
void insertSort(struct Array *arr, int value){
    if (arr->length == arr->size){
        printf("Array is full");
    }

    else{
        int i;
        for(i = arr->length - 1; i >= 0; i--){
            
            if(arr->A[i] < value){
                break;
               
            }
            arr->A[i+1] = arr->A[i];
            
        }
        printf("%d",i);
        arr->A[i+1] = value;
        arr->length++;
    }

}

void display(struct Array arr){
    printf("\nArray elements are : ");
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int recuBinarySearch(struct Array arr, int key, int l, int h)
{

    if(l <= h){
        int mid = l + (h-l)/2;

        if(arr.A[mid] == key){
            return mid;
        }

        else if(arr.A[mid] < key){
            return recuBinarySearch(arr, key, mid + 1, h);

        }

        else{
            return recuBinarySearch(arr, key, l, mid - 1);

        }
    } 

    return -1;
}

int binarySearch(struct Array arr, int key){
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    

    while(l <= h){
        mid = l+((h-l)/2); // floor value
        if(arr.A[mid] == key){
            return mid;
        }

        else if(arr.A[mid] < key){
            l = mid + 1;

        }

        else{
            h = mid - 1;
        }

    }
    return -1;
}



int main()
{

    struct Array arr1; 
    arr1.size = 10;
    arr1.length = 5;
    arr1.A = (int*)malloc(arr1.size*sizeof(int));
    arr1.A[0] = 2;
    arr1.A[1] = 6;
    arr1.A[2] = 10;
    arr1.A[3] = 15;
    arr1.A[4] = 25;
    struct Array arr2;
    arr2.size = 10;
    arr2.length = 5;
    arr2.A = (int*)malloc(arr2.size*sizeof(int));
    arr2.A[0] = 2;
    arr2.A[1] = 4;
    arr2.A[2] = 7;
    arr2.A[3] = 18;
    arr2.A[4] = 20;
    struct Array mergedArray = mergeTwoArrays(arr1, arr2);
    display(mergedArray);
    

    return 0;

}