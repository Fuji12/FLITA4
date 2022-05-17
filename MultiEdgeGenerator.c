#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int EdgeCount = 0;
    int Graph = 0;
    int i;
    printf ("How many edges will be?\n");
    scanf ("%d", &EdgeCount);
    printf ("How many connections will be?\n");
    scanf ("%d", &Graph);
    printf("%d\n", EdgeCount);
    printf("%d\n", Graph);
    
    FILE *out;
    out = fopen("list_of_edges142.txt", "w");
    for (i=0; i < Graph; i++){
       fprintf(out, "%d %d\n", rand()%(EdgeCount-1),rand()%(EdgeCount-1));
    }
    fclose(out);
    
    return 0;
}
    
