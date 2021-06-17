let simplifyPath = function (path) {
    let emts = path.split('/')
    let emtsNew = []
    let len = emts.length

    for (let i = 0; i < len; i++) {
        if (emts[i] == '..') {
            emtsNew.pop()
        }
        else if (emts[i] == '.' || emts[i] == '') {

        }
        else {
            emtsNew.push(emts[i])
        }
    }

    let lenNew = emtsNew.length
    let ret = ''

    for (let i = 0; i < lenNew; i++) {
        ret = ret + '/' + emtsNew[i]
    }

    return ret ? ret : '/'
}