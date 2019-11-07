#include "BST.h"

bst::bst()
{
root = NULL;
}

void bst::insert(node*n, int data)
{
	// if nothing, create
	if (root == NULL)
	{
		root = createNode(data);
	}
	// if a left node exists, move left	
	else if (n->data > data)
	{
		if(n->left != NULL) 
		{
			insert(n->left, data);
		}
		else
		{
			n->left = createNode(data);
		}
	}
	// if a right node exists, move right
	else if (n->data < data)
	{
		if(n->right != NULL)
		{
			insert(n->right, data);
		}
		else
		{
			n->right = createNode(data);
		}
	}
}

node* bst::createNode(int data)
{
node* Newnode = new node;
Newnode->data = data;
Newnode->left = NULL;
Newnode->right = NULL;
return Newnode;
}

void bst::add(int data)
{
	insert (root,data);
}
int bst::maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}
void bst::maxDepthRun(){
	int depth = maxDepth(root);
	cout << "The max Depth is:" << depth << endl;
}
void bst::inorderRecursion(node*n)
{
if (n != NULL){
	inorderRecursion(n->left);
//else
	cout << n->data << endl;
	outFile << n->data << endl;
//if (n->right != NULL)
	inorderRecursion(n->right);
}
}
void bst::preorderRecursion(node*n)
{
if(n != NULL){
	cout << n->data << endl;
	outFile << n->data << endl;
//if (n->left != NULL)
	preorderRecursion(n->left);
//else if (n->right != NULL)
	preorderRecursion(n->right);
}
}
void bst::postorderRecursion(node*n)
{
if (n != NULL){
	postorderRecursion(n->left);
//else if (n->right != NULL)
	postorderRecursion(n->right);
//else  
	cout << n->data << endl;
	outFile << n->data << endl;
}
}
//Deconstructor
void bst::clear(node*n)
{
if(n->left != NULL)
	clear(n->left);	
else if (n->right != NULL)
	clear(n->right);
delete n;
}
void bst::destroy()
{
clear(root);
}

void bst::postorderprint()
{
outFile.open("postorderprint.txt");
outFile << "Post Order Print:" << endl;
postorderRecursion(root);
outFile.close();
}

void bst::preorderprint()
{
outFile.open("preorderprint.txt");
outFile << "Pre Order Print:" << endl;
preorderRecursion(root);
outFile.close();
}

void bst::inorderprint()
{
outFile.open("inorderprint.txt");
outFile << "In Order Print:" << endl;
inorderRecursion(root);
outFile.close();
}

