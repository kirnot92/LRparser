#ifndef _GRAMMAR_
#define _GRAMMAR_

#include <iostream>
#include <vector>

using namespace std;

/*

1. E->E+T
2. E->T
3. T->T*F
4. T->F
5. F->(E)
6. F->id

*/


class _grammar {
private:
	string m_LHS;
	string m_RHS;
public:
	_grammar(string LHS, string RHS) {
		m_LHS = LHS;
		m_RHS = RHS;
	}
	string get_LHS() {
		return m_LHS;
	}
	string get_RHS() {
		return m_RHS;
	}
};

vector<_grammar> grammar = {
	_grammar("none","none"),
	_grammar("E","E+T"),
	_grammar("E","T"),
	_grammar("T","T*F"),
	_grammar("T","F"),
	_grammar("F","(E)"),
	_grammar("F","a")
};
#endif