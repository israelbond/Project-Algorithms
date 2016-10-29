#include "List.h"




RBNode::RBNode()
{
    color = 'B';
    data = 0;
    left = right = NULL;
}


RBTree::RBTree()
{
   root = NULL;
}

RBTree::~RBTree()
{
  if(root) DeleteTree(root);
}

void RBTree::Insert(int num)
{

}

void RBTree::Remove(int num)
{
}

void RBTree::Search(int num)
{
}

void RBTree::DisplayOne()
{
}

void RBTree::DisplayTree()
{
	if(root) DisplayTree(root);
}

void RBTree::DisplayTree(RBNode *& root)
{
	if(!root) return;
	DisplayTree(root->left);
	cout <<"\t Data: "<< root->data <<"\t Color: "<< root->color<<"\n";
	DisplayTree(root->right);

}

void RBTree::DeleteTree(RBNode *& root)
{
    if(!root) return;
    
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = NULL;
}
