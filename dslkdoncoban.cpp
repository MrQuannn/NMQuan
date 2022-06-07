#include<bits/stdc++.h>
using namespace std;
class giangvien{
	protected:// private chi dc truy cap trong class, protected duoc truy cap trong class cha va class con, public truy cap moi luc moi noi.
		string ma_so, Ho_ten;
		float gio_nghien_cuu;
		static float tongdt;
	public:
		//ham tao khong co tham so
		giangvien(){
			ma_so=Ho_ten="";
			gio_nghien_cuu=0;
		}
		float returntime(){
			return gio_nghien_cuu;
		}
		//ham tao co tham so;
		giangvien(string ma_so, string Ho_ten){
			this->ma_so=ma_so;
			this->Ho_ten=Ho_ten;
		}
		virtual void nhap(){
			cout<<"Nhap ma so giang vien: "; cin>>ma_so;
			cout<<"Nhap vao ten giang vien: "; fflush(stdin); getline(cin, Ho_ten);
			tongdt++;
		}
		/*static float tongtime(){
			return tonggionc;
		}
		*/
		~giangvien(){
		};
		void xuat(int i){
			cout<<"|"<<setw(5)<<left<<i+1<<"|"<<setw(10)<<left<<ma_so<<"|"<<setw(20)<<left<<Ho_ten<<"|"<<setw(15)<<left<<gio_nghien_cuu<<"|"<<endl;
			dongke();
		}
		friend void swap(giangvien &a, giangvien &b){
			giangvien temp;
			temp.Ho_ten=a.Ho_ten; temp.ma_so=a.ma_so; temp.gio_nghien_cuu=a.gio_nghien_cuu;
			a.Ho_ten=b.Ho_ten; a.ma_so=b.ma_so; a.gio_nghien_cuu=b.gio_nghien_cuu;
			b.Ho_ten=temp.Ho_ten; b.ma_so=temp.ma_so; a.gio_nghien_cuu=temp.gio_nghien_cuu;
		}
		void dongke(){
			for(int i=0; i<75; i++){
				cout<<"-";
			}
			cout<<endl;
		}
		giangvien *next;
};
float giangvien::tongdt=0;
//cau 3;
bool sosanh(giangvien &a,giangvien &b){
	if(a.returntime()>=b.returntime()) return true;
	else return false;
	//return a.returntime()>b.returntime();
}
//cau 4;
class giang_vien_co_huu: public giangvien{
	private:
		float so_bao, gio_bao, hdnghiencuu, hsnghiencuu;
	public:
		void nhap(){
			giangvien::nhap();
			cout<<"Nhap so bai bao: "; cin>>so_bao;
			cout<<"Nhap gio bai bao: "; cin>>gio_bao;
			cout<<"Nhap huong dan nghien cuu: "; cin>>hdnghiencuu;
			cout<<"Nhap he so nghien cuu: "; cin>>hsnghiencuu;
			gio_nghien_cuu=so_bao*gio_bao+hdnghiencuu*hsnghiencuu;
		}
};
class giang_vien_kiem_giang: public giangvien{
	private:
		float so_bao, gio_bao, giokiemgiang;
	public:
		void nhap(){
			giangvien::nhap();
			cout<<"Nhap so bai bao: "; cin>>so_bao;
			cout<<"Nhap so gio bao: "; cin>>gio_bao;
			cout<<"Nhap gio kiem giang: "; cin>>giokiemgiang;
			gio_nghien_cuu=so_bao*gio_bao+giokiemgiang;
		}
};
class quanli{
	public:
		void menu(){
			cout<<"			BAN MUON CHON "<<endl;
			cout<<" 1. them giang vien co huu"<<endl;
			cout<<" 2. them giang vien kiem giang"<<endl;
			cout<<" 0. thoat"<<endl;
		}
		void dongke(){
			for(int i=0; i<75; i++){
				cout<<"-";
			}
			cout<<endl;
		}
		void thuchien(){
        giangvien *dau=NULL, *cuoi;
        char ok='c';
        giangvien *a;
        while(ok=='c')
        {
            int chon=1;
            menu();
            cout<<"ban muon chon: "; cin>>chon;
            switch(chon){
            case 1:
                {
                a=new giang_vien_co_huu();
                a->nhap();
                if(dau==NULL)
                    {
                    dau=a;
                    cuoi=a;
                    }
                    else{
                    cuoi->next=a;
                    cuoi=a;
                    }
                    break;
                    }
            case 2:{
                a=new giang_vien_kiem_giang();
                a->nhap();
                if(dau==NULL){
                dau=a;
                cuoi=a;
                }
                else{
                cuoi->next=a;
                cuoi=a;
                }
                break;
                }
                }
                cout<<"Ban co muon nhao them khong (co the c ma khong thi k): "; cin>>ok;
        }
	cout<<" da chay doan nay "<<endl;
	//sapxep
	giangvien *i, *j;
	i=dau;
	while(i!=NULL){
		j=i->next;
		while(j!=NULL){
			if(sosanh(*i, *j)==false) swap(*i, *j);
			j=j->next;
		}
		i=i->next;
	}
	cout<<"		DA SAP XEP"<<endl;
	int t=1;
	giangvien *duyet;
	duyet=dau;

	dongke();
	cout<<"|"<<setw(5)<<left<<"STT"<<"|"<<setw(10)<<left<<"Ma so"<<"|"<<setw(20)<<left<<"Ho ten"<<"|"<<setw(15)<<left<<"Gio N.cuu"<<"|"<<endl;
	dongke();
	while(duyet!=NULL){
		duyet->xuat(t);
		duyet=duyet->next;
	}
	}
};
int main(){
	quanli *a=new quanli();
	a->thuchien();
}
