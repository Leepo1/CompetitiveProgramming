#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
using namespace std;

int main(){

    ifstream cin("tttt.in");
    ofstream cout("tttt.out");
    char board[3][3];
    int rowsize[2][3];
    int diagonol[2];
    set<char> row;
    int one=0;
    int two=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>> board[i][j];
        }
    }

    for(int i=0; i<3; i++){
    row.clear();
        for(int j=0; j<3; j++){
            row.insert(board[i][j]);
        }
        rowsize[0][i]=row.size();
    }

    for(int i=0; i<3; i++){
    row.clear();
        for(int j=0; j<3; j++){
            row.insert(board[j][i]);
        }
        rowsize[1][i]=row.size();
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            if(rowsize[i][j]==1){
                one = one+1;
            } else if(rowsize[i][j]==2){
                two =two +1;
            }
        }
    }

    for(int i=0; i<2; i++){
        row.clear();
        if(i==0){
        row.insert(board[0][0]);
        row.insert(board[1][1]);
        row.insert(board[2][2]);
        } else{
            row.insert(board[0][2]);
            row.insert(board[1][1]);
            row.insert(board[2][0]);
        }
        diagonol[i]=row.size();
    }
    for(int i=0; i<2; i++){
        if(diagonol[i]==1){
            one=one+1;
        }else if(diagonol[i]==2){
            two=two+1;
        }
    }
    cout<< one << endl << two;

return 0;
}