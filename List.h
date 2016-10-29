#include <iostream>
using namespace std;

struct RBNode
{
    RBNode();

	char color;
	int data;

	RBNode * left;
	RBNode * right;
	
};

class RBTree
{
	public:
	RBTree();
	~RBTree();
	void Insert(int);
	void Remove(int);
	void Search(int);
	void DisplayOne();
	void DisplayTree();

	private:
	RBNode * root;

	void DisplayTree(RBNode *&);
    void DeleteTree(RBNode *&);

};
