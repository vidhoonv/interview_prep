#include<iostream>
#include<limits.h>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL){}
};

bool isLeaf(TreeNode * tree){
	if(tree==NULL)
		return true;

	if(tree->left==NULL && tree->right==NULL)
		return true;

	return false;
}
int maxsum_between_leaves(TreeNode *tree, int &sum){
	if(tree==NULL)
		return 0;
	if(isLeaf(tree)){
		sum=tree->data;
		return tree->data;
	}

	int lsum=INT_MIN,rsum=INT_MIN,tsum=tree->data;
	int ltreesum=0,rtreesum=0;
	if(tree->left){
		ltreesum=maxsum_between_leaves(tree->left,lsum);
		tsum+=lsum;
	}

	if(tree->right){
		rtreesum=maxsum_between_leaves(tree->right,rsum);
		tsum+=rsum;
	}

	sum=max(lsum,rsum)+tree->data;
	int local_maxsum=max(sum,tsum);
	return max(local_maxsum,max(ltreesum,rtreesum));
}
int main(){
	TreeNode *root = new TreeNode(-15);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(-8);
    root->left->right = new TreeNode(1);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->right->right= new TreeNode(0);
    root->right->right->right->left= new TreeNode(4);
    root->right->right->right->right= new TreeNode(-1);
    root->right->right->right->right->left= new TreeNode(10);
    int s=0;
    cout << "Max pathSum of the given binary tree is " << maxsum_between_leaves(root,s);

	return 0;
}