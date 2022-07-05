//Создайте класс IntSet(множество целых) с операциями + , +=, -, -=, =, == , != , > , < , >= , <= , *, +(int)(добавить в множество),
//-(int)(исключения из множества).
#include"Header.h"



int main() {
	IntSet a;
	a.operator+(100);
	a + 10;
	a.operator+(100);
	a.operator+(100);
	a.Show();
	a.operator-(10);
	printf("\n");
	//a.Show();
	printf("\n");
	a = a + a;
	a.Show();
	printf("\n");
	IntSet b;
	b.operator+(30);
	b + 35;
	//b.Show();
	printf("\n");
	a = b;
	if (a >= b) {
		printf("eee\n");
	}
	else {
		printf("iii\n");
	}
	IntSet c;
	b + 35;
	printf("\n");
	//a.Show();
	printf("\n");
	c = b*a;
	c.Show();
	printf("\n");
	c >> 1;
	//c + 100;
	//c + 100;
	a + 100;
	c.Show();
	printf("\n");
	a.Show();
	IntSet fi;
	fi.intrsect(a, c);
	fi.Show();
	IntSet fin;
	fin.nointrsect(a, c);
	fin.Show();
	IntSet Sum;
	Sum.U(a, c);
	Sum.Show();





	return 0;
}
