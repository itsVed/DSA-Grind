# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def solve(self, root: Optional[TreeNode], s : str) -> int:
        if root is None :
            return 0

        s += str(root.val)

        if root.left is None and root.right is None :
            return int(s, 2)

        return self.solve(root.right, s) + self.solve(root.left, s)


    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        return self.solve(root, "")
        