#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>

using namespace std;

void menu(void);
long long int binpow(long long int, int, int);
long long int binpowt(long long int, int, int);
int evklid(int, int);
int difihelman(void);
int primegen(void);
bool prime(long long);
int gGen(int);
int steps(int, int, int);

int main(){
	srand(time(NULL));
	menu();
}

void menu(){
	int key, a, y, n, b;
	
	while (1){
		system("cls");
		cout << "1.Binpow\n2.Evklid\n3.Diffie-Hellman\n4.ShagKakoy-to\n0.Exit\nkey: ";
		cin >> key;
		switch(key){
			case 1:
				cout << "b = a^x(%n). Input a, y, n\n";	
				cin >> a >> y >> n;
				binpowt(a, y, n);
				break;
			case 2:
				cout << "input a, b" << endl;
				cin >> a >> b;
				evklid(a, b);
				break;
			case 3: 
				difihelman();
				break;
			case 4:
				cout << "a^x = b(%n). Input a, b, n\n";	
				cin >> a >> y >> n;
				steps(a,y ,n);
				break;
			case 0:
				exit(0);
		}
	}
	
}


/*Возведение в степерь для просто выбранного пункта возведения в степень */
long long int binpowt(long long int a, int y, int n){

	long long int res = 1;
	while (y) {
		if (y & 1){
			res *= a;
			res = res % n;
		}
		a *= a;
		a = a%n;
		y >>= 1;
	}
	cout << res << endl;
	system("PAUSE");
	return res;
}
/*возведение в степень для функций */
long long int binpow(long long int a, int y, int n){

	long long int res = 1;
	while (y) {
		if (y & 1){
			res *= a;
			res = res % n;
		}
		a *= a;
		a = a%n;
		y >>= 1;
	}
	return res;
}
/*НОД + х +у */
int evklid(int a, int b){
	int q, temp;
	int U[3], V[3], T[3];
	
	
	U[0] = a; U[1] = 1; U[2] = 0;
	V[0] = b; V[1] = 0; V[2] = 1;
	
	while( V[0] > 0){
		q = U[0] / V[0];
		for (int i = 0; i < 3; ++i){
			T[i] = U[i] - q*V[i];
		}
		
		for (int i = 0; i < 3; ++i){
			U[i] = V[i];
			V[i] = T[i];
		}
	}
	
	printf("NOD=%d, x=%d, y=%d\n", U[0], U[1], U[2]);
	system ("pause");
	return U[0];
}
/*Генерация простого числа */
int primegen(){
	while (1){
		int temp = rand()%50000+50000;
		if(prime(temp))
			return temp;	
	}
}
/*Проверка числа на простоту */
bool prime(long long n){ 
	for(long long i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
/*Генерация случайного g */
int gGen(int p){
	int q = (p-1)/2;
	while (1){
		int g = rand() % (p-1);
		if (binpow(g, q, p) != 1){
			return g;
		}
	}
}

/*Диффи-хелман */
int difihelman(){
	unsigned long long int p, g, xa, xb, y1, y2,z1,z2;
	p = primegen();
	g = gGen(p);
	xa = rand()%10000+10000;
	xb = rand()%10000+10000;
	y1 = binpow(g, xa, p);
	y2 = binpow(g, xb, p);
	z1 = binpow(y2, xa, p);
	z2 = binpow(y1, xb, p);
	//cout << y1 << "  " << y2 << endl;
	//cout << z1 << "  " << z2 << endl;
	if (z1 == z2){
		//cout << "SUCCESS. z1 = " << endl << endl;
		printf("\nSUCCESS. z1 = %lld, z2 = %lld \n", z1, z2);
	}
	system("pause");
	return 0;
}
/*Шаг великана и младенца */
int steps(int a, int b, int n){
	int m = (int) sqrt (n) + 1;
	map <int,int> vals;
	for (int i=n; i>=1; --i){
		vals[binpow (a, i * m, n)] = i;
	}
	
	for (int i=0; i<=m; ++i) {
		int cur = (binpow (a, i, n) * b) % n;
		if (vals.count(cur)) {
			int ans = vals[cur] * m - i;
			if (ans < n){
				printf("Ans(x) = %d\n", ans);
				system("PAUSE");
				return ans;
			}
		}
	}
	return -1;
}

