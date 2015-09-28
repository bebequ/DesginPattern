#ifndef CHAIN_OF_RESPONSIBILITY

/**
 * @file chain_of_resposibility
 * @brief 
 * @details 1. Put a "next" pointer in the base class
 *          2. The "chain" method in the base class always delegates to the next object
 *          3. If the the derived classes cannot handle, they delegate to the base class
 * @author Jin (jin.park@raon-tech.com)
 * @date 2015-09-28
 */

#include <iostream>

class Base
{
private:
	Base* next;

public:
	Base() 
	{
		next = 0;
	}

	void setNext(Base* n)
	{
		next = n;
	}

	void add(Base* n)
	{
		if(next)
			next->add(n);
		else
			next = n;
	}

	virtual void handle(int i)
	{
		next->handle(i);
	}
};

class Handler1 : public Base
{
public:
	void handle(int i) 
	{
		if (rand()%3)
		{
			std::cout<< "H1 passed " << i << " ";
			Base::handle(i);
		}
		else
		{
			std::cout<< "H1 handled " << i << " ";
		}	
	}
};

class Handler2 : public Base
{
public:
	void handle(int i)
	{
		if(rand() %3)
		{
			std::cout << "H2 passesed " << i << " ";
			Base::handle(i);
		} 
		else 
		{
			std::cout << "H2 handled " << i << " ";
		}
	}
};

class Handler3 : public Base
{
public:
	void handle(int i)
	{
		if(rand() %3)
		{
			std::cout << "H3 passesed " << i << " ";
			Base::handle(i);
		}
		else
		{
			std::cout<< "H3 handled " << i << " ";
		}
	}
};

int main(int argc, char* argv[])
{
	srand(time(0));
	Handler1 root;
	Handler2 two;
	Handler3 thr;
	root.add(&two);
	root.add(&thr);
	thr.setNext(&root);
	for (int i = 1; i < 10; i++)
	{
		root.handle(i);
		std::cout<< '\n';
	}

	std::cin.get();
	return 0;
}

#endif
