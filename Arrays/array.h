#include<stdio.h>
#include<stdlib.h>

int* accept(int arrsize)
{
  int* arr = (int* )malloc(sizeof(int)*arrsize);  
  printf("Enter the elements of array : \n");
  for(int i = 0; i < arrsize; i++){
    scanf("%d",&arr[i]);  
  }
  
  return arr;
}

void display(int* arr, int arrsize)
{

  printf("Elements of array are : ");
  for(int i = 0; i < arrsize; i++)
  {
    printf("%d\t",arr[i]);    
  }
  printf("\n");
}
