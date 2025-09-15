/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function(text, brokenLetters) {
    let arr = text.split(" ");
    let count = 0;

    for(let i=0; i < arr.length; i++){
        let s = arr[i];
        let flag = true;

        for(let ch of s){
            if(brokenLetters.includes(ch)){
                flag = false;
                break;
            }
        }

        if(flag) count++;
    }

    return count;
};