/*
*
* http://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree/
*
*/

#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};


TreeNode* deepestLeftLeaf(TreeNode *tree, int &height){

	if(tree==NULL){
		height=0;
		return NULL;
	}

	
	int lh,rh;
	TreeNode* lt_leaf=deepestLeftLeaf(tree->left,lh);
	TreeNode* rt_leaf=deepestLeftLeaf(tree->right,rh);
	if(lt_leaf==NULL && rt_leaf==NULL){
		//leaf case
		height=1;
		return tree;
	}

	if(rt_leaf==tree->right){		
		if(lt_leaf==NULL){
			height=0;
			return NULL;
		}
		else{
			height=lh+1;
			return lt_leaf;
		}
	}
	else{
		if(lh>rh){
			height=lh+1;
			return lt_leaf;
		}
		else{
			height=rh+1;
			return rt_leaf;
		}
	}
}
int main(){
	TreeNode* root = new TreeNode(1);
    root->left =  new TreeNode(2);
    root->right =  new TreeNode(3);
    root->left->left =  new TreeNode(4);
    root->right->left =  new TreeNode(5);
    root->right->right =  new TreeNode(6);
    root->right->left->right =  new TreeNode(7);
    root->right->right->right =  new TreeNode(8);
    root->right->left->right->left =  new TreeNode(9);
    root->right->right->right->right =  new TreeNode(10);

    int ht=0;
    TreeNode *dll=deepestLeftLeaf(root,ht);
    if(dll==NULL)
    	cout<<"no deepest left leaf"<<endl;
    else
    	cout<<dll->data<<" height: "<<ht<<endl;
	return 0;
}