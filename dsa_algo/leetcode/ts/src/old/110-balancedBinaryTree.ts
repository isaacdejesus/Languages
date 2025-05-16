const isBalanced = (root: TreeNode | null): bool => {
    if(!root)
        return true;
    let leftHeight: number = getHeight(root.left);
    let rightHeight: number = getHeight(root.right);
    return Math.abs(leftHeight - rightHeight) <= 1 && isBalanced(root.left) && isBalanced(root.right);
}

const getHeight = (root: TreeNode | null): number => {
    if(!root)
        return 0;
    return 1 + Math.max(getHeight(root.left) + getHeight(root.right));
}