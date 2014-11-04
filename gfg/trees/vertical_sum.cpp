#include<iostream>
#include<map>

using namespace std;

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 };

map<int,int> mp;
void verticalSum(TreeNode *tree, int hd){
	if(tree==NULL)
		return;
	map<int,int>::iterator mit=mp.find(hd);
	if(mit==mp.end()){
		mp.insert(make_pair(hd,tree->data));
	}
	else{
		mp[hd]=mp[hd]+tree->data;
	}
	verticalSum(tree->left,hd-1);
	verticalSum(tree->right,hd+1);
}
void printVerticalSum(TreeNode *tree){
	verticalSum(tree,0);
	map<int,int>::iterator mit=mp.begin();

	while(mit!=mp.end()){
		cout<<mit->second<<endl;
		++mit;
	}
	return;
}
int main(){

	TreeNode *root         = new TreeNode(20);
    root->left                = new TreeNode(8);
    root->left->left          = new TreeNode(4);
    root->left->right         = new TreeNode(12);
    root->left->right->left   = new TreeNode(10);
    root->left->right->right  = new TreeNode(14);
    root->right               = new TreeNode(22);
    root->right->right        = new TreeNode(25);

    printVerticalSum(root);
	return 0;
}