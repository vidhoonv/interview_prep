#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};

void reverseLevelOrder(TreeNode *tree){

	if(tree==NULL)
		return;

	TreeNode *cur;
	stack<TreeNode *> st;
	queue<TreeNode *> tq;

	tq.push(tree);

	while(tq.empty()==false){
		cur=tq.front();
		tq.pop();

		if(cur->right)
			tq.push(cur->right);

		if(cur->left)
			tq.push(cur->left);

		st.push(cur);
	}

	while(st.empty()==false){
		cur=st.top();
		cout<<cur->data<<"\t";
		st.pop();
	}
	cout<<endl;
}
map<int,vector<int>,std::greater<int> > mp;
void reverseLevelOrder2Helper(TreeNode *tree, int vlevel){
	mp[vlevel].push_back(tree->data);
	if(tree->left)
		reverseLevelOrder2Helper(tree->left,vlevel+1);
	if(tree->right)
		reverseLevelOrder2Helper(tree->right,vlevel+1);
}
void reverseLevelOrder2(TreeNode *tree){
	if(tree==NULL)
		return;

	reverseLevelOrder2Helper(tree,0);

	map<int,vector<int> >::iterator mit=mp.begin();
	while(mit!=mp.end()){
		vector<int> vec=mit->second;
		int n=vec.size();
		for(int i=0;i<n;i++)
			cout<<vec[i]<<"\t";
		cout<<endl;
		++mit;
	}
}
int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	reverseLevelOrder(root);
	reverseLevelOrder2(root);
	return 0;
}