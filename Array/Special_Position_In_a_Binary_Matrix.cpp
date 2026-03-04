// Leetcode: 1582. Special Positions in a Binary Matrix
// Problem Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0) continue;

                bool special = true;
                // check row
                for(int r = 0 ; r < m ; r++){
                    if(r != i  &&  mat[r][j] == 1){
                        special = false;
                        break;
                    }
                }

                // Check column
                for(int c = 0 ; c < n ; c++){
                    if(c != j  &&  mat[i][c] == 1){
                        special = false;
                        break;
                    }
                }

                if(special == true) result++;
            }
        }

        return result;
    }
};