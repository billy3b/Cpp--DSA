class Solution {
public:
    // Calculate n choose r (nCr) using a loop
    int calculateCombination(int n, int r) {
        long long result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

    vector<int> getRow(int rowIndex) {
        // Initialize a vector to represent The last Row
        vector<int> lastRow;

        for (int j = 0; j <= rowIndex; j++) {
            // Calculate and insert the binomial coefficient (nCr) into the row
            lastRow.push_back(calculateCombination(rowIndex, j));
        }
        
        return lastRow;
    }
};


//DP Approach
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a 2D vector to represent Pascal's Triangle
        vector<vector<int>> pascalTriangle(rowIndex + 1);

        // Initialize the first row with a single element '1'
        pascalTriangle[0].push_back(1);

        // Generate the rest of the rows
        for (int currentRow = 1; currentRow <= rowIndex; currentRow++) {
            // The first element of each row is always '1'
            pascalTriangle[currentRow].push_back(1);

            // Get a reference to the current row and the previous row
            vector<int>& currentRowList = pascalTriangle[currentRow];
            vector<int>& previousRowList = pascalTriangle[currentRow - 1];

            // Calculate and populate the middle elements of the row
            for (int j = 1; j < previousRowList.size(); j++) {
                int sum = previousRowList[j] + previousRowList[j - 1];
                currentRowList.push_back(sum);
            }

            // The last element of each row is also '1'
            currentRowList.push_back(1);
        }

        return pascalTriangle[rowIndex];
    }
};
