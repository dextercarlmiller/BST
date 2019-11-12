#include "bst.h"
int main(){
    ifstream inFile;
    inFile.open("lots_ints.txt");
    int temp;
    int choice;
    bst tree;
    bst();
    cout << "Enter an integer of how many Nodes you want in the BST: ";
    cin >> choice;
    cout << endl << "Making Binary Tree Structure..." << endl;
    for (int count = 0; count < choice; count++){
        inFile >> temp;
        tree.add(temp);
    }
    // cout << "Post Order Print" << endl;
    // tree.postorderprint();
    // cout << endl;
    // cout << "Pre Order Print" << endl;
    // tree.preorderprint();
    // cout << endl;
    // cout << "In Order Print" << endl;
    // tree.inorderprint();
    tree.show(1);
    cout << endl;
    inFile.close();
    tree.destroy();
return 0;
}