//
// http://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
//
//

#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};

TreeNode* extractLeaves(TreeNode* tree){
	if(tree==NULL)
		return NULL;

	TreeNode* lt=extractLeaves(tree->left);
	TreeNode* rt=extractLeaves(tree->right);

	if(lt==NULL && rt==NULL){
		//leaf case
		return tree;
	}

	if(lt==NULL)
		return rt;
	else if(rt==NULL)
		return lt;
	else{

		if(lt==tree->left)
			tree->left=NULL;

		if(rt==tree->right)
			tree->right=NULL;


		TreeNode* pre=lt;
		while(pre->right!=NULL)
			pre=pre->right;
		pre->right=rt;
		rt->left=pre;
		return lt;
	}

}

void printLeaves(TreeNode* tree){
	while(tree!=NULL){
		cout<<tree->data<<"\t";
		tree=tree->right;
	}
	cout<<endl;
}

void print(TreeNode *root)
{
    if (root != NULL)
    {
         print(root->left);
         cout<<root->data<<"\t";
         print(root->right);
    }
}
int main(){

    TreeNode *root = new TreeNode(1);
     root->left = new TreeNode(2);
     root->right = new TreeNode(3);
     root->left->left = new TreeNode(4);
     root->left->right = new TreeNode(5);
     root->right->right = new TreeNode(6);
     root->left->left->left = new TreeNode(7);
     root->left->left->right = new TreeNode(8);
     root->right->right->left = new TreeNode(9);
     root->right->right->right = new TreeNode(10);

     print(root); cout<<endl;
    TreeNode *lfs=extractLeaves(root);
     print(root); cout<<endl;
    printLeaves(lfs);
	return 0;
}