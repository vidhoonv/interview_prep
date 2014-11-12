#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL){}
};
TreeNode* findLCA(TreeNode *tree, int n1, int n2, bool &found1, bool &found2){
	if(tree==NULL)
		return NULL;



	TreeNode *left_lca=NULL,*right_lca=NULL;
	bool bf1=false,bf2=false;
	left_lca=findLCA(tree->left,n1,n2,bf1,bf2);
	if(bf1==true){
		found1=true;
		bf1=false;
	}
	if(bf2==true){
		found2=true;
		bf2=false;
	}
	if(!found1 || !found2){
		right_lca=findLCA(tree->right,n1,n2,bf1,bf2);
		if(bf1==true){
			found1=true;
			bf1=false;
		}
		if(bf2==true){
			found2=true;
			bf2=false;
		}
	}

	if(tree->data==n1){
		found1=true;
	}
	if(tree->data==n2){
		found2=true;
	}

	
	if(found1 && found2){
		if(left_lca==NULL && right_lca==NULL)
			return tree;
		else if(left_lca==NULL)
			return right_lca;
		else
			return left_lca;			
	}
	else
		return NULL;
}
int main(){
	TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    bool fv1=false,fv2=false;
    TreeNode *lca=findLCA(root,2,7,fv1,fv2);
    if(lca){
    	cout<<lca->data<<endl;
    }
    else{
    	cout<<"no LCA found"<<endl;
    	if(fv1==false)
    		cout<<"value 1 not found"<<endl;
    	if(fv2==false)
    		cout<<"value 2 not found"<<endl;
    }
	return 0;
}