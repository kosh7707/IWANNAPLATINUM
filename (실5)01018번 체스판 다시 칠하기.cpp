#include <iostream>
#include <vector>

auto slice_vector(const std::vector<std::vector<char>>& chess_board, int m, int n) {
    std::vector<std::vector<char>> temp_board(8, std::vector<char>(8));
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
            temp_board[i][j] = chess_board[m+i][n+j];
    return temp_board;
}

auto compare_vector(const std::vector<std::vector<char>>& chess_board, const std::vector<std::vector<char>>& template_board) {
    int ret = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++)
            if (chess_board[i][j] != template_board[i][j])
                ret++;
    }
    return ret;
}

int main() {
    int M, N; std::cin >> M >> N;
    std::vector<std::vector<char>> chess_board(M, std::vector<char>(N));
    std::string temp;
    for(int i=0; i<M; i++) {
        std::cin >> temp;
        for(int j=0; j<N; j++) {
            chess_board[i][j] = temp[j];
        }
    }
    std::vector<std::vector<char>> B_start_template_board = { {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'} };

    std::vector<std::vector<char>> W_start_template_board = { {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                                              {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                                              {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'} };

    int min = 32;
    for (int m=0; m<=M-8; m++) {
        for (int n=0; n<=N-8; n++) {
            int temp_count, temp_count1, temp_count2;
            auto temp_board = slice_vector(chess_board, m, n);
            temp_count1 = compare_vector(temp_board, W_start_template_board);
            temp_count2 = compare_vector(temp_board, B_start_template_board);
            temp_count = (temp_count1 < temp_count2) ? temp_count1 : temp_count2;
            if (temp_count <= min)
                min = temp_count;
        }
    }
    std::cout << min;

    return 0;
}
