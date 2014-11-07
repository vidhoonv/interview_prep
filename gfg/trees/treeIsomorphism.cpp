#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};

bool checkIsomorphism(TreeNode *t1, TreeNode *t2){
	if(t1==NULL && t2==NULL)
		return true;

	if(t1!=NULL && t2!=NULL){
		if(t1->data!=t2->data)
			return false;
		else{
			return((checkIsomorphism(t1->left,t2->left)&&checkIsomorphism(t1->right,t2->right))||(checkIsomorphism(t1->left,t2->right)&&checkIsomorphism(t1->right,t2->left)));
		}

	}
	return false;
}
int main(){
	 TreeNode *n1 = new TreeNode(1);
    n1->left        =  new TreeNode(2);
    n1->right       =  new TreeNode(3);
    n1->left->left  =  new TreeNode(4);
    n1->left->right =  new TreeNode(5);
    n1->right->left  =  new TreeNode(6);
    n1->left->right->left =  new TreeNode(7);
    n1->left->right->right =  new TreeNode(8);
 
    TreeNode *n2 =  new TreeNode(1);
    n2->left         =  new TreeNode(3);
    n2->right        =  new TreeNode(2);
    n2->right->left   =  new TreeNode(4);
    n2->right->right   =  new TreeNode(5);
    n2->left->right   =  new TreeNode(6);
    n2->right->right->left =  new TreeNode(8);
    n2->right->right->right =  new TreeNode(7);
 
    if (checkIsomorphism(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";
 
    return 0;
}