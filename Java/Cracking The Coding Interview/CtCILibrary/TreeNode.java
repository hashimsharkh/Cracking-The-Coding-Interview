package CtCILibrary;

public class TreeNode {
	public int data;      
	public TreeNode left;    
	public TreeNode right; 
	public TreeNode parent;
	private int size = 0;

	public TreeNode(int d) {
		data = d;
		size = 1;
	}
	
	private void setLeftChild(TreeNode left) {
		this.left = left;
		if (left != null) {
			left.parent = this;
		}
	}
	
	private void setRightChild(TreeNode right) {
		this.right = right;
		if (right != null) {
			right.parent = this;
		}
	}

	public int size()
	{
		return size;
	}

	public static TreeNode createMinimalBST(int array[])
	{
		return createMinimalBST(array,0,array.length-1);
	}

	private static TreeNode createMinimalBST(int arr[], int start, int end)
	{
		if(end<start)
			return null;
		int mid = (start+end)/2;

		TreeNode n = new TreeNode(arr[mid]);

		n.left = createMinimalBST(arr,start,mid-1);
		n.right = createMinimalBST(arr,mid+1,end);
		return n;
	}

	public boolean isBST(){
		if(left !=null)
		{
			if(data < left.data || !left.isBST())
				return false;
		}
		if(right!=null)
		{
			if(data>=right.data || !right.isBST())
				return false;
		}

		return true;
	}


	public int height()
	{
		return ;
	}

	public boolean isBalanced()
	{

			if(height(left)-height(right)>1)
				return false;

	}

}