
#include<iostream>
#include<cstring>
#include<exception>

#define TYPE template<typename T>

TYPE class MyQueue
{
	enum { def_capacity=100 };
	private:
		T* t;
		int front,rear,count,capacity,size1;
	public:
		MyQueue(int cap=def_capacity);
		void push(const T& value);
		void pop();
		void display();
		int size() const;
		bool isEmpty() const; 
		const T& getfront();
		const T& getrear();
};

class QueueException
{
	private:
		std::string errmsg;
	public:
		QueueException(const std::string & err): errmsg(err){}
		std::string getError() { return(errmsg); }
};

class QueueOverflow : public QueueException
{
	public:
		QueueOverflow(const std::string & err): QueueException(err) {}
};

class QueueUnderflow : public QueueException
{
	public:
		QueueUnderflow(const std::string & err): QueueException(err) {}
};

TYPE MyQueue<T>::MyQueue(int cap) : t(new T[cap]),capacity(cap),front(-1),rear(-1),count(0),size1(0) {}

TYPE void MyQueue<T>::push(const T& value)
{
	if(size()==capacity)  throw QueueOverflow("Overflow!!");
	if(front==-1)   front=0;
	t[++rear]=value;
	size1++;
}

TYPE void MyQueue<T>::pop()
{
	if(isEmpty())	throw QueueUnderflow("Underflow!!");
	front++;
	++count;
	--size1;
}

TYPE int MyQueue<T>::size() const
{
	return(rear+1-count);
}

TYPE bool MyQueue<T>::isEmpty() const { return(size1==0); }

TYPE void MyQueue<T>::display()
{
	int temp=front;
	std::cout<<std::endl;
	std::cout<<"Data in Queue :>" ;
	for(int i=front;i<rear+1;i++)
	{
		std::cout<<" "<<t[i];
	}
	std::cout<<std::endl;
}

TYPE 
const T& MyQueue<T>::getfront()
{
	if(isEmpty())    throw QueueUnderflow("Underflow!!");
	return(t[front]);
}

TYPE const T& MyQueue<T>::getrear()
{
	return(t[rear]);
}



