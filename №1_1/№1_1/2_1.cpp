//# include <iostream>
//#include <stack>
//
//
//
//template <typename T>
//class DefaultComparator
//{
//public:
//	bool operator()(const T& l, const T& r)
//	{
//		return l < r;
//	}
//};
//
//class treeNode
//{
//public:
//	~treeNode()
//	{
//	}
//	treeNode()
//	{
//
//	}
//	treeNode(treeNode* par, int val)
//	{
//		parent = par;
//		value = val;
//		left = right = NULL;
//	}
//	treeNode(int value)
//	{
//		parent = NULL;
//		left = right = NULL;
//		this->value = value;
//	}
//	int value;
//	treeNode* parent;
//	treeNode* left;
//	treeNode* right;
//};
//
//void Visit(treeNode* node)
//{
//	std::cout << node->value << " ";
//}
//void Void(treeNode* node)
//{
//
//}
//
//
//template<typename Comparator = std::less<int>>
//class Tree {
//public:
//	~Tree()
//	{
//		std::stack<treeNode*> allElem = inOrder(Void);
//		treeNode* node;
//		while (!allElem.empty()) {
//			node = allElem.top();
//			node->parent = NULL;
//			node->left = NULL;
//			node->right = NULL;
//			allElem.pop();
//			delete node;
//		}
//	}
//	Tree():root(NULL)
//	{
//
//	}
//	Tree(int val)
//	{
//		root = new treeNode();
//		root->left = NULL;
//		root->right = NULL;
//		root->parent = NULL;
//		root->value = val;
//	}
//	void Insert(int val)
//	{
//		treeNode* par = NULL;
//		add2(val, Comparator());
//	}
//	friend void Visit(treeNode* node);
//	friend void Void(treeNode* node);
//
//
//	std::stack<treeNode*> inOrder(void (*Visit)(treeNode*)){
//		std::stack<treeNode*> allOrder;
//		treeNode* node = root;
//		std::stack<treeNode*> order;
//		while (node || (!order.empty()))
//		{
//			if (!order.empty())
//			{
//				node = order.top();
//				order.pop();
//				Visit(node);
//				node->right ? node = node->right : node = NULL;
//			}
//			while (node)
//			{
//				allOrder.push(node);
//				order.push(node);
//				node = node->left;
//			}
//		}
//		return allOrder;
//	}
//	int Min()
//	{
//		treeNode* node = root;
//		while (node->left)
//		{
//			node = node->left;
//		}
//		return node->value;
//	}
//private:
//	treeNode* root;
//	void add2(int val, Comparator cmp = Comparator()) {// Comp
//		treeNode* node = root;
//		treeNode* parentNode = NULL;
//		if (!node)
//		{
//			root = new treeNode(NULL,val);
//			return;
//		}
//		bool a = false;
//		while (node)
//		{
//			if (cmp(val, node -> value))
//			{
//				parentNode = node;
//				a = true;
//				node = node->left;
//			}
//			else
//			{
//				parentNode = node;
//				a = false;
//				node = node->right;
//			}
//		}
//		a ? parentNode->left = new treeNode(parentNode, val) : parentNode->right = new treeNode(parentNode, val);
//	}
//
//	void add(treeNode*& node, treeNode*& parentNode, int val) {
//		if (!node)
//		{
//			node = new treeNode(parentNode, val);
//			return;
//		}
//		if (val < node->value)
//		{
//			add(node->left, node, val);
//		}
//		else
//		{
//			add(node->right, node, val);
//		}
//
//	}
//	treeNode* min()
//	{
//		treeNode* node = root;
//		while (node->left)
//		{
//			node = node->left;
//		}
//		return node;
//	}
//};
//
//int main()
//{
//	int size;
//	int* buf;
//	std::cin >> size;
//	buf = new int[size];
//	for (int i = 0; i < size; ++i)
//	{
//		std::cin >> buf[i];
//	}
//	Tree<DefaultComparator<int>> tree;
//	for (int i = 0; i < size; ++i)
//	{
//		tree.Insert(buf[i]);
//	}
//	tree.inOrder(Visit);
//	delete[]buf;
//	system("pause");
//	return 0;
//}