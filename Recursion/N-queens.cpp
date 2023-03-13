class Solution {
public:
    int size;
    vector<vector<string>> solutions;

	vector<vector<string>> solveNQueens(int n) {
		this->size = n;
        vector<vector<char>> emptyBoard(size, vector<char>(size));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                emptyBoard[i][j] = '.';
            }
        }
        unordered_set<int> diagonals;
        unordered_set<int> antiDiagonals;
        unordered_set<int> cols;
        backtrack(0, diagonals, antiDiagonals, cols, emptyBoard);
        return solutions;
	}

    // Making use of a helper function to get the
    // solutions in the correct output format
    vector<string> createBoard(vector<vector<char>> & state) {
        vector<string> board;
        for (int row = 0; row < size; row++) {
            string val(state[row].begin(), state[row].end());
            board.push_back(val);
        }
        return board;
    }

    void backtrack(int row, unordered_set<int> &diagonals, 
                    unordered_set<int> &antiDiagonals, 
                    unordered_set<int>& cols, vector<vector<char>> state) {
        // Base case - N queens have been placed
        if (row == this->size) {
            solutions.push_back(createBoard(state));
            return;
        }
        
        for (int col = 0; col < this->size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.find(col) != cols.end()
                    || diagonals.find(currDiagonal) != diagonals.end()
                    || antiDiagonals.find(currAntiDiagonal) != antiDiagonals.end()) {
                continue;    
            }
            
            // "Add" the queen to the board
            cols.insert(col);
            diagonals.insert(currDiagonal);
            antiDiagonals.insert(currAntiDiagonal);
            state[row][col] = 'Q';

            // Move on to the next row with the updated board state
            backtrack(row + 1, diagonals, antiDiagonals, cols, state);

            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.erase(cols.find(col));
            diagonals.erase(diagonals.find(currDiagonal));
            antiDiagonals.erase(antiDiagonals.find(currAntiDiagonal));
            state[row][col] = '.';
        }
    }
};