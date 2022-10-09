#include <iostream>
#include <vector>

using namespace std;

class make_change {
protected:
	int charge;
	int payment;
	int unit;
	int deduct;
public:
	make_change();
	make_change(int c, int p, int u);;
	make_change(const make_change& m);
	virtual void print_make_change()=0;
	virtual ~make_change() {

	}
};


make_change::make_change() : charge(0), payment(0), unit(0), deduct(-1*(charge-payment)) {}
make_change::make_change(int c, int p, int u) : charge(c), payment(p), unit(u),deduct (-1*(charge - payment)) {}
make_change::make_change(const make_change& m) : charge(m.charge), payment(m.payment), unit(m.unit) , deduct(-1 * (m.charge - m.payment)) {}


// -------------------------------make_change()-------------------------------------------------

class Won : public make_change {
protected:
	int divi; // ����: 1, ������: -1, ����+����: 0
	int coin_count=0; 
	vector<int> coin_types = {100, 50, 10}; // 100�� = 100, 50�� = 50, 10��= 10
	int paper_count=0; 
	vector<int> paper_types = {50000, 10000, 5000, 1000}; // 1000�� = 1000, 5000�� = 5000, 10000�� = 10000��, 50000�� = 50000��
public : 
	Won(int c, int p, int u);
	void print_make_change();
	void coin_counts();
	void paper_counts();
	
	
};

 Won::Won(int c, int p, int u) {
	 charge = c; 
	 payment = p;
	 deduct = -1 * (c - p);
	 if(deduct >= 1000) {
		divi = 0;
		if (deduct % 1000 == 0) {
			divi= 1;
		}
	}
	else {
		divi = -1;
	}

	

}

 void Won::coin_counts() {
	 if (divi == 0) {
		 coin_count = deduct % 1000;
	 }
	 else if (divi == -1) {
		 coin_count = deduct;
	 }
	 else {
		 coin_count = 0;
	 }

	
	 
 }

 void Won::paper_counts() {
	 if (divi == 0) {
		 paper_count = deduct - (deduct % 1000);
		 
	 }
	 else if (divi == 1) {
		 paper_count = deduct;
	 }
	 else {
		 paper_count = 0;
	 }
 }

 void Won::print_make_change() {
	 vector<int> c_temp(3), p_temp(4);
	 if (paper_count != 0) {
		 for (int i = 0; i < 4; i++) {
			 p_temp[i] = paper_count / paper_types[i];
			 paper_count -= p_temp[i]*paper_types[i];
			 if(p_temp[i] != 0)
			 cout << paper_types[i] << "��: "<< p_temp[i] << "��" << endl;
		 }
	 }
	 
		 for (int i = 0; i < 3; i++) {
			 c_temp[i] = coin_count / coin_types[i];
			 coin_count -= c_temp[i]*coin_types[i];
			 if(c_temp[i] != 0)
			 cout << coin_types[i] << "��: " << c_temp[i] << "��" << endl;
		 }
	 
 }

// --------------------------------- Won() ----------------------------------------------------

 class Dollar : public make_change {
 protected:
	 int divi; // ����: 1, ������: -1, ����+����: 0
	 int coin_count = 0.0;
	 vector<int> coin_types = { 50, 25, 10, 5, 1 }; // 50��Ʈ = 50, 25��Ʈ = 25, 10��Ʈ = 10, 5��Ʈ = 5, 1��Ʈ = 1
	 int paper_count = 0.0;
	 vector<int> paper_types = { 10000, 5000, 2000, 1000, 500, 100}; // 100�޷� = 1000, 50�޷� = 500, 20�޷� = 200, 10�޷� = 100, 1�޷� = 100
 public:
	 Dollar(int c, int p, int u);
	 void print_make_change();
	 void coin_counts();
	 void paper_counts();
	 

 };

 Dollar::Dollar(int c, int p, int u) {
	 charge = c;
	 payment = p;
	 deduct = -1 * (c - p);
	 if (deduct >= 100) {
		 divi = 0;
		 if (deduct % 100 == 0) {
			 divi = 1;
		 }
	 }
	 else {
		 divi = -1;
	 }



 }

 void Dollar::coin_counts() {
	 if (divi == 0) {
		 coin_count = deduct % 100;
	 }
	 else if (divi == -1) {
		 coin_count = deduct;
	 }
	 else {
		 coin_count = 0;
	 }

	

 }

 void Dollar::paper_counts() {
	 if (divi == 0) {
		 paper_count = deduct - (deduct % 100);

	 }
	 else if (divi == 1) {
		 paper_count = deduct;
	 }
	 else {
		 paper_count = 0;
	 }
 }

 void Dollar::print_make_change() {
	 vector<int>  p_temp(6);
	 vector<int> c_temp(5);
	 if (paper_count != 0) {
		 for (int i = 0; i < 6; i++) {
			 p_temp[i] = paper_count / paper_types[i];
			 if (p_temp[i] > 1) {
				 paper_count -= p_temp[i] * paper_types[i];
			 }
			 else {
				 p_temp[i] = 0;
			 }
			 if (p_temp[i] != 0)
				 cout << paper_types[i]/100 << "�޷�: " << p_temp[i] << "��" << endl;
		 }
	 }

	 for (int i = 0; i < 5; i++) {
		 c_temp[i] = coin_count / coin_types[i];
		 coin_count -= c_temp[i] * coin_types[i];
		 if (c_temp[i] != 0)
			 cout << coin_types[i] << "��Ʈ: " << c_temp[i] << "��" << endl;
	 }
	 

 }
 //-------------------------------------dollar-----------------------------------------

 class Yen : public make_change {
 protected:
	 int divi; // ����: 1, ������: -1, ����+����: 0
	 int coin_count = 0;
	 vector<int> coin_types = { 500, 100, 50, 10, 5, 1}; // 500�� = 500, 100�� = 100, 50�� = 50, 10�� = 10, 5�� = 5, 1�� = 1
	 int paper_count = 0;
	 vector<int> paper_types = {10000, 5000, 1000 }; // 10000�� = 10000, 5000�� = 5000, 1000�� = 1000
 public:
	 Yen(int c, int p, int u);
	 void print_make_change();
	 void coin_counts();
	 void paper_counts();
	

 };

 Yen::Yen(int c, int p, int u) {
	 charge = c;
	 payment = p;
	 deduct = -1 * (c - p);
	 if (deduct >= 1000) {
		 divi = 0;
		 if (deduct % 1000 == 0) {
			 divi = 1;
		 }
	 }
	 else {
		 divi = -1;
	 }



 }

 void Yen::coin_counts() {
	 if (divi == 0) {
		 coin_count = deduct % 1000;
	 }
	 else if (divi == -1) {
		 coin_count = deduct;
	 }
	 else {
		 coin_count = 0;
	 }

	 

 }

 void Yen::paper_counts() {
	 if (divi == 0) {
		 paper_count = deduct - (deduct % 1000);

	 }
	 else if (divi == 1) {
		 paper_count = deduct;
	 }
	 else {
		 paper_count = 0;
	 }
 }

 void Yen::print_make_change() {
	 vector<int>  p_temp(3);
	 vector<int> c_temp(6);
	 if (paper_count != 0) {
		 for (int i = 0; i < 3; i++) {
			 p_temp[i] = paper_count / paper_types[i];
			 paper_count -= p_temp[i] * paper_types[i];
			 
			 if (p_temp[i] != 0)
				 cout << paper_types[i] << "��: " << p_temp[i] << "��" << endl;
		 }
	 }

	 for (int i = 0; i < 6; i++) {
		 c_temp[i] = coin_count / coin_types[i];
		 coin_count -= c_temp[i] * coin_types[i];
		 if (c_temp[i] != 0)
			 cout << coin_types[i] << "��: " << c_temp[i] << "��" << endl;
	 }
	 

 }
 //-------------------------------------Yen-----------------------------------------

int main() {
	int nation;
	string nation_money_type;
	int c=0,p=0;
	double uc=0.0,up=0.0;
	cout << "1-korea, 2-USA, 3-Japan" << endl;
	cout << "���� ������ �����Ͻÿ�: ";
	cin >> nation;
	cout << endl;
	if (nation == 2) {
		cout << "������ ������ �����Ͻÿ�: ";
		cin >> uc;
		cout << endl;
		uc = (int)(uc*100);
		cout << "û���� ������ �����Ͻÿ�: ";
		cin >> up;
		cout << endl;
		up = (int)(up*100);
	}
	else {
		cout << "������ ������ �����Ͻÿ�: ";
		cin >> c;
		cout << endl;
		cout << "û���� ������ �����Ͻÿ�: ";
		cin >> p;
		cout << endl;
	}

	if (c < p || uc < up) {
		cout << "�Ž������� ������ �����ϴ�." << endl;
		if(nation == 1){
			Won won(c, p, nation);
			won.paper_counts();
			won.coin_counts();
			won.print_make_change();
		}
		else if (nation == 2) {
			Dollar dollar(uc, up, nation);
			dollar.paper_counts();
			dollar.coin_counts();
			dollar.print_make_change();

		}
		else if (nation == 3) {
			Yen yen(c, p, nation);
			yen.paper_counts();
			yen.coin_counts();
			yen.print_make_change();
		}
	}
	else if (c == p) {
		cout << "�Ž������� �����ϴ�.";
	}
	else {
		cout << "�ݾ��� �����մϴ�";
	}




}