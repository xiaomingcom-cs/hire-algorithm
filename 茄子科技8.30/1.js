// 本题为考试多行输入输出规范示例，无需提交，不计分。
const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    // Write your code here
    var n = parseInt(await readline());
    var ans = 1;
    var tmp=[]
    for(var i = 0;i < n; i++){
        lines = (await readline());
        var item = lines.split("").sort().join("");
        if(tmp.indexOf(item)==-1){
            tmp.push(item);
        }
        
    }

    console.log(tmp.length);
}()