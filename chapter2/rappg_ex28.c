/*
Greg Rapp
EX 2.8
9/9
*/
#include <stdio.h>
int main()
{
  int guess = 0;
  int key = 5;
  printf("\nenter guess 1-10: ");
  scanf("%d",&guess);
  while (guess != key)
  {
    if (guess < key){
      printf("guess is less than answer\n");
    }
    else if (guess > key){
      printf("guess is greater than answer\n");
    }
    printf("\nenter better guess: ");
    scanf("%d", &guess);
  }
  printf("\ncorrect.\n");
}

