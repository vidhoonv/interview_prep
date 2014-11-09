/*
*
* http://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths/
*
*/
#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};

int sumNumsRoottoLeaf(TreeNode * tree, int num){
	if(tree==NULL){
		return 0;
	}
	num=num*10+tree->data;
	if(tree->left==NULL && tree->right==NULL)
		return num;

	int lnsum,rnsum;
	lnsum=sumNumsRoottoLeaf(tree->left,num);
	rnsum=sumNumsRoottoLeaf(tree->right,num);

	return(lnsum+rnsum);
}
int main(){
	TreeNode *root = new TreeNode(6);
    root->left        = new TreeNode(3);
    root->right       = new TreeNode(5);
    root->right->right= new TreeNode(7);
    root->left->left  = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    cout<<sumNumsRoottoLeaf(root,0)<<endl;
	return 0;
}

