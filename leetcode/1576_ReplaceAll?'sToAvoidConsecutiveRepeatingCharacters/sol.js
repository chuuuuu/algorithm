/**
 * @param {string} s
 * @return {string}
 */
var modifyString = function (s) {
    String.prototype.replaceAt = function (i, chr) {
        return this.substr(0, i) + chr + this.substr(i + 1)
    }

    let len = s.length

    for (let i = 0; i < len; i++) {
        if (s[i] == '?') {
            if ('a' != s[i - 1] && 'a' != s[i + 1]) {
                // s[i] = 'a'
                // we cannot write like this, since string in javascript is immutable
                s = s.replaceAt(i, 'a')
            }
            else if ('b' != s[i - 1] && 'b' != s[i + 1]) {
                s = s.replaceAt(i, 'b')
            }
            else if ('c' != s[i - 1] && 'c' != s[i + 1]) {
                s = s.replaceAt(i, 'c')
            }
            else {
                console.log('error')
            }
        }
    }

    return s
};