#pragma once
#include <iostream> 
#include <vector>
#include <algorithm> 
#include <functional>
using namespace std;
class SegmentTree
{
	public:
		SegmentTree(const vector<int> &,const  function<int(int, int)>);
		SegmentTree(const vector<int> &);
		int GetMinimum(int, int);
		void UpdatePos(int,int);
	private:
		int Build(int,int,int);
		int GetMinimum(int,int,int);
		void UpdatePos(int, int, int);
		struct Node {
			int l, r, minimum;
		};
		vector<int> values = vector<int>();
		vector<Node> SEG = vector<Node>();
		function<int(int, int)> aggregationFunction;

		
};

