#include <bits/stdc++.h>
using namespace std;


struct DONTHUC {
	int somu;
	double heso;

	DONTHUC(double _heso = 0, int _somu = 0) {
		heso = _heso;
		somu = _somu;
	}

	DONTHUC& operator = (const DONTHUC& rhs) {
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node {
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr) {
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC {
	Node* head;
	Node* tail;
	DATHUC() {
		this->head = nullptr;
		this->tail = nullptr;
	}
};



int main() {
	DATHUC B;
	int N;

	cin >> N;
	for (int test = 0; test < N; test++) {
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B, heso, somu);
	}


	cout << "Da thuc vua nhap la: "; Xuat(B);
	double x; cin >> x;
	cout << "\nVoi x=" << x << ", gia tri da thuc la: "
		<< setprecision(2) << fixed << TinhDaThuc(B, x);
	return 0;
}
