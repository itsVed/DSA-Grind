class Spreadsheet {
public:

    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1)) - 1;
        int col = cell[0] - 'A';

        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = stoi(cell.substr(1)) - 1;
        int col = cell[0] - 'A';

        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        size_t pos = formula.find('+');
        int ans = 0;

        string x = formula.substr(0, pos);
        string y = formula.substr(pos + 1);

        int left = 0;
        int right = 0;

        if(isalpha(x[0])){

            int col = x[0] - 'A';
            int row = stoi(x.substr(1)) - 1;

            left = sheet[row][col];
        }
        else{
            left = stoi(x);
        }

        if(isalpha(y[0])){
            
            int col = y[0] - 'A';
            int row = stoi(y.substr(1)) - 1;

            right = sheet[row][col];
        }
        else{
            right = stoi(y);
        }

        return left + right;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */