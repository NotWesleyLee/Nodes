#include<iostream>
#include<string>


class BST
{
private: struct node
{
	std::string name;
	node*left;
	node*right;
};
		 node*root;
public:
	BST() { root = NULL; }
	void insert(node*&r, std::string x)
	{
		if (r == NULL)
		{
			node*p = new node;
			p->name = x;
			p->left = p->right = NULL;
			r = p;
		}
		else
		{
			if (x < r->name) insert(r->left, x);
			if (x > r->name) insert(r->right, x);
		}
	}
	void displayInorder(node*r)
	{
		if (r != NULL)
		{
			displayInorder(r->left);
			std::cout << r->name << " ";
			displayInorder(r->right);
		}
	}
	void displayPreorder(node*r)
	{
		if (r != NULL)
		{
			std::cout << r->name << " ";
			displayPreorder(r->left);
			displayPreorder(r->right);
		}
	}
	void displayPostorder(node*r)
	{
		if (r != NULL)
		{
			displayPostorder(r->left);
			displayPostorder(r->right);
			std::cout << r->name << " ";
		}
	}
	void insert(std::string x)
	{
		insert(root, x);
	}
	void displayInorder()
	{
		displayInorder(root);
	}
	void displayPreorder()
	{
		displayPreorder(root);
	}
	void displayPostorder()
	{
		displayPostorder(root);
	}
};
int main()
{
	BST t;
	std::string month[12] = { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCB","NOV", "DEC" };
	int x;
	for (int i = 0; i < 12; i++)
		t.insert(month[i]);

	std::cout << "Content of all nodes using Inorder\n";
	t.displayInorder();
	std::cout << std::endl << std::endl;
	std::cout << "Content of all nodes using Postorder\n";
	t.displayPostorder();
	std::cout << std::endl << std::endl;
	std::cout << "Content of all nodes using Preorder\n";
	t.displayPreorder();
	std::cout << std::endl << std::endl;
	system("pause");
}