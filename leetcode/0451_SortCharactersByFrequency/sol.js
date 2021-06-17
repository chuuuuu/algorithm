let frequencySort = function(s) {
    let len = s.length
    let map = {}
    for(let i=0; i<len; i++){
        if(map[s[i]] == undefined){
            map[s[i]] = 1
        }
        else{
            map[s[i]] += 1
        }
    }

    let arr = Object.entries(map)
    arr.sort((a, b)=>{
        return - a[1] + b[1]
    })
    console.log(arr)
    let arrlen = arr.length
    let ret = ''
    for(let i=0; i<arrlen; i++){
        for(let j=0; j<arr[i][1]; j++){
            ret += arr[i][0]
        }
    }

    return ret
}