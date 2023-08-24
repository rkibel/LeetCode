/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
String.prototype.leftJustify = function( length, char ) {
    var fill = [];
    while ( fill.length + this.length < length ) {
      fill[fill.length] = char;
    }
    return this + fill.join('');
}

var fullJustify = function(words, maxWidth) {
    let index = 0
    let res = []
    while (index < words.length) {
        let lastline = (index == words.length - 1)
        let arr = [words[index]]
        let tot = words[index].length
        index++
        for (; index < words.length && tot + arr.length + words[index].length <= maxWidth; index++) {
            tot += words[index].length
            arr.push(words[index])
            if (index == words.length - 1) lastline = true
        }
        if (arr.length == 1 || lastline) {
            res.push(arr.join(' ').leftJustify(maxWidth, ' '))
        }
        else {
            for (let i = 0; i < maxWidth - tot; i++) arr[i % (arr.length-1 || 1)] += ' '
            res.push(arr.join(''))
        }
    }
    return res
}