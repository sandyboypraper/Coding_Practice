#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        char data;
        TreeNode* parents[];
        TreeNode* children[];
        void insert_child(){
            
        }
}

class Tree{
    TreeNode tree_nodes[];
    public:
        Tree(char input_data[][2]){
            for(int i = 0;i<input_data.length();i++)
            {
                TreeNode tree_node1;
                tree_node.data = input_data[i][0];

                TreeNode tree_node2;
                tree_node2.data = input_data[i][1];

                tree_node1.insert_child()
            }
        }
}

int main(){
    Tree tree([['A','B'],['A','C'],['B','G'],['C','H'],['E','F'],['B','D'],['C','E']]);
    return 0;
}