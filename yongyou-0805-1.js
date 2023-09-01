/**   100%
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型一维数组 
 * @param target int整型 
 * @return int整型
 */
//查找升序数组中最后一个目标元素
function findLastIndex(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    let result = -1;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      if (arr[mid] === target) {
        result = mid;
        left = mid + 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return result;
}

function search( nums ,  target ) {
    // write code here
    let idx = nums.indexOf(target),boo=false
    while(nums[idx]==target){
        idx++;
        boo=true
    }
    return boo ? idx-1 : idx;
    console.log(idx)
    // let idx = -1;
    // let l=0,r=nums.length-1;
    // while(l<r){
    //     console.log(l,r)
    //     let m=Math.floor((l+r)/2);
    //     console.log(m)
    //     if(nums[m]>target) r=m;
    //     if(nums[m]<target) l=m;
    //     if(nums[m]==target){
    //         idx=m;
    //         console.log("hhh")
    //         break;
    //         // l=m;
    //     }
    // }
    // while(nums[idx]==target){
    //     idx++;
    // }
    // return idx-1;
    // for(let i of nums){
    //     if(i!=target){
    //         if(idx!=-1) return idx;
    //         else continue;
    //     } 
    //     else idx=i;
    // }
    // return idx;
}
module.exports = {
    search : search
};