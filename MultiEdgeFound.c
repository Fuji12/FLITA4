#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define graf_height 100
#define graf_width 2

int main()
{
  int matrix[graf_height][graf_width];
  int i, j, k;
  int m = 0;
  clock_t begin = clock();
  FILE *file = fopen("list_of_edges142.txt", "r");
  if (!file)
    exit(EXIT_FAILURE);
  for (i = 0; i <  graf_height && !feof(file); i++)
  {
    for (j = 0; j < graf_width && !feof(file); j++)
    {
      fscanf(file, "%d", &matrix[i][j]);
     // printf("%d ", matrix[i][j]);
    }
    //putchar('\n');
  }
  fclose(file);
  for (int i = 0; i < graf_height; i++){  
    if (matrix[i][0] == -1 && matrix[i][1] == -1)
       {
         continue;
       }
    else{        
    for (int k = i + 1; k < graf_height; k++){
      if (matrix [i][0] == matrix [k][0] && matrix [i][1] == matrix [k][1]){
        //printf("Found multiconnetction beetwen edges %d %d\n", matrix[i][0], matrix[i][1]);
        matrix [k][0]= -1;
        matrix [k][1]= -1;
        m++;
       }
      }
    }
  }  
if (m==0){
     printf ("There are no multiedges in this graph\n");
     clock_t end = clock();
     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     printf("Work time : %lf\n",time_spent);
     return 0;
  }
  printf ("Number of multiedges in total: %d\n", m);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Work time : %lf\n",time_spent);
  //for (int i = 0; i < graf_height; i++){
  // printf( "%d %d\n", matrix[i][0], matrix[i][1]);
  //}
  return 0;
}
