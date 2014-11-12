/*
*
*http://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/
*
*/

#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};

bool isLeaf(TreeNode *tree){
	if(tree==NULL)
		return false;
	if(tree->left==NULL and tree->right==NULL)
		return true;

	return false;
}
TreeNode* removeNonKSumPathsHelper(TreeNode *tree, int k, int &sum){
	if(tree==NULL)
		return NULL;

	int ls=0,rs=0;
	tree->left=removeNonKSumPathsHelper(tree->left,k,ls);
	tree->right=removeNonKSumPathsHelper(tree->right,k,rs);

	sum=tree->data+max(ls,rs);
	if(sum>=k)
		return tree;
	else{
		delete tree;
		return NULL;
	}
}
TreeNode* removeNonKSumPaths(TreeNode *tree, int k){
	int s=0;
	if(tree==NULL)
		return NULL;	
return(removeNonKSumPathsHelper(tree,k,s));
	
}
void printTree(TreeNode *tree){
	if(tree==NULL)
		return;
	printTree(tree->left);
	cout<<tree->data<<"\t";
	printTree(tree->right);
}
int main(){

	int k = 45;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(12);
    root->right->right->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);
    root->left->left->right->left = new TreeNode(13);
    root->left->left->right->right = new TreeNode(14);
    root->left->left->right->right->left = new TreeNode(15);

	printTree(root);
	cout<<endl;
	root=removeNonKSumPaths(root,k);
	printTree(root);
	cout<<endl;
	return 0;
}
