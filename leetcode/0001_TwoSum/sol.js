var twoSum = function(nums, target) {
    let len = nums.length
    let map = {}

    for(i=0; i!=len; i++){
        let x = target - nums[i]
        if(map[x] === undefined){
            map[nums[i]] = i;
        }
        else{
            return[i, map[x]]
        }
    }
};