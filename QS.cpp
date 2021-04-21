#include "QS.h"

using namespace std;

void QS::switchValues(int left, int right){
	int temp = myarray[right];
	myarray[right] = myarray[left];
	myarray[left] = temp;
}

void QS::sortAll(){
	if(size<1) return;
	cout << "in sortAll" << endl;
	int first = 0;
	int last = size -1;
	recurSort(first,last);
}

void QS::recurSort(int left, int right){
	if (right-left<1) return;
	int middle = medianOfThree(left,right);
	int newpivot = partition(left,right,middle);
	recurSort(left,newpivot-1);
	recurSort(newpivot+1,right);
}

int QS::medianOfThree(int left, int right){
	cout << "in medianOfThree" << endl;
	if((left < 0) || (size < 1) || (right>size-1)||(left == right)||(left>right))return -1;
	int median = ((left + right)/2);
	while(!(myarray[left]<=myarray[median] && myarray[median]<=myarray[right])){
		if(myarray[left]>myarray[median]) switchValues(left,median);
		if(myarray[median]>myarray[right]) switchValues(median,right);
	}
	return median;
}

int QS::partition(int left, int right, int pivotIndex){
	cout << "in partition" << endl;
	if(left<0||left>size-1|| right<0|| right>size-1 || pivotIndex>right || pivotIndex<left || left>=right) return -1;
	switchValues(left,pivotIndex);
	int up = left+1;
	int down = right;
	do{
		while((myarray[up]<=myarray[left])&&(up!=right)) {
			cout << up++ << endl;}
		while((myarray[down]>myarray[left])&&(down>left)) {
			cout << down-- << endl;}
		if(up<down) switchValues(up,down);
	}
	while(up<down);
	switchValues(left,down);
	return down;
}

string QS::getArray(){
	cout << "in getArray" << endl;
	string out ="";
	if (myarray != NULL){
		for (int x=0; x<size; x++){
			int value = myarray[x];
			out+= to_string(value);
			if (x<size-1) out+=",";
		}
	}
	return out;
}

int QS::getSize(){
	cout << "in getSize" << endl;
	return size;
}

bool QS::addToArray(int value){
	cout << "In addToArray" << endl;
	if (index > arraycap - 1) return false;
	myarray[index]=value;
	index++;
	size++;
	return true;
}

bool QS::createArray(int capacity){
	cout << "in Array" << endl;
	if (arraycap != 0) clear();
	if (capacity>0){
		myarray = new int[capacity];
		arraycap = capacity;
		return true;}
	else {return false;}

}

void QS::clear(){
	cout << "in the clear" << endl;
	delete [] myarray;
	size = 0;
	index = 0;
	arraycap = 0;
}