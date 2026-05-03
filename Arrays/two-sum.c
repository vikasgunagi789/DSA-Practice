#include <stdio.h>

void twoSum(int nums[], int size, int target) {

    for(int i = 0; i < size; i++) {

        for(int j = i + 1; j < size; j++) {

            if(nums[i] + nums[j] == target) {

                printf("Indices: %d %d\n", i, j);
                return;
            }
        }
    }

    printf("No solution found");
}

int main() {

    int nums[] = {2, 7, 11, 15};
    int target = 9;

    int size = sizeof(nums) / sizeof(nums[0]);

    twoSum(nums, size, target);

    return 0;
}
