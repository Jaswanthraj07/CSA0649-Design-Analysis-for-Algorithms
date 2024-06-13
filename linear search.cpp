#include <stdio.h>

int main() {
    int arr[100];
    int i, n, target, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    for(i = 0; i < n; i++) {
        if(arr[i] == target) {
            found = 1;
            break;
        }
    }

    if(found == 1) {
        printf("%d found at position %d\n", target, i + 1);
    } else {
        printf("%d not found in the array\n", target);
    }

    return 0;
}
