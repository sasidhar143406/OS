#include <stdio.h>
#include <stdbool.h>

int main() {
    int i, j, n, m, count = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    
    int allocation[n][m], max[n][m], need[n][m], available[m], work[m];
    bool finish[n];
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        finish[i] = false;
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for (i = 0; i < m; i++) {
        work[i] = available[i];
    }
    for (int k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == false) {
                bool can_execute = true;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_execute = false;
                        break;
                    }
                }

                if (can_execute) {
                    for (j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    printf("Process %d is finished.\n", i + 1);
                    count++;
                }
            }
        }
    }
    if (count == n) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is NOT in a safe state.\n");
    }

    return 0;
}
