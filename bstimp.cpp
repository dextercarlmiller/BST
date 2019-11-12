#include "BST.h"
bst::bst(){
	root = NULL;
}
void bst::add(int data){
	root = insert(root,data);
	cout << "root --------" << root->data << endl;
}
node* bst::createNode(int data){
	node* Newnode = new node;
	Newnode->data = data;
	Newnode->height = 0;
	Newnode->left = NULL;
	Newnode->right = NULL;
	cout << "insert value:" << data << endl;
	return Newnode;
}
node* bst::insert(node*n, int data){
	//Step 1: Standard BST insertion
	// if nothing, create
	if (n == NULL){
		return createNode(data);
	}
	// if data is less than node data, move left	
	if (n->data > data){
			n->left = insert(n->left, data);
		}
	// if data is greater than node data, move right
	else if (n->data < data){
			n->right = insert(n->right, data);
		}
	else
		return n;
	//update height
	n->height = height(n);
	//balance the tree
	return balance(n);
}
int bst::height(node* node){  
    if (node == NULL)  
        return 0;  
    else{  
        /* compute the depth of each subtree */
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
		
        /* use the larger one */
        if (lDepth > rDepth){
			return(lDepth + 1); 
		}  
        else{ 
			return(rDepth + 1);  
        }
	}  
}
node* bst::balance(node*node){
	int bal_factor = balanceFactor(node);
	if (bal_factor >1){
		if (balanceFactor(node->left) > 0){
			cout << endl << "---rr_rotate---" << endl;
			return RightRotate(node);
		}
		else {
			cout << endl << "---lr_rotate---" << endl;
			node->left = LeftRotate(node->left);
			return RightRotate(node);
		}
	}
	else if (bal_factor < -1){
		if (balanceFactor(node->right) > 0){
			cout << endl << "---rl_rotate---" << endl;
			node->right = RightRotate(node->right);
			return LeftRotate(node);
		}
		else{
			cout << endl << "---ll_rotate---" << endl;
			return LeftRotate(node);
		}
	}
	return node;	
}
int bst::balanceFactor(node*node){
	if (node == NULL)
		return 0;
	return (height(node->left) - height(node->right));
}
node* bst::LeftRotate(node*n){
	//set variables
	node* y = n->right;
	node* T2 = y->left;
	//perform rotation
	y->left = n;
	n->right = T2;
	//update heights
	n->height = height(n);
	y->height = height(y);
	return y;
}
node* bst::RightRotate(node*n){
	node* y = n->left;
	node* T2 = y->right;

	y->right = n;
	n->left = T2;

	n->height = height(n);
	y->height = height(y);
	return y;
}
void bst::inorderRecursion(node*n){
	if (n != NULL){
		inorderRecursion(n->left);
		cout << n->data << endl;
		inorderRecursion(n->right);
		}
}
void bst::preorderRecursion(node*n){
	if(n != NULL){
		cout << n->data << endl;
		preorderRecursion(n->left);
		preorderRecursion(n->right);
	}
}
void bst::postorderRecursion(node*n){
	if (n != NULL){
		postorderRecursion(n->left);
		postorderRecursion(n->right);
		cout << n->data << endl;
	}
}
void bst::postorderprint(){
	postorderRecursion(root);
}
void bst::preorderprint(){
	preorderRecursion(root);
}
void bst::inorderprint(){
	inorderRecursion(root);
}
void bst::show(int l){
	cout << endl << "AVL Tree:" << endl;
	print(root,l);
}
void bst::print(node *p, int l) {
   int i;
   if (p != NULL) {
      print(p->left, l+ 1);
      cout<<" ";
      if (p == root)
         cout << "Root -> ";
      for (i = 0; i < l&& p != root; i++)
         cout << " ";
      cout << p->data;
      print(p->right, l + 1);
   }
}
//Deconstructor
void bst::clear(node*n){
	if(n->left != NULL)
		clear(n->left);	
	else if (n->right != NULL)
		clear(n->right);
	delete n;
}
void bst::destroy(){
	clear(root);
}