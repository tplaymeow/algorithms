#include <cmath>
#include <iostream>
#include <vector>

int cur_num = 1;

std::vector<std::vector<int>> merge_matrix(std::vector<std::vector<int>> m1,
                                           std::vector<std::vector<int>> m2,
                                           std::vector<std::vector<int>> m3,
                                           std::vector<std::vector<int>> m4) {
    int size = m1.size();
    std::vector<std::vector<int>> result(2 * size, std::vector<int>(2 * size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m1[i][j];
            result[i][size + j] = m2[i][j];
            result[size + i][j] = m3[i][j];
            result[size + i][size + j] = m4[i][j];
        }
    }
    return result;
}

std::vector<std::vector<int>> get_init_matrix(int empty_field_x,
                                              int empty_field_y) {
    std::vector<std::vector<int>> result(2, std::vector<int>(2, cur_num++));
    result[empty_field_y][empty_field_x] = 0;
    return result;
}

std::vector<std::vector<int>> get_matrix(int size_pow, int empty_field_x,
                                         int empty_field_y) {
    if (size_pow == 1)
        return get_init_matrix(empty_field_x, empty_field_y);

    int size = 1 << size_pow;

    if (empty_field_x < size / 2 && empty_field_y < size / 2) {
        auto m1 = get_matrix(size_pow - 1, empty_field_x, empty_field_y);
        auto m2 = get_matrix(size_pow - 1, 0, size / 2 - 1);
        auto m3 = get_matrix(size_pow - 1, size / 2 - 1, 0);
        auto m4 = get_matrix(size_pow - 1, 0, 0);

        m2[size / 2 - 1][0] = cur_num;
        m3[0][size / 2 - 1] = cur_num;
        m4[0][0] = cur_num++;
        return merge_matrix(m1, m2, m3, m4);
    }
    if (empty_field_x >= size / 2 && empty_field_y < size / 2) {
        auto m1 = get_matrix(size_pow - 1, size / 2 - 1, size / 2 - 1);
        auto m2 = get_matrix(size_pow - 1, empty_field_x - size / 2, empty_field_y);
        auto m3 = get_matrix(size_pow - 1, size / 2 - 1, 0);
        auto m4 = get_matrix(size_pow - 1, 0, 0);

        m1[size / 2 - 1][size / 2 - 1] = cur_num;
        m3[0][size / 2 - 1] = cur_num;
        m4[0][0] = cur_num++;
        return merge_matrix(m1, m2, m3, m4);
    }
    if (empty_field_x < size / 2 && empty_field_y >= size / 2) {
        auto m1 = get_matrix(size_pow - 1, size / 2 - 1, size / 2 - 1);
        auto m2 = get_matrix(size_pow - 1, 0, size / 2 - 1);
        auto m3 = get_matrix(size_pow - 1, empty_field_x, empty_field_y - size / 2);
        auto m4 = get_matrix(size_pow - 1, 0, 0);

        m1[size / 2 - 1][size / 2 - 1] = cur_num;
        m2[size / 2 - 1][0] = cur_num;
        m4[0][0] = cur_num++;
        return merge_matrix(m1, m2, m3, m4);
    }
    if (empty_field_x >= size / 2 && empty_field_y >= size / 2) {
        auto m1 = get_matrix(size_pow - 1, size / 2 - 1, size / 2 - 1);
        auto m2 = get_matrix(size_pow - 1, 0, size / 2 - 1);
        auto m3 = get_matrix(size_pow - 1, size / 2 - 1, 0);
        auto m4 = get_matrix(size_pow - 1, empty_field_x - size / 2,
                             empty_field_y - size / 2);

        m1[size / 2 - 1][size / 2 - 1] = cur_num;
        m2[size / 2 - 1][0] = cur_num;
        m3[0][size / 2 - 1] = cur_num++;
        return merge_matrix(m1, m2, m3, m4);
    }
    return {};
}

int main() {
    int n, x, y;
    std::cin >> n;
    std::cin >> y >> x;

    for (auto &line : get_matrix(n, x - 1, y - 1)) {
        for (auto &el : line)
            std::cout << el << " ";
        std::cout << "\n";
    }
}
