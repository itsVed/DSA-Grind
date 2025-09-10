/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let n = strs.length;

    if(n === 0) return "";

    let prefix = strs[0];

    for(let i=1; i < n; i++){

        while(!strs[i].startsWith(prefix)){
            prefix = prefix.substring(0, prefix.length - 1);

            if(prefix.length === 0){
                return "";
            }
        }
    }

    return prefix;
};