#include <iostream>
#include <vector>
using namespace std;

// for max heap

// array based
void InsertA(int a[], int index_last_added_ele){
	int i = index_last_added_ele;
	int temp = a[index_last_added_ele];
	while(i > 0){
		int parent_index;
		int parent;
		if(i%2 == 0){
			parent_index = i/2-1;
			parent = a[parent_index];
		}
		else{
			parent_index = i/2;
			parent = a[parent_index];
		}
		if(parent < temp){
			a[parent_index] = temp;
			a[i] = parent;

		}
		i = parent_index;
	}
}

// STL vector based
void InsertV(vector<int>& v, int key){
	v.push_back(key);
	int i = v.size()-1;
	int temp = v[i];
	while(i > 0){
		int parent_index;
		int parent;
		if(i%2 == 0){
			parent_index = i/2-1;
			parent = v[parent_index];
		}
		else{
			parent_index = i/2;
			parent = v[parent_index];
		}
		if(parent < temp){
			v[parent_index] = temp;
			v[i] = parent;

		}
		i = parent_index;
	}
}

void createHeapA(int a[], int n){
	int i = 0;
	while(i < n){
		InsertA(a, i);
		i++;

	}
}

void createHeapV(vector<int>& v, int a[], int n){
	int i = 0;
	while(i < n){
		InsertV(v, a[i]);
		i++;
	}
}

int extractMax(int a[], int n){
	int last_el = a[n-1];
	int max = a[0];
	a[0] = a[n-1];
	int i = 0;
	int j = 2*i + 1;
	while(j < n-1){
		if(a[j] < a[j+1]){
			j = j+1;
		}
		if(a[i] < a[j]){
			a[i] = a[j];
			a[j] = last_el;
			i = j;
			j = 2*i + 1;
		}
		else{
			break;
		}

	}

	return max;
}

void heapSort(int a[], int n){  // n no of elements
	createHeapA(a, n);
	for(int i = n; i >0; i--){
		int max = extractMax(a, i);
		a[i-1] = max;
	}
}

/* Sir's method 
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}
*/

void heapify(int a[], int n){
	int i = n-1;
	while(i >=0){
		int temp;
		int lchild_index = 2*i + 1;
		int rchild_index = lchild_index + 1;
		if(lchild_index < n && a[lchild_index] > a[i]){
			int el = a[i];
			temp = a[lchild_index];
			a[i] = temp;
			a[lchild_index] = el;

		}

		if(rchild_index < n && a[rchild_index] > a[i]){
			int el = a[i];
			temp = a[rchild_index];
			a[i] = temp;
			a[rchild_index] = el;
		}
		i--;
	}
}
template <class T>
void Print(T& vec, int n){
    cout << "Max Heap: [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main()
{
	// int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    // InsertA(a, 9);
    // Print(a, sizeof(a)/sizeof(a[0]));
    // cout << endl;

    // // STL based
    // vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    // Print(v, v.size());
    // v.reserve(15);  // Reserve space for 15 elements
 
    // InsertV(v, 50);
    // Print(v, v.size());
 
 	//  int b[] = {10, 20, 30, 25, 5, 40, 35};
    // Print(b, sizeof(b)/sizeof(b[0]));
 
 	// createHeapA(b, sizeof(b)/sizeof(b[0]));
 	//  cout << "Create Heap using Array" << endl;
 	// Print(b, sizeof(b)/sizeof(b[0]));
    // cout << endl;

    // vector<int> vb;
    // createHeapV(vb, b, sizeof(b)/sizeof(b[0]));
    // Print(vb, vb.size());

    int H[]={10,20,30,25,5,40,35};
    heapify(H, 7);

    Print(H, 7);

    return 0;
}