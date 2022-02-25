#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

struct range {
    size_t left;
    size_t right;
};
size_t uint_range_length(struct range range) {
    return range.right - range.left;
}

uint32_t read_uint() {
    uint32_t result;
    scanf("%" SCNu32, &result);
    return result;
}

int main() {
    const size_t flowers_count = read_uint();
    uint32_t *flowers = malloc(sizeof(uint32_t) * flowers_count);
    for (size_t i = 0; i < flowers_count; i++)
        flowers[i] = read_uint();

    struct range range = {0, 0};
    struct range range_ans = {0, 0};
    uint32_t last_flower = 0;
    size_t last_flower_repeats = 0;

    for (size_t i = 0; i < flowers_count; i++) {
        if (last_flower != flowers[i])
            last_flower_repeats = 1;
        else if (last_flower_repeats == 1)
            last_flower_repeats = 2;
        else {
            if (uint_range_length(range) > uint_range_length(range_ans))
                range_ans = range;
            range.left = range.right;
        }
        last_flower = flowers[i];
        range.right = i;
    }
    if (uint_range_length(range) > uint_range_length(range_ans))
        range_ans = range;

    printf("%zu %zu", range_ans.left + 1, range_ans.right + 1);
    free(flowers);
    return 0;
}
