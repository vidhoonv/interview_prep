/*

http://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/


*/
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct TreeNode{
	char data;
	TreeNode *left,*right;
	TreeNode(char x): data(x),left(NULL),right(NULL){}
};

void get_in_str(TreeNode *tree,string &s){
	if(tree==NULL)
		return;
	get_in_str(tree->left,s);
	ostringstream os;
	os<<tree->data;
	s.append(os.str());
	get_in_str(tree->right,s);
}

void get_pre_str(TreeNode *tree,string &s){
	if(tree==NULL)
		return;
	
	ostringstream os;
	os<<tree->data;
	s.append(os.str());
	get_in_str(tree->left,s);
	get_in_str(tree->right,s);
}
bool checksubtree(TreeNode *par, TreeNode *sub){
	bool in_status=false,pre_status=false;
	string in_sub(""),pre_sub("");
	string in_par(""),pre_par("");

	get_in_str(par,in_par);
	get_pre_str(par,pre_par);

	get_in_str(sub,in_sub);
	get_pre_str(sub,pre_sub);

	int sublen=in_sub.size();
	for(int i=0;i<in_par.size()-sublen;i++){
		string in_subs=in_par.substr(i,sublen);
		if(in_subs==in_sub)
			in_status=true;
	}

	if(in_status==false)
		return false;

	for(int i=0;i<pre_par.size()-sublen;i++){
		string pre_subs=pre_par.substr(i,sublen);
		if(pre_subs==pre_sub)
			pre_status=true;
	}	

	return(pre_status && in_status);
}
int main(){
	TreeNode *T = new TreeNode('a');
    T->left = new TreeNode('b');
    T->right = new TreeNode('d');
    T->left->left = new TreeNode('c');
    T->right->right = new TreeNode('e');
 
    TreeNode *S = new TreeNode('a');
    S->left = new TreeNode('b');
    S->left->left = new TreeNode('c');
    S->right = new TreeNode('d');
 
    if (checksubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
	return 0;
}