/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
    
    let current = root;
    let next = null;
    if(root !== null)
        next = root.left;
    while(current && next)
    {
        current.left.next = current.right;
        if(current.next !== null )
            current.right.next = current.next.left;
        current = current.next;
        if(!current)
        {
            current = next;
            next = current.left;
        }
    }
    return root;
};