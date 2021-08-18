class MyArray {
private:
	int* ary;
	int size;
public:
	MyArray();
	MyArray(int s);
	MyArray(const MyArray& br);
	~MyArray();
	MyArray& operator=(const MyArray& br);
	bool put(int index, int val);
	bool get(int index, int& getdata);

	int getSize();
	int* getAry(void);
};
