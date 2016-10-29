#include <iostream>
using namespace std;

struct RBNode
{
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
	void search(int);
	void DisplayOne();
	void DisplayTree();

	private:
	RBNode * root;

	void DisplayTree(RBNode *&);

};
