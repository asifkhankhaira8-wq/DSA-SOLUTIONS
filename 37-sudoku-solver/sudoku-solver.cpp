class Solution {
public:
bool isColSafe(char n,int col,vector<vector<char>>& board){
       for(int row=0;row<9;row++){
        if(board[row][col]==n) return false;
        }
        return true;
}
bool isRowSafe(char n,int row,vector<vector<char>>& board){
       for(int col=0;col<9;col++){
         if(board[row][col]==n) return false;
       }
       return true;
}
bool isBoxSafe(char n ,int row,int col,vector<vector<char>>& board){
    int rows=row/3;
    int cols=col/3;
    rows*=3;
    cols*=3;
      for(int i=rows;i<rows+3;i++){
        for(int j=cols;j<cols+3;j++){
            if(board[i][j]==n) return false;
        }
      }
      return true;
}
bool fun(int row,int col,vector<vector<char>>& board){
    if(col == 9) return true;
      if(row == 9 ) return fun(0, col+1, board);
    if(board[row][col]!='.'){
        return fun(row+1,col,board);
        
    }
    else{
         for(int i=1;i<=9;i++){
        char ch = i + '0';
   if(isColSafe(ch,col,board) && isRowSafe(ch,row,board) && isBoxSafe(ch,row,col,board)){
         board[row][col]=ch;
         if(fun(row+1,col,board)) return true;
        board[row][col]='.';
        }
     }}
     return false;
}
    void solveSudoku(vector<vector<char>>& board) {
        bool b=fun(0,0,board);
    }
};