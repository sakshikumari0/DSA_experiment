#include <stdio.h>

int main() {
    int marks[5];
    int flag = 0;
    int i;
    int total = 0;
    float avg;

    for (i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
    }

    for (i = 0; i < 5; i++) {
        total += marks[i];
        if (marks[i] < 40) {
            flag = 1;
        }
    }

    avg = total / 5.0;
    printf("Average: %.2f\n", avg);

    if (flag == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }

    return 0;
}
