#include<stdio.h>

void clearcount(void);
int getcount(void);
void bubblesort(int unsortedarr[], int siz);
int count;
int main(int argc, char const *argv[])
{
  int array1[10] = { 9, 2, 5, -4, 12, -20, 47, 6, 3 };
  int array2[6] = { 10, 5, 2, -4, -12, -20 };
  int array3[4] = { -3, 3, 7, 12 };
  bubblesort(array1, 10);
  for (int i=0; i < 10; ++i)
    printf("%d ",array1[i]);
  printf("\n Required mutual repositionings of elements: %d \n", getcount());
  clearcount();
  printf("Lets sort another array, we have reset counter to %d \n",getcount());
  bubblesort(array2, 6);
  for (int i=0; i < 6; ++i)
    printf("%d ",array2[i]);
  printf("\n required %d \n", getcount());
  clearcount();
  bubblesort(array3, 4);
  printf("\n The last array required %d \n", getcount());
  clearcount();
  return 0;
}
/*
/usr/bin/gcc -Wall -std=c99 -o 2.08sort 2.08program2.5bubblesort.c 2.08main.c
*/
