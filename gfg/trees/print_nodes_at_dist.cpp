#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};

bool isLeaf(TreeNode *tree){
	if(tree==NULL)
		return true;

	if(tree->left==NULL && tree->right==NULL)
		return true;

	return false;
}
void print_nodes_at_dist_from_leaves_helper(TreeNode *tree, int k, vector<int> &dist){
	if(tree==NULL || isLeaf(tree)){
		dist.push_back(0);
		return;
	}

	vector<int> ldist,rdist;
	bool found=false;
	print_nodes_at_dist_from_leaves_helper(tree->left,k,ldist);
	print_nodes_at_dist_from_leaves_helper(tree->right,k,rdist);
	int i=0;
	for(i=0;i<ldist.size();i++){
		dist.push_back(ldist[i]+1);
		if(ldist[i]+1==k && found==false){
			cout<<tree->data<<endl;
			found=true;
		}
	}
	for(i=0;i<rdist.size();i++){
		dist.push_back(rdist[i]+1);
		if(rdist[i]+1==k && found==false){
			cout<<tree->data<<endl;
			found=true;
		}
	}
}
void print_nodes_at_dist_from_leaves(TreeNode * tree, int k){
	vector<int> dt;
	print_nodes_at_dist_from_leaves_helper(tree,k,dt);
}
int main(){
	TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);


    print_nodes_at_dist_from_leaves(root,1);
    //cout<<endl;
	return 0;
}