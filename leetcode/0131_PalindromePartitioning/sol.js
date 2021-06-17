let partition = function(s) {
    let lists = []

    let checkPld = (s)=>{
        let len = s.length
        for(let i=0; i<len; i++){
            if(s[i] != s[len - i - 1]){
                return false;
            }
        }

        return true
    }

    let dfs = (s, list)=>{
        if(s == ""){
            lists.push(list)
            return
        }

        let len = s.length
        for(let i=0; i<len; i++){
            if(checkPld(s.substring(0, i+1))){
                dfs(s.substring(i+1), [...list, s.substring(0, i+1)]) //hard copy
            }
        }
    }
    
    dfs(s, [])
    
    return lists  
};