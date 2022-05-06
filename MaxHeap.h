class MaxHeap {
public:
	MaxHeap();
	void insert(int key);
	int getMax();
	int extractMax();
	~MaxHeap();
private:
	unsigned int size_;
	unsigned int capacity_;

	int* items_;
	void _doubleArray();
	int _parent(int i);
	int _rightChild(int i);
	int _leftChild(int i);
	void _heapifyUp(int i);
	void _swap(int i, int j);
	void _heapifyDown(int i);
	bool _isLeaf(int i);
};