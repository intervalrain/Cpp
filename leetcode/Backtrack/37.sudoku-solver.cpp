#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    int boxs[81], rows[81], cols[81];

    int entry[81];
    int box[9], row[9], col[9];

    int ptr = 0;
    int seq[81];

    int next(int p){
        int q, x, Possibles, cnt;
        int min = 9;

        for (int i = p; i < 81; i++) {
            x = seq[i];
            Possibles = box[boxs[x]] & row[rows[x]] & col[cols[x]];
            cnt = 0;
            while (Possibles) {
                Possibles &= ~(Possibles & -Possibles);
                cnt++;
            }
            if (cnt == 1){
                q = i;
                break;
            } else if (cnt < min) {
                min = cnt;
                q = i;
            }
        }
        return q;
    }

    void setup(){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                int x = 9*i+j;
                rows[x] = i;
                cols[x] = j;
                boxs[x] = (i/3)*3 + (j/3);
            }
        }
        for (int x = 0; x < 81; x++) {
            seq[x] = x;
            entry[x] = 0;
        }
        for (int i = 0; i < 9; i++) {
            box[i] = row[i] = col[i] = 0x1ff;
        }
    }

    void init(vector<vector<char>>& board){
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int val = ch - '0';
                int x = 9*i+j;
                int bit = 1 << (val-1);
                int q;
                
                entry[x] = bit;
                box[boxs[x]] &= ~bit;
                col[cols[x]] &= ~bit;
                row[rows[x]] &= ~bit;

                q = ptr;
                while (q < 81 && seq[q] != x) q++ ;
                swap(seq[ptr], seq[q]);
                ptr++;
            }
        }
    }

    void place(int p, vector<vector<char>>& board){
        if (p >= 81) {
            finalize(board);
            return;
        }

        int q = next(p);
        swap(seq[p], seq[q]);
        int x = seq[p];
        
        int Possibles = box[boxs[x]] & row[rows[x]] & col[cols[x]];
        while (Possibles) {
            int bit = Possibles & (-Possibles);
            Possibles &= ~bit;
            entry[x] = bit;
            box[boxs[x]] &= ~bit;
            row[rows[x]] &= ~bit;
            col[cols[x]] &= ~bit;
                    
            place(p+1, board);

            entry[x] = 0;
            box[boxs[x]] |= bit;
            row[rows[x]] |= bit;
            col[cols[x]] |= bit;
        }

        swap(seq[p], seq[q]);
    }

    void finalize(vector<vector<char>>& board){
        char ch;
        int x = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int bit = entry[x++];
                for (int val = 1; val <= 9; val++) {
                    if (bit == (1 << (val-1))) {
                        ch = '0' + val;
                        break;
                    }
                }
                board[i][j] = ch;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        ptr = 0;
        setup();
        init(board);
        place(ptr, board);
    }
};
// @lc code=end