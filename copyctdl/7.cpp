//LeNhoa
#include<iostream>
using namespace std;

struct node{
	float heso;
	int somu;
	node *next;
};

class dathuc{
	public:
		dathuc();
		node *start;
		node* ktao(float,int);
		void nhap();
		void cong(dathuc);
		float giatri(float);
		void nhan(dathuc);
		dathuc nhan_donthuc(node*);
		void chia();
		void daoham();
		int dem();
		void duyet();
		void chen(float,int);
};

dathuc::dathuc(){
	start = NULL;
}

node* dathuc::ktao(float a, int b){
	node *tmp;
	tmp = new (node);
	tmp->heso = a;
	tmp->somu = b;
	tmp->next = NULL;
	return tmp;
}

int dathuc::dem(){	
	int vt = 0;
	node *s;
	s = start;
	while(s!=NULL){
		s= s->next;
		vt++;
	}
	return vt;
}

void dathuc::chen(float hs, int sm){
	if(start==NULL){
		start = ktao(hs,sm);
	}
	else{
		node *t;
		t = ktao(hs,sm);
		if(start->somu < sm){
			t->next = start;
			start = t;
		}
		else{
			node *s;
			s = start;
			while(s->next!=NULL){
				if(s->next->somu < sm){
					break;
				}
				s = s->next;
			}
			t->next = s->next;
			s->next = t;
		}
	}
}

//void dathuc::nhap(){
//	int ok = 1;
//	while(ok){
//		float a;
//		int b;
//		cout<<"nhap he so: ";
//		cin>>a;
//		cout<<"nhap so mu: ";
//		cin>>b;
//		chen(a,b);
//		cout<<"ban co muon nhap tiep(1_co, 0_khong): ";
//		cin>>ok;
//	}
//}

void dathuc::nhap(){
	int a;
	cout<<"nhap so don thuc cua da thuc: ";
	cin>>a;
	cout<<"nhap lan luot he so va so mu tung don thuc: ";
	for(int i=0; i<a; i++){
		int hs, sm;
		cin>>hs>>sm;
		chen(hs,sm);
	}
}

void dathuc::duyet(){
	if(start==NULL){
		cout<<"ds rong";
	}
	else{
		node *s;
		s = start;
		while(s->next!= NULL){
			cout<< s->heso << "x^" << s->somu <<" + ";
			s = s->next;
		}
		cout<< s->heso << "x^" << s->somu << endl;
	}
}

void dathuc::cong(dathuc a){
	node *t, *s;
	t = a.start;
	s = start;
	while(s!=NULL){
		while(t->somu > s->somu){
			chen(t->heso,t->somu);
			t = t->next;
		}
		if(t->somu == s->somu){
			s->heso = s->heso + t->heso;
			t = t->next;
		}
		s = s->next;
	}
	while(t!=NULL){
		chen(t->heso, t->somu);
		t = t->next;
	}
}

//dathuc dathuc::nhan_donthuc(node *t){
////	if(t == NULL || a.start == NULL)	return a;
//	dathuc a;
//	node *s;
//	s = start;
//	while(s!=NULL){
//		s->heso = s->heso * t->heso;
//		s->somu = s->somu + t->somu;
//		a.chen(s->heso,s->somu);
//		s = s->next;
//	}
//	return a;
//}
//
//void dathuc::nhan(dathuc b){
//	node *x;
//	x = b.start;
//	while(x!=NULL){
//		cong(nhan_donthuc(x));
//		x = x->next;
//	}
//}

main(){
	dathuc P, Q;
	P.nhap();
	P.duyet();
	Q.nhap();
	Q.duyet();
	P.cong(Q);
//	P.nhan(Q);
	P.duyet();
}
