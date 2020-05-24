/* ProyectoFinalHLD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
* Miguel Angel Muñoz Vazquez
* Aaron Perez Ontiveros
*/


#include <iostream>
#include "SegmentTree.h"
using namespace std;
int main()
{
	const vector<int> values = { 5,-2,10,1 };
	SegmentTree s(values);
	cout << s.GetMinimum(0, values.size()-1) << '\n';
	s.UpdatePos(0,100);
	cout << s.GetMinimum(0, values.size()-1) << '\n';
	s.UpdatePos(0, -100);
	cout << s.GetMinimum(0, values.size() - 1) << '\n';


}
