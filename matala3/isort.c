#include <stdio.h>
#define ARR_SIZE 50
void shift_element(int* arr, int i){
    for (int j = i; j > 0; j--) {
        *(arr + j) = *(arr + j - 1);
    }
}
void insertion_sort(int* arr , int len){
    for (int i=1;i<len;i++){
        int save=*(arr + i);
        int j=i-1;
        while (j>=0){
            if (*(arr+j)>save){
                j--;
            }
            else {
                break;
            }
        }
        shift_element(arr+j,i-j);
        *(arr + j + 1) = save;
    }
}
int main(){
    int numbers[ARR_SIZE]={0};
    for (int i=0;i<ARR_SIZE;i++){
        scanf("%d",&(*(numbers+i)));
    }
    insertion_sort(numbers,ARR_SIZE);
    for (int i=0;i<ARR_SIZE;i++){
        printf("%d",*(numbers+i));
        if (i==ARR_SIZE-1) {
            printf("\n");
        }
        else {
            printf(",");
        }
    }
    return 0;
}