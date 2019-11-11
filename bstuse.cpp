#include "bst.h"
int main(){
ifstream inFile;
int choice;
inFile.open("lots_ints.txt");
	bst tree;
bst();
cout << "Enter an integer of how many Nodes you want in the BST: ";
cin >> choice;
cout << "Making Binary Tree Structure" << endl;
for (int count = 0; count < choice; count++)
{
int temp;
inFile >> temp;
tree.add(temp);
}
cout << "Post Order Print" << endl;
tree.postorderprint();
cout << endl;

cout << "Pre Order Print" << endl;
tree.preorderprint();
cout << endl;

cout << "In Order Print" << endl;
tree.inorderprint();
cout << endl;
inFile.close();
tree.destroy();
return 0;
}