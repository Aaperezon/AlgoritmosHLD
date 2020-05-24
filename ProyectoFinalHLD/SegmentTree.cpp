#include "SegmentTree.h"
#include <iostream>


SegmentTree::SegmentTree(const vector<int>& values) {
    this->values = values;
    vector<Node> SEGtemp(values.size()*4);
    this->SEG = SEGtemp;
    SegmentTree::Build(0, 0, (values.size()-1));
}

int SegmentTree::Build(int dir, int l, int r) {
    SEG[dir].l = l;
    SEG[dir].r = r;

    if (l == r) {
        SEG[dir].minimum = values[l];
        return SEG[dir].minimum;
    }
    int mid = (l + r) / 2;
    SegmentTree::Build(dir * 2 + 1, l, mid);
    SegmentTree::Build(dir * 2 + 2, mid + 1, r);
    SEG[dir].minimum = min(SEG[dir * 2 + 1].minimum, SEG[dir * 2 + 2].minimum);

}

int SegmentTree::GetMinimum(int dir, int l, int r) {
    //getMinimum(3,5) [dir].l -> 6
    //              [dir].r -> 8 
    //SEG[dir].l -> 1
    //SEG[dir].r -> 2 
    //getMinimum(0, 3);
    if (SEG[dir].l > r || SEG[dir].r < l)
        return INT_MAX;
    if (l <= SEG[dir].l && SEG[dir].r <= r)
        return SEG[dir].minimum;
    return min(
        SegmentTree::GetMinimum(dir * 2 + 1, l, r),
        SegmentTree::GetMinimum(dir * 2 + 2, l, r)
    );
}
int SegmentTree::GetMinimum(int l, int r) {
    return SegmentTree::GetMinimum(0, l, r);
}

void SegmentTree::UpdatePos(int dir, int pos, int newValue) {
    if (SEG[dir].l == SEG[dir].r) {
        SEG[dir].minimum = values[pos] = newValue;
        return;
    }
    if (pos <= SEG[dir * 2 + 1].r)
        SegmentTree::UpdatePos(dir * 2 + 1, pos, newValue);
    else
        SegmentTree::UpdatePos(dir * 2 + 2, pos, newValue);
    SEG[dir].minimum = min(SEG[dir * 2 + 1].minimum, SEG[dir * 2 + 2].minimum);
}

void SegmentTree::UpdatePos(int pos, int newValue) {
    return SegmentTree::UpdatePos(0, pos, newValue);
}


