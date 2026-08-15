// Scan through positions and each array
// Array (rows) should have all unique int values
// Positions (columns) should all unique int values
// -> Hashmap: position = key, array = value
// Create three new arrays that store up to 9 values
// before being wiped. Same array check
// Make a function that checks arrays

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool good = true;
        int i = 0;
        int f = 0;
        vector<char> one_square;
        vector<char> two_square;
        vector<char> three_square;

        unordered_map<int, vector<char>> column;

        while (good == true && i < 9) {
            vector<char> row = board[i];

            good = isArrayValid(row);
            if (!good) break;

            for (int j = 0; j < 9; j++) {
                if (j < 3) {
                    one_square.push_back(row[j]);
                } else if (j >= 3 && j < 6) {
                    two_square.push_back(row[j]);
                } else {
                    three_square.push_back(row[j]);
                }

                column[j].push_back(row[j]);
            }

            if (one_square.size() == 9) {
                good = (isArrayValid(one_square) && 
                isArrayValid(two_square) && isArrayValid(three_square));

                one_square.clear();
                two_square.clear();
                three_square.clear();
            }

            i++;
        }

        while (good == true && f < 9) {
            good = isArrayValid(column[f]);
            f++;
        }

        return good;
    }

    bool isArrayValid(vector<char>& sets) {
        unordered_map<char, int> valid;

        for (char ch : sets) {
            if (ch >= '1' && ch <= '9') {
                valid[ch]++;
            }

            if (valid[ch] > 1) {
                return false;
            }
        }

        return true;
    }
};