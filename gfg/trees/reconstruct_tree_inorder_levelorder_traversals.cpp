#include<iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x): data(x),left(NULL),right(NULL) {}
};


TreeNode* reconstructTree(int inorder[], int lvlorder[],int istart, int iend){
	TreeNode *cur=NULL;
	int i=istart;
	int lvlordersize=iend-istart+1;

	if(istart>iend)
		return NULL;
	cur=new TreeNode(lvlorder[0]);
	
	if(istart==iend)
		return cur;

	for(i=istart;i<=iend;i++){
		if(lvlorder[0]==inorder[i])
			break;
	}
	int inindex=i,j=0,k=0;
	int lvlorderleft[i-istart],lvlorderright[iend-i];

	for(i=0;i<lvlordersize;i++){
		for(j=istart;j<inindex;j++){
			if(lvlorder[i]==inorder[j]){
				lvlorderleft[k++]=lvlorder[i];
			}
		}
	}

	k=0;
	for(i=0;i<lvlordersize;i++){
		for(j=inindex+1;j<=iend;j++){
			if(lvlorder[i]==inorder[j]){
				lvlorderright[k++]=lvlorder[i];
			}
		}
	}

	// cout<<"left level order traversal is"<<endl;
	// for(i=0;i<inindex-istart;i++)
	// 	cout<<lvlorderleft[i]<<"\t";
	// cout<<endl;

	// cout<<"right level order traversal is"<<endl;
	// for(i=0;i<iend-inindex;i++)
	// 	cout<<lvlorderright[i]<<"\t";
	// cout<<endl;

	cur->left=reconstructTree(inorder,lvlorderleft,istart,inindex-1);
	cur->right=reconstructTree(inorder,lvlorderright,inindex+1,iend);

	return cur;
}

void printInorder(TreeNode *tree){
	if(tree==NULL)
		return;
	printInorder(tree->left);
	cout<<tree->data<<"\t";
	printInorder(tree->right);
}

int main(){
	int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    TreeNode *root = reconstructTree(in, level, 0, n - 1);
 
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
    cout<<endl;
	return 0;
}