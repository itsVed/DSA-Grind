/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let ans = "";

    let n = a.length, m = b.length;

    let t = Math.min(n, m);   
    let carry = 0;

    
    for (let i = 0; i < t; i++) {
        let ai = a[n - 1 - i];
        let bi = b[m - 1 - i];

        if (ai === '1' && bi === '1') {
            if (carry === 1) {
                ans = '1' + ans;   
            } else {
                ans = '0' + ans;
            }
            carry = 1;
        }
        else if (ai === '0' && bi === '0') {
            if (carry === 1) {
                ans = '1' + ans;
                carry = 0;
            } else {
                ans = '0' + ans;
            }
        }
        else { 
            if (carry === 1) {
                ans = '0' + ans;
                carry = 1;
            } else {
                ans = '1' + ans;
                carry = 0;
            }
        }
    }

    for (let i = n - t - 1; i >= 0; i--) {
        let bit = a[i];
        if (bit === '1' && carry === 1) {
            ans = '0' + ans;
            carry = 1;
        } else if (bit === '0' && carry === 1) {
            ans = '1' + ans;
            carry = 0;
        } else {
            ans = bit + ans;
        }
    }

    for (let i = m - t - 1; i >= 0; i--) {
        let bit = b[i];
        if (bit === '1' && carry === 1) {
            ans = '0' + ans;
            carry = 1;
        } else if (bit === '0' && carry === 1) {
            ans = '1' + ans;
            carry = 0;
        } else {
            ans = bit + ans;
        }
    }

    if (carry === 1) {
        ans = '1' + ans;
    }

    return ans;
};
