#include"Header.h"


IntSet::IntSet() {
	this->set = (int*)malloc(sizeof(int)+4);
	//std::cout << "Constructor" << this << std::endl;
}

IntSet::IntSet(const IntSet& b) {
	//std::cout << "Constructor copy" << this << std::endl;
	this->count = b.count;
	this->set = (int*)malloc(sizeof(int)*b.count+4);
	for (int i = 0; i < b.count; i++) {
		this->set[i] = b.set[i];
	}
}

IntSet::~IntSet() {
	free(set);
	//std::cout << "delete" << this << std::endl;
}

IntSet IntSet::operator+(int k) {
	//std::cout << "Constructor operator" << this << std::endl;
	set = (int*)realloc(set, sizeof(int) * count + 4);
	set[count] = k;
	count++;
	return *this;
}


void IntSet::Show() {
	for (int i = 0; i < count; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}

IntSet IntSet::operator-(int d) {
	//std::cout << "Constructor operator -- " << this << std::endl;
	int cnt = 0;
	for (int u = 0; u < count; u++) {
		if (set[u] == d) {
			cnt++;
		}
	}
	if (cnt == 0) {
		std::cout << "Number missing\n";
		return *this;
	}
	else {
		int* sete = (int*)malloc(sizeof(int) * (count)+4);
		int r = 0;
		for (int i = 0; i < count; i++) {
			if (set[i] == d) {
				continue;
			}
			else {
				sete[r] = set[i];
				r++;
			}
		}
		for (int y = 0; y < count - cnt; y++) {
			set[y] = sete[y];
		}
		count -= cnt;

		return *this;
	}


	/*int *sete = (int*)malloc(sizeof(int)*(count-d) + 4);
	for (int i = 0; i < count; i++) {
		
		sete[i] = set[i];
	}
	count -= d;
	return *this;*/
}

IntSet &IntSet::operator=(const IntSet& b) {
	this->count = b.count;
	if (this->set != nullptr) {
		free(set);
	}
	this->set = (int*)malloc(sizeof(int) * b.count + 4);
	for (int i = 0; i < b.count; i++) {
		this->set[i] = b.set[i];
	}
	return *this;
}

IntSet IntSet::operator+(const IntSet& b) {
	IntSet c;
	 
	 if (b.count > this->count) {
		 c.set = (int*)realloc(c.set, sizeof(int) * b.count + 4);
		 for (int i = 0; i < b.count; i++) {
			 c.set[i] = b.set[i];
		 }
		 for (int i = 0; i < this->count; i++) {
			 c.set[i] = b.set[i] + this->set[i];
		 }
		 c.count = b.count;
	 }
	 else {
		 c.set = (int*)realloc(c.set, sizeof(int) * this->count + 4);
		 for (int i = 0; i < this->count; i++) {
			 c.set[i] = this->set[i];
		 }
		 for (int i = 0; i < b.count; i++) {
			 c.set[i] = b.set[i] + this->set[i];
		 }
		 c.count = this->count;
	 }
	 return c;
	
		



}

IntSet IntSet::operator+=(const IntSet& b) { // b = b+a
	if (b.count > this->count) {
		this->set = (int*)realloc(this->set, sizeof(int) * b.count + 4);
		for (int i = this->count; i < b.count; i++) {
			this->set[i] = 0;
		}
		for (int i = 0; i < b.count; i++) {
			this->set[i] = this->set[i] + b.set[i];
		}
		this->count = b.count;
	}
	else {
		for (int i = 0; i < b.count; i++) {
			this->set[i] = this->set[i] + b.set[i];
		}
	}
	return *this;
}

IntSet IntSet::operator-=(const IntSet& b) {
	if (b.count > this->count) {
		this->set = (int*)realloc(this->set, sizeof(int) * b.count + 4);
		for (int i = this->count; i < b.count; i++) {
			this->set[i] = 0;
		}
		for (int i = 0; i < b.count; i++) {
			this->set[i] = this->set[i] - b.set[i];
		}
		this->count = b.count;
	}
	else {
		for (int i = 0; i < b.count; i++) {
			this->set[i] = this->set[i] - b.set[i];
		}
	}
	return *this;
}

IntSet IntSet::operator-(const IntSet& b) {
	IntSet c;

	if (b.count > this->count) {
		c.set = (int*)realloc(c.set, sizeof(int) * b.count + 4);
		for (int i = this->count; i < b.count; i++) {
			this->set[i] = 0;
		}
		for (int i = 0; i < b.count; i++) {
			c.set[i] = this->set[i] - b.set[i];
		}
		c.count = b.count;
	}
	else {
		c.set = (int*)realloc(c.set, sizeof(int) * this->count + 4);
		for (int i = 0; i < this->count; i++) {
			c.set[i] = this->set[i];
		}
		for (int i = 0; i < b.count; i++) {
			c.set[i] = this->set[i] - b.set[i];
		}
		c.count = this->count;
	}
	return c;

}

IntSet IntSet::operator*(const IntSet& b) {
	IntSet c;

	if (b.count > this->count) {
		c.set = (int*)realloc(c.set, sizeof(int) * b.count + 4);
		for (int i = 0; i < b.count; i++) {
			c.set[i] = b.set[i];
		}
		for (int i = 0; i < this->count; i++) {
			c.set[i] = b.set[i] * this->set[i];
		}
		c.count = b.count;
	}
	else {
		c.set = (int*)realloc(c.set, sizeof(int) * this->count + 4);
		for (int i = 0; i < this->count; i++) {
			c.set[i] = this->set[i];
		}
		for (int i = 0; i < b.count; i++) {
			c.set[i] = b.set[i] * this->set[i];
		}
		c.count = this->count;
	}
	return c;
}

bool IntSet::operator==(const IntSet& b) {
	int cnt = 0;
	if (this->count != b.count) {
		return false;
	}
	else {
		for (int i = 0; i < count; i++) {
			if (this->count == b.count) {
				cnt++;
			}
		}
		if (cnt == count) {
			return true;
		}
	}

}

bool IntSet::operator!=(const IntSet& b) {
	int cnt = 0;
	if (this->count != b.count) {
		return true;
	}
	else {
		for (int i = 0; i < count; i++) {
			if (this->count == b.count) {
				cnt++;
			}
		}
		if (cnt != count) {
			return true;
		}
		else {
			return false;
		}
	}

}

bool IntSet::operator>(const IntSet& b) {
	int thissum = 0;
	int bsum = 0;

	if (this->count > b.count) {
		return true;

	}
	else {
		return false;
	}

	/*for (int i = 0; i < this->count; i++) {
		thissum += this->set[i];
	}
	for (int i = 0; i < b.count; i++) {
		bsum += b.set[i];
	}
	if (thissum > bsum) {
		return true;
	}
	else {
		return false;
	}*/

	
}

bool IntSet::operator<(const IntSet& b) {
	int thissum = 0;
	int bsum = 0;

	if (this->count < b.count) {
		return true;

	}
	else {
		return false;
	}
	/*for (int i = 0; i < this->count; i++) {
		thissum += this->set[i];
	}
	for (int i = 0; i < b.count; i++) {
		bsum += b.set[i];
	}
	if (thissum < bsum) {
		return true;
	}
	else {
		return false;
	}*/
}

bool IntSet::operator>=(const IntSet& b) {
	int thissum = 0;
	int bsum = 0;

	if (this->count >= b.count) {
		return true;

	}
	else {
		return false;
	}
	/*for (int i = 0; i < this->count; i++) {
		thissum += this->set[i];
	}
	for (int i = 0; i < b.count; i++) {
		bsum += b.set[i];
	}
	if (thissum >= bsum) {
		return true;
	}
	else {
		return false;
	}*/
}

bool IntSet::operator<=(const IntSet& b) {
	int thissum = 0;
	int bsum = 0;

	if (this->count <= b.count) {
		return true;

	}
	else {
		return false;
	}
	/*for (int i = 0; i < this->count; i++) {
		thissum += this->set[i];
	}
	for (int i = 0; i < b.count; i++) {
		bsum += b.set[i];
	}
	if (thissum <= bsum) {
		return true;
	}
	else {
		return false;
	}*/


}

IntSet IntSet::operator<<(int z) {
	int* sete = (int*)malloc(sizeof(int) * count + 4);
	int r = 0;
	for (int i = z; i < count; i++) {
		sete[r] = set[i];
		r++;
	}
	for (int y = 0; y < z; y++) {
		sete[r] = set[y];
		r++;
	}
	for (int e = 0; e < count; e++) {
		set[e] = sete[e];
	}
	return *this;
}

IntSet IntSet::operator>>(int z) {
	int* sete = (int*)malloc(sizeof(int) * count + 4);
	int r = 0;
	for (int i = 0; i < count-z; i++) {
		sete[z+r] = set[i];
		r++;
	}
	r = 0;
	for (int y = count-z; y < count; y++) {
		sete[r] = set[y];
		r++;
	}
	for (int e = 0; e < count; e++) {
		set[e] = sete[e];
	}
	return *this;
}


/// >> << 3 4 5 6     6 6 7 8 4 5 6 3 7   !
/// исключение из множества !
/// функция объединения множеств  U !
/// пересечение выписываем одинаковые элементы !
/// не пересечение разные эл !



IntSet IntSet::U(const IntSet& z, const IntSet& t) {
	IntSet c;
	c.intrsect(z, t);
	IntSet b;
	b.nointrsect(z, t);
	IntSet sum;
	sum.count = c.count + b.count;
	sum.set = (int*)realloc(sum.set, sizeof(int) * sum.count + 4);
	int cntsum = 0;
	for (int i = 0; i < c.count; i++) {
		sum.set[cntsum] = c.set[i];
		cntsum++;
	}
	for (int i = 0; i < b.count; i++) {
		sum.set[cntsum] = b.set[i];
		cntsum++;
	}
	this->count = sum.count;
	this->set = (int*)realloc(this->set, sizeof(int) * this->count + 4);
	for (int i = 0; i < this->count; i++) {
		this->set[i] = sum.set[i];
	}
	return *this;
}

int compare(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}


IntSet IntSet::intrsect(const IntSet& z,const IntSet& This) {
	
	int* ar = (int*)malloc(sizeof(int) * (This.count+z.count) + 4);
	IntSet c;
	IntSet b;
	if (z.count > This.count) {
		c.count = z.count;
		c.set = (int*)realloc(c.set, sizeof(int) * c.count);
		for (int i = 0; i < c.count; i++) {
			c.set[i] = z.set[i];
		}

		b.count = This.count;
		b.set = (int*)realloc(b.set, sizeof(int) * b.count);
		for (int i = 0; i < b.count; i++) {
			b.set[i] = This.set[i];
		}
	}
	else {
		c.count = This.count;
		b.count = z.count;
		c.set = (int*)realloc(c.set, sizeof(int) * c.count);
		for (int i = 0; i < c.count; i++) {
			c.set[i] = This.set[i];
		}
		b.set = (int*)realloc(b.set, sizeof(int) * b.count);
		for (int i = 0; i < b.count; i++) {
			b.set[i] = z.set[i];
		}
	}
	


	qsort(c.set, c.count, sizeof(int), compare);
	qsort(b.set, b.count, sizeof(int), compare);
	
	int cn = 0;
	for (int i = 0; i < c.count; i++) {
		for (int j = 0; j < b.count; j++) {
			if (c.set[i] == b.set[j] && c.set[i - 1] != c.set[i] && b.set[j - 1] != b.set[j]) {
				ar[i] = c.set[i];
				cn++; 
			}
		}
	}
	


	this->set = (int*)realloc(this->set, sizeof(int) * cn + 4);
	this->count = cn;
	for (int i = 0; i < this->count; i++) {
		this->set[i] = ar[i];
	}
	free(ar);

	return *this;
}

IntSet IntSet::nointrsect(const IntSet& z, const IntSet& This) {
	int* ar = (int*)malloc(sizeof(int) * (This.count + z.count) + 4);
	
	
	IntSet c;
	c.count = This.count;
	c.set = (int*)realloc(c.set, sizeof(int) * c.count);
	for (int i = 0; i < c.count; i++) {
		c.set[i] = This.set[i];
	}
	
	
	IntSet b;
	b.count = z.count;
	b.set = (int*)realloc(b.set, sizeof(int) * b.count);
	for (int i = 0; i < b.count; i++) {
		b.set[i] = z.set[i];
	}
	
	qsort(c.set, c.count, sizeof(int), compare);
	qsort(b.set, b.count, sizeof(int), compare);

	//NotRepeat(c.set, c.count);
	//NotRepeat(b.set, b.count);



	int cn = 0;
	int cnt = 0;
	int iset = 0;
	for (int i = 0; i < c.count; i++) {
		cn = 0;
		for (int j = 0; j < b.count; j++) {
			if (c.set[i] == b.set[j] && c.set[i - 1] != c.set[i] && b.set[j - 1] != b.set[j]) {
				cn++;
			}
		}
		if (cn == 0 && c.set[i - 1] != c.set[i]) {
			ar[iset] = c.set[i]; iset++;
			cnt++;
		}
	}
	for (int i = 0; i < b.count; i++) {
		cn = 0;
		for (int j = 0; j < c.count; j++) {
			if (b.set[i] == c.set[j] && c.set[i - 1] != c.set[i] && b.set[j - 1] != b.set[j]) {
				cn++;
			}
		}
		if (cn == 0 && b.set[i - 1] != b.set[i]) {
			ar[iset] = b.set[i]; iset++;
			cnt++;
		}
	}
	IntSet l;
	l.intrsect(c, b);
	int cnu = 0;
	this->set = (int*)realloc(this->set, sizeof(int) * cnt + 4);
	this->count = cnt;
	for (int i = 0; i < this->count; i++) {
		cnu = 0;
		for (int j = 0; j < l.count; j++) {
			if (ar[i] == l.set[j]) {
				cnu++;
			}
		}
		if (cnu == 0) {
			this->set[i] = ar[i];
		}
		else {
			this->count -= cnu;
		}
	}
	free(ar);

	return *this;
}
