/**
 * @param {string} s
 * @return {boolean}
 */
var doesAliceWin = function(s) {
    let n = s.length;
    let v = 0;

    for(let i=0; i < n; i++){
        if("aeiou".includes(s[i])){
            v++;
        }
    }

    if(v === 0) return false;
    
    return true;
};