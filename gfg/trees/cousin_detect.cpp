#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL){}
};

struct qTreeNode{
	TreeNode *tnode,*tpar;
	qTreeNode(): tnode(NULL),tpar(NULL){}
};

bool arecousins(TreeNode *tree,TreeNode* n1,TreeNode *n2){
	if(tree==NULL)
		return false;

	if(tree==n1 || tree==n2)
		return false; //no node can be cousin to root
	bool found=false;
	int flvl=-1;
	TreeNode *par=NULL;
	int lvl=0;
	int cchild=0,pchild=1;
	qTreeNode *cur= new qTreeNode;
	cur->tnode=tree;
	cur->tpar=NULL;


	queue<qTreeNode*> tq;

	tq.push(cur);

	while(tq.empty()==false){
		cur=tq.front();
		tq.pop();
		pchild--;
		if(cur->tnode==n1 || cur->tnode==n2){
			if(found==false){
				found=true;
				flvl=lvl;
				par=cur->tpar;
			}
			else if(flvl<lvl)
				return false;
			else{
				if(flvl==lvl && cur->tpar!=par)
					return true;
				else 
					return false;
			}
		}
		if(cur->tnode->left){
			qTreeNode *lft=new qTreeNode;
			lft->tnode=cur->tnode->left;
			lft->tpar=cur->tnode;
			tq.push(lft);
			cchild++;
		}

		if(cur->tnode->right){
			qTreeNode *rgt=new qTreeNode;
			rgt->tnode=cur->tnode->right;
			rgt->tpar=cur->tnode;
			tq.push(rgt);
			cchild++;
		}

		if(pchild==0){
			pchild=cchild;
			cchild=0;
			lvl++;
		}
	}
}
int main(){
	TreeNode *root = new TreeNode(1);
    root->left =  new TreeNode(2);
    root->right =  new TreeNode(3);
    root->left->left =  new TreeNode(4);
    root->left->right =  new TreeNode(5);
    root->left->right->right =  new TreeNode(15);
    root->right->left =  new TreeNode(6);
    root->right->right =  new TreeNode(7);
    root->right->left->right =  new TreeNode(8);
 
    TreeNode *Node1,*Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;
 
    if(arecousins(root,Node1,Node2))
    	 cout<<"Yes"<<endl;
   	else
   		 cout<<"No"<<endl;
 
    return 0;
	return 0;
}