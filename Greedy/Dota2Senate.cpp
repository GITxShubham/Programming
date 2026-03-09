// LeetCode 649. 
// Problem statement: https://leetcode.com/problems/dota2-senate/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue <int> q , radiant , dire;
        for(int i = 0 ; i < senate.length() ; i++){
            q.push(i);
            if(senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        while(q.size()>1){
            if(senate[q.front()] == 'R'){
                if(dire.size() != 0){
                    senate[dire.front()] = 'X';
                    dire.pop();
                    q.push(q.front());
                    q.pop();
                    radiant.push(radiant.front());
                    radiant.pop();
                }
                else return "Radiant";
            }
            else if(senate[q.front()] == 'D'){
                if(radiant.size() != 0){
                    senate[radiant.front()] = 'X';
                    radiant.pop();
                    q.push(q.front());
                    q.pop();
                    dire.push(dire.front());
                    dire.pop();
               }
               else return "Dire";
            }
            else q.pop();
        }
        if(senate[q.front()] == 'R') return "Radiant";
        else return "Dire";
    }
};