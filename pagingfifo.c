#include<stdio.h>

int main()
{
    int n, i, j, m, pagefault = 0, found = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter the number of page frames: ");
    scanf("%d", &m);
    
    int arr[n];  
    int a[m];   
    
    
    printf("Enter the page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < m; i++) {
        a[i] = -1;
    }

 
    for(i = 0; i < n; i++) {
        found = 0;

        
        for(j = 0; j < m; j++) {
            if(arr[i] == a[j]) {
                found = 1; 
                break;
            }
        }

        
        if(!found) {
            pagefault++;

               for(j = 0; j < m - 1; j++) {
                a[j] = a[j + 1];
            }

        a[m - 1] = arr[i];
        }
    }

   
    printf("Total page faults: %d\n", pagefault);

    return 0;
}
