#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
using namespace std;

class Statistics{
private:
	vector<int> count_array;

public:
	struct Tuple{
		unsigned int index;
		int count;

		Tuple(unsigned int index, int count){
			this->index = index;
			this->count = count;
		}
		Tuple(){}
	};

	void Reset(unsigned int size);
	void Count(unsigned int index);
	unsigned int Size() const;
	unsigned int GetCount(unsigned int index) const;
	unsigned long TotalCount() const;
	Tuple GetMax() const;
	Tuple GetMin() const;
	vector<int> GetVector() const;
	vector<Tuple> GetSortedTupleVector() const;
};

#endif