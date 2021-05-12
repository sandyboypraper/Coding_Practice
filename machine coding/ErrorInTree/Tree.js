import TreeNode from "./TreeNode.js"

export default class Tree{
    constructor(input_data){
        this.data = {};
        for (let index in input_data){
            let node1,node2;
            node1 = this.insertOrGetNewTreeNode(input_data[index][0]);
            node2 = this.insertOrGetNewTreeNode(input_data[index][1]);

            node1.childs.push(node2.id);
            node2.parents.push(node1.id);

            console.log(node1, node2);
        }
    }

    insertOrGetNewTreeNode(node_id){
        let node = this.data[node_id] || new TreeNode(node_id);
        this.data[node_id] = node;
        return node;
    }
}