//Precise more
#include<iostream>
#include<exception>
#include<cstring>

#define TYPE template<typename V>

TYPE
class MyStack
{
	enum { DEF_CAPACITY=100 };
	private:
		V* s;
		int t;			//index of the top of the stack
		int capacity;
	public:
		MyStack(int cap=DEF_CAPACITY);
		void push(const V& v);
		void pop();
		const V& top();
		bool isEmpty() const;
		int size() const;

};

class StackException
{
	private:
		std::string errmsg;
	public:
		StackException(const std::string & err)
			:errmsg(err) {}
		std::string getError() { return(errmsg);}

};
class StackEmpty:public StackException
{
	public:
		StackEmpty(const std::string & err):StackException(err) {}
};
class StackFull:public StackException
{
	public:
		StackFull(const std::string & err):StackException(err) {}
};

TYPE MyStack<V>::MyStack(int cap)
 	:s(new V[cap]), capacity(cap), t(-1) {}	

TYPE int MyStack<V>::size() const
{
	return(t+1);
}

TYPE bool MyStack<V>::isEmpty() const
{
	return(t<0);
}

TYPE const V& MyStack<V>::top()
{
	if(isEmpty()) 	throw StackEmpty("Top of empty stack!!");
	return s[t];
}

TYPE void MyStack<V>::push(const V& v)
{
	if(size()==capacity) 	throw StackFull("Push to full stack!!");
	s[++t]=v;
}

TYPE void MyStack<V>::pop()
{
	if(isEmpty()) 	throw StackEmpty("Pop from empty stack!!");
	--t;
}

#undef TYPE


