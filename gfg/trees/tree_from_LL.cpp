/*
*
* http://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/
*
*/
#include<iostream>
#include<queue>

using namespace std;

struct ListNode
{
    int data;
    ListNode* next;
};
struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 };
TreeNode* constructTree(ListNode *list){
	if(list==NULL)
		return NULL;

	queue<TreeNode*> tq;
	TreeNode *cur,*head;
	ListNode *cnode=list;

	head=new TreeNode(cnode->data);
	cnode=cnode->next;
	tq.push(head);

	while(cnode!=NULL){
		cur=tq.front();
		tq.pop();

		TreeNode *lnode=new TreeNode(cnode->data);
		tq.push(lnode);
		cur->left=lnode;

		cnode=cnode->next;
		if(cnode==NULL)
			break;

		TreeNode *rnode=new TreeNode(cnode->data);
		tq.push(rnode);
		cur->right=rnode;

		cnode=cnode->next;
	}

	return head;
}

void push(struct ListNode** head_ref, int new_data)
{
    // allocate node and assign data
    struct ListNode* new_node = new ListNode;
    new_node->data = new_data;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // move the head to point to the new node
    (*head_ref)    = new_node;
}

void inorderTraversal(TreeNode* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

int main(){

	ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    TreeNode *root=constructTree(head);
    inorderTraversal(root);
	return 0;
}