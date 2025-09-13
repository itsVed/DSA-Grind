/**
 * @param {string} s
 * @return {number}
 */
var maxFreqSum = function(s) {
    let vec = new Array(26).fill(0);
    var maxv = 0;
    var maxc = 0;

    for(let ch of s){
        let idx = ch.charCodeAt(0) - 'a'.charCodeAt(0);
        vec[idx]++;

        if("aeiou".includes(ch)){
            maxv = Math.max(maxv, vec[idx]);
        }
        else{
            maxc = Math.max(maxc, vec[idx]);
        }
    }

    return maxc + maxv;
};