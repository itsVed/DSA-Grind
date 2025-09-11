/**
 * @param {string} s
 * @return {string}
 */
var sortVowels = function (s) {
    let str = "";
    let n = s.length;
    let vowel = "aeiouAEIOU";

    for (let i = 0; i < n; i++) {
        if (vowel.includes(s[i])) {
            str += s[i];
        }
    }

    str = str.split('').sort().join(''); // as string don't have sort function in JS so we need to convert it in array  of string

    let arr = s.split('');
    let j = 0;

    for (let i = 0; i < n; i++) {
        if (vowel.includes(arr[i])) {
            arr[i] = str[j++];
        }
    }

    return arr.join('');
};
