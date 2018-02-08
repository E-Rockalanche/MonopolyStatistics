#include "Statistics.h"

void Statistics::Reset(unsigned int size){
	count_array.resize(size, 0);
	for(unsigned int i = 0; i < count_array.size(); i++){
		count_array[i] = 0;
	}
}

unsigned int Statistics::Size() const{
	return count_array.size();
}

void Statistics::Count(unsigned int index){
	count_array[index]++;
}

unsigned int Statistics::GetCount(unsigned int index) const{
	return count_array[index];
}

unsigned long Statistics::TotalCount() const{
	unsigned int total = 0;
	for(unsigned int i = 0; i < count_array.size(); i++){
		total += GetCount(i);
	}
	return total;
}

Statistics::Tuple Statistics::GetMax() const{
	Tuple max(0, count_array[0]);
	for(unsigned int i = 1; i < count_array.size(); i++){
		if (count_array[i] > max.count){
			max = Tuple(i, count_array[i]);
		}
	}
	return max;
}

Statistics::Tuple Statistics::GetMin() const{
	Tuple min(0, count_array[0]);
	for(unsigned int i = 1; i < count_array.size(); i++){
		if (count_array[i] < min.count){
			min = Tuple(i, count_array[i]);
		}
	}
	return min;
}

vector<int> Statistics::GetVector() const{
	return count_array;
}

vector<Statistics::Tuple> Statistics::GetSortedTupleVector() const{
	vector<Tuple> sorted_array;
	for(unsigned int i = 0; i < count_array.size(); i++){
		sorted_array.push_back(Tuple(i, count_array[i]));
	}
	Tuple cur_tuple, next_tuple;
	for(unsigned int it = 0; it < sorted_array.size() - 1; it++){
		for(unsigned int cur = 0; cur < sorted_array.size() - 1; cur++){
			cur_tuple = sorted_array[cur];
			next_tuple = sorted_array[cur+1];
			if (next_tuple.count > cur_tuple.count){
				//swap
				sorted_array[cur] = next_tuple;
				sorted_array[cur+1] = cur_tuple;
			}
		}
	}
	return sorted_array;
}