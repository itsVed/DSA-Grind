class Solution {
public:
    string pushDominoes(string d) {
        int n = d.length();
        int idx = -1;
        int len = 0;
        char ch = '#';

        for (int i = 0; i <= n; i++) {
            if (i < n && d[i] == '.') {
                if (idx == -1) idx = i;
                len++;
            } else {
                if (len > 0) {
                    char next = (i < n) ? d[i] : '#';

                    if (ch == 'L' && next == 'L') {
                        for (int j = 0; j < len; j++)
                            d[idx + j] = 'L';
                    } else if (ch == 'R' && next == 'R') {
                        for (int j = 0; j < len; j++)
                            d[idx + j] = 'R';
                    } else if (ch == 'R' && next == 'L') {
                        int l = 0, r = len - 1;
                        while (l < r) {
                            d[idx + l] = 'R';
                            d[idx + r] = 'L';
                            l++;
                            r--;
                        }
                        // if len is odd, middle stays '.'
                    } else if (ch == '#' && next == 'L') {
                        for (int j = 0; j < len; j++)
                            d[idx + j] = 'L';
                    } else if (ch == 'R' && next == '#') {
                        for (int j = 0; j < len; j++)
                            d[idx + j] = 'R';
                    }
                    // else: do nothing for isolated or L...R

                    len = 0;
                    idx = -1;
                }

                if (i < n && d[i] != '.')
                    ch = d[i];
            }
        }

        return d;
    }
};
