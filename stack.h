#ifndef _STACK_
#define _STACK

#include <iostream>
#include <vector>

using namespace std;


class _element {
private:
	string m_type; // state, terminal, nonterminal
	string m_value;// value
public:
	_element(string type, string value) {
		this->m_type = type;
		this->m_value = value;
	}

	string value() {
		return m_value;
	}
	string type() {
		return m_type;
	}
};




class _stack {
private:
	vector<_element*> vec;
	string temp;
public:

	void push(_element* el) {
		vec.push_back(el);

	}

	_element* top() {
		return vec.back();
	}

	void pop() {
		_element* temp = vec.back();
		vec.pop_back();
		delete temp;
	}

	string* print() {
		temp = "";
		vector<_element*>::iterator iter = vec.begin();
		while (iter != vec.end()) {
			temp += (*iter)->value();
			iter++;
		}
		return &temp;
	}

};

#endif