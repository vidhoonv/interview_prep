#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	int hd;
	TreeNode(int x): data(x),hd(-1),left(NULL),right(NULL) {}
};

map<int,int> tmp,bmp;
void populateBottomViewHelper(TreeNode *tree){
	if(tree==NULL)
		return;
	int hdist=0;
	queue<TreeNode*> tq;
	TreeNode *cur;
	tree->hd=hdist;
	tq.push(tree);

	while(tq.empty()==false){
		cur=tq.front();
		tq.pop();
		hdist=cur->hd;
		bmp[hdist]=cur->data;
		
		if(cur->left){
			cur->left->hd=hdist-1;
			tq.push(cur->left);
		}
		if(cur->right){
			cur->right->hd=hdist+1;
			tq.push(cur->right);
		}
	}
	
}
void printBottomView(TreeNode *tree){
	populateBottomViewHelper(tree);
	map<int,int>::iterator mit=bmp.begin();

	while(mit!=bmp.end()){
		cout<<mit->second<<"\t";
		++mit;
	}
	cout<<endl;
}
void populateTopViewHelper(TreeNode *tree){
	if(tree==NULL)
		return;
	int hdist=0;
	queue<TreeNode*> tq;
	TreeNode *cur;
	tree->hd=hdist;
	tq.push(tree);

	while(tq.empty()==false){
		cur=tq.front();
		tq.pop();
		hdist=cur->hd;
		if(tmp.find(hdist)==tmp.end()){
			tmp[hdist]=cur->data;
		}
		if(cur->left){
			cur->left->hd=hdist-1;
			tq.push(cur->left);
		}
		if(cur->right){
			cur->right->hd=hdist+1;
			tq.push(cur->right);
		}
	}
	
}
void printTopView(TreeNode *tree){
	populateTopViewHelper(tree);
	map<int,int>::iterator mit=tmp.begin();

	while(mit!=tmp.end()){
		cout<<mit->second<<"\t";
		++mit;
	}
	cout<<endl;
}
int main(){
	TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    printTopView(root);
    printBottomView(root);
	return 0;
}