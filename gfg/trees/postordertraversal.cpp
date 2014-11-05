#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 };

void recursivePostOrderTraversal(TreeNode *tree){
	if(tree==NULL)
		return;
	recursivePostOrderTraversal(tree->left);
	recursivePostOrderTraversal(tree->right);
	cout<<tree->data<<"\t";
}

void iterativePostOrderTraversal1(TreeNode *tree){
	if(tree==NULL)
		return;

	TreeNode *cur;
	stack<TreeNode *> st,fst;

	st.push(tree);

	while(st.empty()==false){
		cur=st.top();
		st.pop();
		fst.push(cur);

		if(cur->left)
			st.push(cur->left);

		if(cur->right)
			st.push(cur->right);

	}

	while(fst.empty()==false){
		cur=fst.top();
		fst.pop();
		cout<<cur->data<<"\t";
	}

	cout<<endl;
}


void iterativePostOrderTraversal2(TreeNode *tree){
	if(tree==NULL)
		return;

	stack<TreeNode *> st;
	TreeNode *cur,*tmp=NULL;

	cur=tree;
do{
	while(cur!=NULL){
		if(cur->right)
			st.push(cur->right);
		
		st.push(cur);
		cur=cur->left;
	}
	
	while(st.empty()==false){
		cur=st.top();
		st.pop();
		if(st.empty()==false){
			tmp=st.top();
		}
		else{
			tmp=NULL;
		}
		if(cur->right==tmp){
			st.pop();
			st.push(cur);
			cur=tmp;
			break;
		}
		else{
			cout<<cur->data<<"\t";
		}
		
	}
}while(st.empty()==false);


}
int main(){

  TreeNode *root = new TreeNode(1);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7); 

  recursivePostOrderTraversal(root);
  cout<<endl;
  iterativePostOrderTraversal2(root);
  return 0;
}