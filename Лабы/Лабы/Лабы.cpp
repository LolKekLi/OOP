#include <locale.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template <class T1>
class Text {
	string text;
	Text* prev;
	Text* next;
public:
	Text(Text* pr = NULL, Text* nxt = NULL) : text("") { this->prev = pr; this->next = nxt; }
	void set(string txt, Text* pr, Text* nxt) { this->text = txt; this->prev = pr; this->next = nxt; }
	void setString(string txt) { this->text = txt; }
	void setNext(Text* prev = NULL) {
		if (next != NULL) {
			next->prev = prev;
		}
	}
	void setPrev(Text* nxt = NULL) {
		if (prev != NULL) {
			prev->next = nxt;
		}
	}
	void chNext(Text* nxt = NULL) {
		next = nxt;
	}
	void chPrev(Text* pr = NULL) {
		prev = pr;
	}
	T1 get() { return text; }
	Text* getPrev() {
		return prev;
	}
	Text* getNext() {
		return next;
	}
};
template <class T2>
class Memory {
	T2* stack;
public:
	Memory() {
		stack = new T2;
	}
	Memory(const Memory& obj) : stack(new T2(*(obj.stack))) {}
	~Memory() {
		delete stack;
	}
	void show();
	int write(string);
	void commit();
	void ctrlZ();
	void ctrlY();
	T2* operator->();
};
template <class T2>
T2* Memory<T2>::operator->()
{
	return stack;
}
template <class T2>
void Memory<T2>::show() {
	cout << "состояния объекта ";
	T2* first = stack;
	while (first->getPrev() != NULL) {
		first = first->getPrev();
	}
	while (first != stack) {
		cout << first->get();
		first = first->getNext();
	}
	cout << stack->get() << endl;
}
template <class T2>
int Memory<T2>::write(string text) {
	T2* prev = stack;
	if (stack->getNext() != NULL) {
		stack->setNext(NULL);
		delete stack->getNext();
	}
	stack = new T2;
	prev->chNext(stack);
	stack->set(text, prev, NULL);
	return 1;
}
template <class T2>
void Memory<T2>::commit() {
	T2* first = stack;
	string st;
	while (first->getPrev() != NULL) {
		first = first->getPrev();
	}
	while (first != stack) {
		st.append(first->get());
		first = first->getNext();
	}
	st.append(stack->get());
	stack->setString(st);
	ofstream f;
	f.open("res.txt");
	f << st;
	f.close();
	if (stack->getPrev() != NULL) {
		delete stack->getPrev();
		stack->chPrev();
	}
	if (stack->getNext() != NULL) {
		delete stack->getNext();
		stack->chNext();
	}
}

template <class T2>
void Memory<T2>::ctrlZ() {
	if (stack->getPrev() != NULL) {
		cout << "ДЕЙСТВИЕ БЫЛО ОТМЕНЕНО" << endl;
		stack = stack->getPrev();
	}
}
template <class T2>
void Memory<T2>::ctrlY() {
	if (stack->getNext() != NULL) {
		stack = stack->getNext();
		cout << "ДЕЙСТВИЕ БЫЛО ВОЗВРАЩЕНО" << endl;
	}
}
int main() {
	Memory<Text<string>> firstText;
	setlocale(LC_ALL, "Russian");
	string txt;
	cout << "Введите строку" << endl;
	getline(cin, txt);
	firstText->set(txt, NULL, NULL);
	firstText.show();
	int kod = 0;
	while (kod != 5) {
		cout << "0 - show, 1 - write, 2 - ctrZ, 3 - ctrlY, 4 - save, 5 - exit" << endl;
		cin >> kod;
		switch (kod)
		{
		case 0:
			firstText.show();
			break;
		case 1:
			cout << "Введите строку" << endl;
			cin.ignore();
			getline(cin, txt);
			if (firstText.write(txt))
			{
				firstText.show();
			}
			cout << endl;
			break;
		case 2:
			firstText.ctrlZ();
			break;
		case 3:
			firstText.ctrlY();
			break;
		case 4:
			firstText.commit();
			break;
		default:
			firstText.commit();
			break;
		}
	}
	return 0;
}