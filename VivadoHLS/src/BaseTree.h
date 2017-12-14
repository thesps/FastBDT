#ifndef __BASETREE_H__
#define __BASETREE_H__

/**
 * A storage class for a decision tree in the project format
 */

#include <vector>

class BaseTree{

public:
	BaseTree(const int features[], const int childrenLeft[], const int childrenRight[],
			 std::vector<double> thresholds, std::vector<double> values){
		_features = features;
		_childrenLeft = childrenLeft;
		_childrenRight = childrenRight;
		_thresholds = thresholds;
		_values = values;
	}

	const int* features(){ return _features; }
	const int* childrenLeft(){ return _childrenLeft; }
	const int* childrenRight(){ return _childrenRight; }
	std::vector<double> thresholds(){ return _thresholds; }
	std::vector<double> values(){ return _values; }

private:
	const int* _features;
	const int* _childrenLeft;
	const int* _childrenRight;
	std::vector<double> _thresholds;
	std::vector<double> _values;
};

#endif
