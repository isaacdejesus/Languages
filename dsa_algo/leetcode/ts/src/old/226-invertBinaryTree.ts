class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null)
    {
        this.val = (val === undefined ? 0 : val);
        this.left = (left === undefined ? null : left);
        this.right = (right === undefined ? null : right);
    }
}
const invertBTree = (root: TreeNode | null): TreeNode | null => {
    if(!root) return null;
    const leftNode = root.left;
    root.left = root.right;
    root.right = leftNode;
    invertBTree(root.left);
    invertBTree(root.right);
    return root;
};

const invertBTree2 = (root: TreeNode | null): TreeNode | null => {
    if(root){
        let swap = root.left;
        root.left = invertBTree2(root.right);
        root.right = invertBTree2(swap);
    }
    return root;
};
const invertBTree3 = (root: TreeNode | null): TreeNode | null => {
    if(!root)
        return null;
    const node = new TreeNode(
        root.val,
        invertBTree3(root.right),
        invertBTree3(root.left),
    )
    return node;
};
