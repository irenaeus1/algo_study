#include <iostream>
#include <bitset>
using namespace std;

#define test 0
#define TEST if(test)

//brute force sliding window
int main() {
    int N, M;
    cin >> N >> M;
    TEST N = M = 8;
    char input[52];
    long long int input_board[50]= {};
    for (int i = 0; i < N; i++) {
        if(!test) cin >> input;
        input_board[i] = 0;
        for (int j = 0; j < M; j++){
            TEST input[j] = ((i+j)%2)?'W':'B';
            if (input[j] == 'W'){
                input_board[i] += (1LL << (M-j-1));
            }
        }
    }
    long long int and_board[2][50] = {};
    long long int patten[2] = {0b01010101010101010101010101010101010101010101010101LL, 0b10101010101010101010101010101010101010101010101010LL};
    for (int j = 0; j < N; j++){
        and_board[0][j] = input_board[j] ^ patten[j%2];
        and_board[1][j] = input_board[j] ^ patten[(j+1)%2];
    }
    int result = 64;

    for (int i = 0; i < N-7; i++){
        for (int j = 0; j < M-7; j++){
            int cnt[2] = {0, 0};
            for (int l = 0; l < 8; l++){
                cnt[0] += bitset<8>((and_board[0][i+l] >> (M-j-8)) & 0xFF).count();
                cnt[1] += bitset<8>((and_board[1][i+l] >> (M-j-8)) & 0xFF).count();
            }
            
            result = min(result, 64-cnt[0]);
            result = min(result, 64-cnt[1]);
        }
    }
    cout << result << endl;
}