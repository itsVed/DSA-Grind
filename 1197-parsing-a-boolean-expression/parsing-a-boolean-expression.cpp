class Solution {
public:

    bool f(int &index, string &s){
        char ch = s[index++];

        if(ch == 't') return true;
        if(ch == 'f') return false;

        if(ch == '!'){
            index++;
            bool result = !f(index, s);
            index++;

            return result;
        }

        vector<bool> val;
        index++;

        while(s[index] != ')'){
            if(s[index] != ','){
                val.push_back(f(index, s));
            }
            else{
                index++;
            }
        }

        index++;

        if(ch == '&'){
            for(int v: val){
                if(!v) return false;
            }

            return true;
        }

        if(ch == '|'){
            for(int v: val){
                if(v) return true;
            }

            return false;
        }
        

        return false;
    }

    bool parseBoolExpr(string expression) {
        int index = 0;

        return f(index, expression);
    }
};