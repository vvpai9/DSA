#include <stdio.h>
#include <stdlib.h>

void readFile(int a[],int n,char *f);
void countingSort(int a[],int n);

int main() {
    int n=10,a[n];
    readFile(a,n,"input.txt");
    
    printf("Before:\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    
    countingSort(a,n);
    
    printf("\nAfter:\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    
    for(int i=0;i<n;i++)
       printf("%d ",a[i]);
    
       printf("\n");
    return 0;
}

void readFile(int a[],int n,char *f)
{
    FILE *in=fopen(f,"r");
    if(!in) exit(1);
    
    for(int i=0;i<n;i++) fscanf(in,"%d",&a[i]);
    fclose(in);
}

void countingSort(int a[],int n)
{
    int sorted=1;
    for(int i=1;i<n;i++)if(a[i]<a[i-1]) { sorted=0; break; }
    if(sorted) return;

    int max=a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    
    int *cnt=calloc(max+1,sizeof(int));
    for(int i=0;i<n;i++) cnt[a[i]]++;
    
    int idx=0;
    for(int i=0;i<=max;i++) 
        while(cnt[i]--) a[idx++]=i;
    
    free(cnt);
}
