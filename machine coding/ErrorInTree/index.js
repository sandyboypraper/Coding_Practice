import Tree from "./Tree.js"
import TreeScanner from "./TreeScanner.js"

function main(){
    console.log("sasa")
    let tree = new Tree([['A','B'],['A','C'],['A','D'],['B','C'],['E','F'],['B','D'],['C','E']]);
    TreeScanner.call(tree);
}

main();

