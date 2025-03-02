//2630 색종이 만들기

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int white = 0; // 하얀색 색종이 개수
int blue = 0;  // 파란색 색종이 개수

// 해당 영역이 모두 같은 색인지 확인하는 함수
bool isSameColor(int row, int col, int size) {
    int color = paper[row][col];
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

// 분할 정복으로 색종이 개수 세기
void countPapers(int row, int col, int size) {
    // 현재 영역이 모두 같은 색인 경우
    if (isSameColor(row, col, size)) {
        if (paper[row][col] == 0) {
            white++;
        } else {
            blue++;
        }
        return;
    }
    
    // 4등분으로 나누어 재귀 호출
    int newSize = size / 2;
    countPapers(row, col, newSize);                  // 좌상단
    countPapers(row, col + newSize, newSize);        // 우상단
    countPapers(row + newSize, col, newSize);        // 좌하단
    countPapers(row + newSize, col + newSize, newSize); // 우하단
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    // 종이 정보 입력 받기
    paper.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    
    // 분할 정복 시작
    countPapers(0, 0, n);
    
    // 결과 출력
    cout << white << '\n';
    cout << blue << '\n';
    
    return 0;
}
