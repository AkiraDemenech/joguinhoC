#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

void color (int cor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (hConsole, cor);
}

void tab (int n) {
	if(n<1) {
		n = 0;
	}
	if(kbhit()) {
		getch();
		fflush(stdin);
	}
	int c;
	for(c=0; c<n; c++) {
		printf("\n    ");
	}
	color(10);
}

float scan () {
	float r;
	color(11);
	scanf("%f",&r);
	return r;
}

void add() {
	tab(1);
	float n, r = 0;
	int c = 1;
	do {
		tab(1);
		color(15);
		printf("parcela n%d = ",c++);
		n = scan();
		if(n!=0) {
			r+=n;
		}
	} while(n!=0);
	tab(1);
	printf("RESULTADO = ");
	color(15);
	printf("%f",r);
	tab(1);
}

void sub() {
	float a, b, c;
	tab(2);
	printf("MINUENDO = ");
	a = scan();
	tab(1);
	printf("SUBTRAENDO = ");
	b = scan();
	c = a - b;
	tab(1);
	printf("DIFERENCA = ");
	color(15);
	printf("%f",c);
	tab(1);
}

void mult() {
	float n, r = 1;
	int c = 1;
	do {
		tab(1);
		color(15);
		printf("fator n%d = ",c++);
		n = scan();
		if(n!=0) {
			r*=n;
		}
	} while(n!=0);
	tab(1);
	printf("RESULTADO = ");
	color(15);
	printf("%f",r);
	tab(1);
}

void divs() {
	float a, b, c;
	tab(2);
	printf("NUMERADOR = ");
	a = scan();
	do {
		tab(1);
		printf("DENOMINADOR = ");
		b = scan();
	} while(b==0);
	c = a/b;
	tab(1);
	printf("QUOCIENTE = ");
	color(15);
	printf("%f",c);
	tab(1);
}

void pot() {
	float b, e, p;
	tab(2);
	printf("BASE = ");
	b = scan();
	tab(1);
	printf("EXPOENTE = ");
	e = scan();
	p = pow(b, e);
	tab(1);
	printf("RESULTADO = ");
	color(15);
	printf("%f",p);
	tab(1);
}

void rad() {
	float r, res;
	int i;
	tab(2);
	printf("RADICANDO = ");
	r = scan();
	do {
		tab(1);
		printf("INDICE = ");
		i = scan();
	} while(i<2);
	if(i%2==0 && r<0) {
		r = -r;
		res = pow(r, 1./i);
		tab(1);
		printf("RADICAL = ");
		color(15);
		printf("%f(i^%f)",res,2.0/i);
	} else {
		res = pow(r, 1./i);
		tab(1);
		printf("RADICAL = ");
		color(15);
		printf("%f",res);
	}
	tab(1);
}

void lg() {
	float x, y, ld, le, l;
	tab(1);
	do {
		tab(1);
		printf("LOGARITMANDO = ");
		x = scan();
	} while(x<=0);
	do {
		tab(1);
		printf("BASE = ");
		y = scan();
	} while(y<=0 || y==1);
	ld = log10(x);
	le = log(x);
	l = log10(x)/log10(y);
	tab(1);
	printf("LOGARITMO NATURAL = ");
	color(15);
	printf("%f",le);
	tab(1);
	printf("LOGARITMO DECIMAL = ");
	color(15);
	printf("%f",ld);
	tab(1);
	printf("LOGARITMO(%f, %f) = ",y,x);
	color(15);
	printf("%f",l);
	tab(1);
}

double fatorial (int n) {
	double f = 1;
	int c;
	for(c=1; c<=n; c++) {
		f*=c;
	}
	return (f);
}

void fact() {
	int f, c;
	tab(2);
	printf("NUMERO = ");
	f = scan();
	double r = fatorial(f);
	tab(1);
	printf("FATORIAL = ");
	color(15);
	printf("%.0f",r);
	tab(1);
}

void comb () {
	int e, g;
	tab(1);
	do {
		tab(1);
		printf("NUMERO DE ELEMENTOS = ");
		e = scan();
	} while(e<3);
	do {
		tab(1);
		printf("NUMERO NO AGRUPAMENTO = ");
		g = scan();
	} while(g>=e || g<2);
	float r = fatorial(e);
	tab(1);
	printf("PERMUTACAO SIMPLES (%d elementos) = ",e);
	color(15);
	printf("%.0f",r);
	r/=(fatorial(e-g));
	tab(1);
	printf("COMBINACAO SIMPLES (%d por grupo, repetidos) = ",g);
	color(15);
	printf("%.0f",r);
	tab(1);
	r /= fatorial(g);
	printf("ARRANJO SIMPLES (%d por grupo, sem repeticao) = ",g);
	color(15);
	printf("%.0f",r);
	tab(1);
}

void trig() {
	float a, r, sen, cs, tg, ct, cosec, sec;
	tab(2);
	printf("ANGULO = ");
	a = scan();
	r = a*3.14159/180;
	sen = sin(r);
	cs = cos(r);
	tg = tan(r);
	ct = 1/tg;
	cosec = 1/sen;
	sec = 1/cs;
	tab(1);
	printf("P/ GRAUS: %f",a);
	tab(1);
	color(15);
	printf("Sen = %f / Cosec = %f",sen,cosec);
	tab(1);
	color(15);
	printf("Cos = %f / Sec = %f",cs,sec);
	tab(1);
	color(15);
	printf("Tan = %f / Cotg = %f",tg,ct);
	tab(1);
	printf("P/ RADIANOS: %f.pi",r/3.141592);
	r = a;
	sen = sin(r);
	cs = cos(r);
	tg = tan(r);
	ct = 1/tg;
	cosec = 1/sen;
	sec = 1/cs;
	tab(1);
	color(15);
	printf("Sen = %f / Cosec = %f",sen,cosec);
	tab(1);
	color(15);
	printf("Cos = %f / Sec = %f",cs,sec);
	tab(1);
	color(15);
	printf("Tan = %f / Cotg = %f",tg,ct);
	tab(1);
}

void tot() {
	int n, c, nup, i, p, h, j;
	tab(1);
	do {
		tab(1);
		printf("NUMERO = ");
		n = scan();
	} while(n<2);
	for(c=2, i=0, nup=n; c<=n; c++) {
		if(n%c==0) {
			i++;
			n /= c;
			c = 1;
		}
	}
	h = i;
	int fat[i];
	for(c=2, i=0, n=nup; c<=n; c++) {
		if(n%c==0) {
			fat[i] = c;
			n /= c;
			c = 1;
			i++;
		}
	}
	for(c=1, i=0, n=nup; c<=n; c++) {
		if(n%c==0) {
			i++;
		}
	}
	j = i;
	int dvs[i];
	for(c=1, i=0, n=nup; c<=n; c++) {
		if(n%c==0) {
			dvs[i] = c;
			i++;
		}
	}
	tab(1);
	printf("FATORES (");
	color(15);
	printf("%d",h);
	color(10);
	printf(") = ");
	for(c=0; c<h; c++) {
		color(15);
		printf("%d",fat[c]);
		color(10);
		if(c<h-1) {
			printf(", ");
		}
	}
	printf(";");
	tab(1);
	printf("DIVISORES (");
	color(15);
	printf("%d",j);
	color(10);
	printf(") = ");
	for(c=0; c<j; c++) {
		color(15);
		printf("%d",dvs[c]);
		color(10);
		if(c<j-1) {
			printf(", ");
		}
	}
	printf(".");
	tab(1);
}

void bhask() {
	float a, b, c, d, x1, x2, xv, yv;
	tab(2);
	printf("A = ");
	a = scan();
	tab(1);
	printf("B = ");
	b = scan();
	tab(1);
	printf("C = ");
	c = scan();
	if(a==0) {
		x1 = -c/b;
	} else {
		d = b*b - 4*a*c;
		xv = -b/(2*a);
		yv = -d/(4*a);
		if(d<0) {
			x1 = sqrt(-d)/(2*a);
			x2 = -sqrt(-d)/(2*a);
		} else {
			x1 = (sqrt(d) - b)/(2*a);
			x2 = (-b -sqrt(d))/(2*a);
		}
	}
	tab(1);
	color(15);
	if(a!=0) {
		printf("%f.x^2 ",a);
		if(b>0) {
			printf("+ ");
		}
	}
	if(b!=0) {
		printf("%f.x ",b);
	}
	if(c>0) {
		printf("+ ");
	}
	if(c!=0) {
		printf("%f",c);
	}
	tab(1);
	color(15);
	if(a==0) {
		if(b==0) {
			printf("CONSTANTE ");
			color(10);
			if(c==0) {
				printf("NULA");
			} else {
				printf("H = ");
				color(15);
				printf("%f",c);
			}
		} else {
			printf("AFIM ");
			color(10);
			if(c==0) {
				printf("IN");
			}
			printf("COMPLETA");
			tab(1);
			printf("RAIZ = ");
			color(15);
			printf("%f",x1);
		}
	} else {
		printf("QUADRATICA ");
		color(10);
		if(b==0 || c==0) {
			printf("IN");
		}
		printf("COMPLETA");
		tab(1);
		printf("CONCAVIDADE PARA ");
		color(15);
		if(a>0) {
			printf("CIMA");
		} else {
			printf("BAIXO");
		}
		tab(1);
		printf("COORDENADAS DO VERTICE: ");
		color(15);
		printf("%f",xv);
		color(10);
		printf(" ; ");
		color(15);
		printf("%f",yv);
		tab(1);
		printf("INTERSECCAO COM Y (c) = ");
		color(15);
		printf("%f",c);
		tab(1);
		printf("INTERSECCAO COM X (Raiz): ");
		color(15);
		if(d<0) {
			printf("%f + %fi",b/(2*a),x1);
			color(10);
			printf(" e ");
			color(15);
			printf("%f - %fi",b/(2*a),x1);
		} else {
			printf("%f",x1);
			if(d>0) {
				color(10);
				printf(" e ");
				color(15);
				printf("%f",x2);
			}
		}
	}
	tab(1);
}

int trug (float a, float b, float c) {
	int d = 0;
	if(a+b>c) {
		if(b+c>a) {
			if(a+c>b) {
				d++;
			}
		}
	}
	return (d);
}

void pit() {
	float a, b, c;
	tab(2);
	printf("HIPOTENUSA = ");
	c = scan();
	tab(1);
	printf("CATETO a = ");
	a = scan();
	tab(1);
	printf("CATETO b = ");
	b = scan();
	if(a<=0 || b<=0 || c<=0) {
		if(c<=0 && a>0 && b>0) {
			c = sqrt(a*a + b*b);
		}
		if(c>0 && a<=0 && b>0) {
			a = sqrt(c*c - b*b);
		}
		if(c>0 && a>0 && b<=0) {
			b = sqrt(c*c - a*a);
		}
		tab(1);
		if(trug(a, b, c)) {
			printf("HIP = ");
			color(15);
			printf("%f",c);
			tab(1);
			printf("CAT a = ");
			color(15);
			printf("%f",a);
			tab(1);
			printf("CAT b = ");
			color(15);
			printf("%f",b);
		} else {
			color(12);
			printf("NAO E UM TRIANGULO");
		}
	} else {
		if(trug(a, b, c)==0) {
			tab(1);
			color(12);
			printf("NAO E UM TRIANGULO");
		}
	}
	tab(1);
}

void heron() {
	float a, b, c, A, p;
	tab(2);
	printf("LADO a = ");
	a = scan();
	tab(1);
	printf("LADO b = ");
	b = scan();
	tab(1);
	printf("LADO c = ");
	c = scan();
	tab(1);
	if(trug(a, b, c)) {
		p = (a + b + c)/2;
		A = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("AREA = ");
		color(15);
		printf("%f",A);
	} else {
		color(12);
		printf("NAO E UM TRIANGULO");
	}
	tab(1);
}

int asc (char v) {
	int b = 0;
	if(v>=48 && v<=122) {
		if(v<=57) {
			b = v - 47;
		}
		if(v>=65 && v<=90) {
			b = v - 54;
		}
		if(v>=97) {
			b = v - 86;
		}
	}
	return (b);
}

void num() {
	int bi, bf, i, c, bu, b, sz;
	double t, it;
	char an[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	tab(1);
	do {
		tab(1);
		printf("BASE DE N = ");
		bi = scan();
	} while(bi<2 || bi>36);
	for(sz=0, t=18446744073709551612; t>=1; sz++) {
		t = t/bi;
		if(sz==0) {
			t+=2;
		}
	}
	sz++;
	int n[sz];
	char num[sz];
	do {
		tab(1);
		printf("BASE PARA CONVERSAO = ");
		bf = scan();
	} while(bf<2 || bf>36);
	do {
		tab(1);
		for(c=0; c<sz; c++) {
			num[c] = -1;
			n[c] = 0;
		}
		printf("N(%d) [%d] = ",bi,sz-1);
		color(11);
		scanf("%s",num);
		
		for(c=0, i=sz; c<sz; c++) {
			if(num[c]!=-1 && asc(num[c])==0) {
				i = c;
			}
			if(c>=i) {
				num[c] = -1;
			}
		}
		// corte de caracteres estranhos
		
		for(c=0, i=sz; c<sz; c++) {
			if(num[c]==-1) {
				i = c;
				c = sz;
			}
		}
		//  I = primeiro caracter nulo.
		
		for(c=0; c<i; c++) {
			n[i-c-1] = asc(num[c]) - 1;
		}
		// transferência para o Vetor INT
		
		for(c=0, i=1; c<sz; c++) {
			if(n[c]>=bi) {
				i = 0;
			}
		}
		// validação da base numérica
		
		if(i==0) {
			tab(1);
			color(12);
			printf("NUMERO INVALIDO");
			tab(1);
		}
	} while(i==0);
	for(c=0, it=0; c<sz; c++) {
		it+=n[c]*pow(bi, c);
	}
	bu = it;
	c = 0;
	while(bu>0) {
		bu = bu/bf;
		c++;
	}
	int nf[c];
	bu = it;
	b = c;
	c = 0;
	while(bu>0) {
		nf[c] = bu%bf;
		bu = bu/bf;
		c++;
	}
	tab(1);
	printf("N(%d) = ",bi);
	color(15);
	for(c=sz-1, i=0; c>=0; c--) {
		if(n[c]>0) {
			i++;
		}
		if(i>0) {
			printf("%c",an[n[c]]);
		}
	}
	if(bi!=10 && bf!=10) {
		tab(1);
		printf("N(10) = ");
		color(15);
		printf("%.0f",it);
	}
	tab(1);
	printf("N(%d) = ",bf);
	color(15);
	for(c=b-1; c>=0; c--) {
		printf("%c",an[nf[c]]);
	}
	tab(1);
}

void pag() {
	double a1, a, r, sa, pa, sg, pg;
	int c, n, m;
	tab(2);
	printf("a1 = ");
	a1 = scan();
	tab(1);
	printf("RAZAO = ");
	r = scan();
	tab(1);
	printf("Ni = ");
	m = scan();
	tab(1);
	printf("Nf = ");
	n = scan();
	tab(1);
	printf("P.A.");
	for(c=m, sa=0, pa=1; c<=n; c++) {
		a = a1 + (r*(c-1));
		tab(1);
		printf("Termo a%d = ",c);
		color(15);
		printf("%f",a);
		pa = pa*a;
		sa+=a;
	}
	tab(1);
	printf("SOMA (Aritmetica) = ");
	color(15);
	printf("%f",sa);
	tab(1);
	printf("PRODUTO (Aritmetica) = ");
	color(15);
	printf("%f",pa);
	tab(1);
	printf("P.G.");
	for(c=m, sg=0, pg=1; c<=n; c++) {
		a = a1*pow(r,c-1);
		tab(1);
		printf("Termo a%d = ",c);
		color(15);
		printf("%f",a);
		pg = pg*a;
		sg+=a;
	}
	tab(1);
	printf("SOMA (Geometrica) = ");
	color(15);
	printf("%f",sg);
	tab(1);
	printf("PRODUTO (Geometrica) = ");
	color(15);
	printf("%f",pg);
	tab(1);
}

void mmcmdc() {
	int n, c, i, m, p, mc, dc;
	tab(1);
	do {
		tab(1);
		printf("N numeros: ");
		n = scan();
	} while(n<2);
	int nm[n];
	for(c=0; c<n; c++) {
		do {
			tab(1);
			printf("numero n%d = ",c+1);
			nm[c] = scan();
		} while(nm[c]<2);
	}
	for(c=1, m=nm[0]; c<n; c++) {
		if(nm[c]<m) {
			m = nm[c];
		}
	}
	for(c=2, dc=1; c<=m; c++) {
		for(i=0, p=0; i<n; i++) {
			if(nm[i]%c==0) {
				p++;
			}
		}
		if(p==n) {
			dc = c;
		}
	}
	for(c=2, m=2, mc=1; c<=m; c++) {
		for(i=0, m=0, p=0; i<n; i++) {
			if(nm[i]>m) {
				m = nm[i];
			}
			if(nm[i]%c==0) {
				p++;
			}
		}
		if(p>0) {
			for(i=0; i<n; i++) {
				if(nm[i]%c==0) {
					nm[i] = nm[i]/c;
				}
			}
			mc = mc*c;
			c = 1;
		}
	}
	tab(1);
	printf("MMC = ");
	color(15);
	printf("%d",mc);
	tab(1);
	printf("MDC = ");
	color(15);
	printf("%d",dc);
	tab(1);
}

void tria() {
	int n, c, r;
	tab(1);
	do {
		tab(1);
		color(10);
		printf("BASE DO TRIANGULO = ");
		n = scan();
	} while(n<0);
	for(c=0, r=0; c<=n; c++) {
		r+=c;
	}
	tab(1);
	color(10);
	printf("%d NUMERO TRIANGULAR = ",n);
	color(15);
	printf("%d",r);
	tab(1);
}

void phi() {
	int n, c, a1, a2;
	double f, o, t, a;
	tab(1);
	do {
		tab(1);
		printf("Termo N: ");
		n = scan();
	} while(n<3);
	do {
		tab(1);
		printf("a1 = ");
		a1 = scan();
		tab(1);
		printf("a2 = ");
		a2 = scan();
	} while(a1+a2==0);
	o = a1;
	t = a2;
	for(c=3; c<=n; c++) {
		if(c%2==0) {
			t+=o;
			a = t;
			f = (t)/(o);
		} else {
			o+=t;
			a = o;
			f = (o)/(t);
		}
	}
	tab(1);
	printf("Termo a%d (%d,%d) = ",n,a1,a2);
	color(15);
	printf("%.0f",a);
	tab(1);
	printf("PHI = ");
	color(15);
	printf("%f",f);
	tab(1);
}

void pertab (int z) {
	while(z>118) {
		z-=118;
	}
	switch (z) {
		case 1: printf("H"); break; case 41: printf("Nb"); break; case 81: printf("Ti"); break;
		case 2: printf("He"); break; case 42: printf("Mo"); break; case 82: printf("Pb"); break;
		case 3: printf("Li"); break; case 43: printf("Tc"); break; case 83: printf("Bi"); break;
		case 4: printf("Be"); break; case 44: printf("Ru"); break; case 84: printf("Po"); break;
		case 5: printf("B"); break; case 45: printf("Rh"); break; case 85: printf("At"); break;
		case 6: printf("C"); break; case 46: printf("Pd"); break; case 86: printf("Rn"); break;
		case 7: printf("N"); break; case 47: printf("Ag"); break; case 87: printf("Fr"); break;
		case 8: printf("O"); break; case 48: printf("Cd"); break; case 88: printf("Ra"); break;
		case 9: printf("F"); break; case 49: printf("In"); break; case 89: printf("Ac"); break;
		case 10: printf("Ne"); break; case 50: printf("Sn"); break; case 90: printf("Th"); break;
		case 11: printf("Na"); break; case 51: printf("Sb"); break; case 91: printf("Pa"); break;
		case 12: printf("Mg"); break; case 52: printf("Te"); break; case 92: printf("U"); break;
		case 13: printf("Al"); break; case 53: printf("I"); break; case 93: printf("Np"); break;
		case 14: printf("Si"); break; case 54: printf("Xe"); break; case 94: printf("Pu"); break;
		case 15: printf("P"); break; case 55: printf("Cs"); break; case 95: printf("Am"); break;
		case 16: printf("S"); break; case 56: printf("Ba"); break; case 96: printf("Cm"); break;
		case 17: printf("Cl"); break; case 57: printf("La"); break; case 97: printf("Bk"); break;
		case 18: printf("Ar"); break; case 58: printf("Ce"); break; case 98: printf("Cf"); break;
		case 19: printf("K"); break; case 59: printf("Pr"); break; case 99: printf("Es"); break;
		case 20: printf("Ca"); break; case 60: printf("Nd"); break; case 100: printf("Fm"); break;
		case 21: printf("Sc"); break; case 61: printf("Pm"); break; case 101: printf("Md"); break;
		case 22: printf("Ti"); break; case 62: printf("Sm"); break; case 102: printf("No"); break;
		case 23: printf("V"); break; case 63: printf("Eu"); break; case 103: printf("Lr"); break;
		case 24: printf("Cr"); break; case 64: printf("Gd"); break; case 104: printf("Rf"); break;
		case 25: printf("Mn"); break; case 65: printf("Tb"); break; case 105: printf("Db"); break;
		case 26: printf("Fe"); break; case 66: printf("Dy"); break; case 106: printf("Sg"); break;
		case 27: printf("Co"); break; case 67: printf("Ho"); break; case 107: printf("Bh"); break;
		case 28: printf("Ni"); break; case 68: printf("Er"); break; case 108: printf("Hs"); break;
		case 29: printf("Cu"); break; case 69: printf("Tm"); break; case 109: printf("Mt"); break;
		case 30: printf("Zn"); break; case 70: printf("Yb"); break; case 110: printf("Ds"); break;
		case 31: printf("Ga"); break; case 71: printf("Lu"); break; case 111: printf("Rg"); break;
		case 32: printf("Ge"); break; case 72: printf("Hf"); break; case 112: printf("Cn"); break;
		case 33: printf("As"); break; case 73: printf("Ta"); break; case 113: printf("Nh"); break;
		case 34: printf("Se"); break; case 74: printf("W"); break; case 114: printf("Fl"); break;
		case 35: printf("Br"); break; case 75: printf("Re"); break; case 115: printf("Mc"); break;
		case 36: printf("Kr"); break; case 76: printf("Os"); break; case 116: printf("Lv"); break;
		case 37: printf("Rb"); break; case 77: printf("Ir"); break; case 117: printf("Ts"); break;
		case 38: printf("Sr"); break; case 78: printf("Pt"); break; case 118: printf("Og"); break;
		case 39: printf("Y"); break; case 79: printf("Au"); break;
		case 40: printf("Zr"); break; case 80: printf("Hg"); break;
	}
}

void lpqui() {
	int z, cv, se, c, d, e, i;
	tab(1);
	do {
		tab(1);
		printf("NUMERO ATOMICO z = ");
		z = scan();
	} while(z<=0 || z>118);
	tab(1);
	for(c=1, d=z, i=0; c<=19 && d>0; c++) {
		
		if(c==1 || c==2 || c==4 || c==6 || c==9 || c==12 || c==16) { se = 2; }
		if(c==3 || c==5 || c==8 || c==11 || c==15 || c==19) { se = 6; }
		if(c==7 || c==10 || c==14 || c==18) { se = 10; }
		if(c==13 || c==17) { se = 14; }
		// definição do Subnível do Cálculo
		
		if(c==1) { cv = 1; }
		if(c==2 || c==3) { cv = 2; }
		if(c==4 || c==5 || c==7) { cv = 3; }
		if(c==6 || c==8 || c==10 || c==13) { cv = 4; }
		if(c==9 || c==11 || c==14 || c==17) { cv = 5; }
		if(c==12 || c==15 || c==18) { cv = 6; }
		if(c==16 || c==19) { cv = 7; }
		// definição da Camada do Cálculo
		
		color(10);
		printf("%d",cv);
		switch (se) {
			case 2: printf("s"); break;
			case 6: printf("p"); break;
			case 10: printf("d"); break;
			case 14: printf("f"); break;
		}
		if(cv>i) {
			i = cv;
			// i = Camada de Valência (+externa)
		}
		color(15);
		if(d<se) {
			printf("%d",d);
			e = d;
			d = 0;
		} else {
			printf("%d",se);
			e = d;
			d-=se;
		}
		if(d>0) {
			color(10);
			printf(", ");
		}
	}
	cv = i;
	tab(1);
	printf("CAMADA DE VALENCIA (Periodo) = ");
	color(15);
	printf("%d",cv);
	char val[] = "KLMNOPQ";
	color(10);
	printf(" (");
	color(15);
	printf("%c",val[cv-1]);
	color(10);
	printf(")");
	tab(1);
	printf("SUBNIVEL MAIS ENERGETICO = ");
	color(15);
	c = cv;
	if(se>=10) {
		c--;
		if(se==14) {
			c--;
		}
	}
	printf("%d",c);
	switch (se) {
		case 2: printf("S"); break;
		case 6: printf("P"); break;
		case 10: printf("D"); break;
		case 14: printf("F"); break;
	}
	color(10);
	printf(" (");
	color(15);
	printf("%d",e);
	color(10);
	printf(" e)");
	tab(1);
	printf("ELEMENTO: ");
	color(15);
	pertab(z);
	tab(1);
	if(se==2 || se==6) {
		printf("REPRESENTATIVO");
	} else {
		printf("METAL DE TRANSICAO ");
		color(15);
		if(se==14) {
			printf("IN");
		} else {
			printf("EX");
		}
		printf("TERNA");
	}
	tab(1);
	color(15);
	if(se==14) {
		if(cv==6) {
			printf("Lantanideo");
		} else {
			printf("Actinideo");
		}
	} else {
		if(se==2) {
			printf("METAL ALCALINO");
			if(z%2==0) {
				printf("-TERROSO");
			}
			printf(" (Muito Reativo)");
			if(z<3) {
				tab(1);
				color(15);
			}
		}
		if(se!=2 || z<3) {
			if(se==6 || z<3) {
				if(z==5 || z==14 || z==32 || z==33 || z==51 || z==52 || z==84 || z==85) {
					printf("SEMIMETAL (Metaloide) ");
				}
				if(e==6 || z==2) {
					printf("GAS NOBRE");
				} else {
					if(cv==7) {
						printf("(propriedades desconhecidas)");
					} else {
						if(e+1>=cv) {
							printf("AMETAL (Nao-Metal)");
						} else {
							printf("METAL (Menos Reativo)");
						}
					}
					tab(1);
					if(z==1 || e==5) {
						printf("HALOGENIO");
					}
					if(e==4) {
						printf("CALCOGENIO");
					}
					if(e<4 && se==6) {
						printf("FAMILIA DO ");
						switch (e) {
							case 1: printf("BORO (B)"); break;
							case 2: printf("CARBONO (C)"); break;
							case 3: printf("NITROGENIO (N)"); break;
							//case : printf(""); break;
						}
					}
				}
			} else {
				printf("FAMILIA DO ");
				if((se==10 && e==1) || se==14) {
					printf("ESCANDIO (Sc)");
				}
				if(se==10) {
					switch (e) {
						case 2: printf("TITANIO (Ti)"); break;
						case 3: printf("VANADIO (V)"); break;
						case 4: printf("CROMIO (Cr)"); break;
						case 5: printf("MANGANES (Mn)"); break;
						case 6: printf("FERRO (Fe)"); break;
						case 7: printf("COBALTO (Co)"); break;
						case 8: printf("NIQUEL (Ni)"); break;
						case 9: printf("COBRE (Cu)"); break;
						case 10: printf("ZINCO (Zn)"); break;
						//case : printf(""); break;
					}
				}
			}
		}			
	}
	// classificação do elemento
	tab(1);
}

void termo() {
	float K, C, F, R;
	tab(1);
	do {
		tab(1);
		printf("TEMPERATURA = ");
		C = scan();
	} while(C<-273.15);
	F = (C*9/5) + 32;
	R = F + 459.67;
	K = C + 273.15;
	tab(1);
	printf("P/ CELSIUS: ");
	tab(1);
	printf("Kelvin = ");
	color(15);
	printf("%f",K);
	color(10);
	printf(" K");
	tab(1);
	printf("Fahrenheit = ");
	color(15);
	printf("%f",F);
	color(10);
	printf(" F");
	tab(1);
	printf("Rankine = ");
	color(15);
	printf("%f",R);
	color(10);
	printf(" Ra");
	tab(1);
	F = C;
	printf("P/ FAHRENHEIT: ");
	R = F + 459.67;
	C = (F - 32)*85/9;
	K = C + 273.15;
	tab(1);
	printf("Rankine = ");
	color(15);
	printf("%f",R);
	color(10);
	printf(" Ra");
	tab(1);
	printf("Celsius = ");
	color(15);
	printf("%f",C);
	color(10);
	printf(" C");
	tab(1);
	printf("Kelvin = ");
	color(15);
	printf("%f",K);
	color(10);
	printf(" K");
	tab(1);
}

void imc() {
	float h, m, i;
	tab(1);
	do {
		tab(1);
		printf("MASSA (kg) = ");
		m = scan();
	} while(m<0);
	do {
		tab(1);
		printf("ALTURA (m) = ");
		h = scan();
	} while(h<0);
	while(h>=10) {
		h = h/10;
	}
	i = m/(h*h);
	tab(1);
	printf("IMC = ");
	color(15);
	printf("%f",i);
	color(10);
	printf(" == ");
	color(15);
	if(i<18.5) {
		if(i<17) {
			printf("MUITO ");
		}
		printf("ABAIXO DO PESO");
	} else {
		if(i>25) {
			if(i>30) {
				printf("OBESO ");
				if(i>35) {
					if(i>40) {
						printf("MORBIDO");
					} else {
						printf("SEVERO");
					}
				}
			} else {
				printf("ACIMA DO PESO");
			}
		} else {
			printf("PESO NORMAL");
		}
	}
	tab(1);
}

void vol() {
	float r, c, ac, as, v;
	tab(1);
	do {
		tab(1);
		printf("RAIO = ");
		r = scan();
	} while(r<=0);
	c = 6.283185*r;
	ac = 3.141592*r*r;
	as = 4*ac;
	v = as*r/3;
	tab(1);
	printf("CIRCUNFERENCIA = ");
	color(15);
	printf("%f",c);
	tab(1);
	printf("AREA DO CIRCULO = ");
	color(15);
	printf("%f",ac);
	tab(1);
	printf("AREA SUPERFICIAL DA ESFERA = ");
	color(15);
	printf("%f",as);
	tab(1);
	printf("VOLUME = ");
	color(15);
	printf("%f",v);
	tab(1);
}

void collatz () {
	tab(2);
	printf("NUMERO = ");
	int c, num = scan();
	int i[2];
	i[0] = 0;
	i[1] = 0;
	if(num<0) num = -num;
	for(c=0; num>1; c++) {
		i[num%2]++;
		if(num%2==0)
			num /= 2;
		else
			num = (3*num) + 1;
	}
	tab(1);
	printf("NUMERO DE ETAPAS: ");
	color(15);
	printf("%d",c);
	tab(1);
	printf("NUMERO DE ETAPAS PARES: ");
	color(15);
	printf("%d",i[0]);
	tab(1);
	printf("NUMERO DE ETAPAS IMPARES: ");
	color(15);
	printf("%d",i[1]);
	tab(1);
}

void runt (int t) {
	int h, m, s;
	s = time(NULL)-t;
	for(m=0; s>=60; m++) {
		s-=60;
	}
	for(h=0; m>=60; h++) {
		m-=60;
	}
	color(15);
	printf("\n\a (");
	if(h>0) {
		printf("%d.",h);
	}
	if(h+m>0) {
		printf("%d.",m);
	}
	printf("%d) ",s);
}

void seqn() {
	int c, i, f, n, m, o, p0, p1, p2, p, t, h, s, pc;
	tab(2);
	printf("Ni = ");
	i = scan();
	tab(1);
	printf("Nf = ");
	f = scan();
	if(f<i) {
		c = f;
		f = i;
		i = c;
	}
	if(i<2) {
		i = 2;
	}
	pc = 0;
	tab(1);
	color(12);
	printf("MOSTRAR NUMEROS PRIMOS ? 1/0");
	do {
		c = getch() - 48;
	} while(c!=0 && c!=1);
	pc+=(c*100);
	tab(1);
	color(12);
	printf("MOSTRAR NUMEROS PERFEITOS ? 1/0");
	do {
		c = getch() - 48;
	} while(c!=0 && c!=1);
	pc+=(c*10);
	tab(1);
	color(12);
	printf("MOSTRAR NUMEROS AMIGOS ? 1/0");
	do {
		c = getch() - 48;
	} while(c!=0 && c!=1);
	pc+=(c);
	t = time(NULL);
	for(c=i, p=0, p0=0, p1=0, p2=0; c<=f && pc>0; c++) {
		for(m=2, n=1; m<c; m++) {
			if(c%m==0) {
				n+=m;
			}
		}
		if(n==1) {
			if(pc/100==1) {
				p++;
				p0++;
				runt(t);
				color(14);
				printf("[%d] NUMERO PRIMO [%d] = ",p,p0);
				color(15);
				printf("%d",c);
			}
		} else {
			if(n==c && (pc%100)/10==1) {
				p++;
				p1++;
				runt(t);
				color(13);
				printf("[%d] NUMERO PERFEITO [%d] == ",p,p1);
				color(15);
				printf("%d",c);
			}
			if((n>c || n<i) && pc%10==1) {
				for(m=2, o=1; m<n; m++) {
					if(n%m==0) {
						o+=m;
					}
				}
				if(o==c) {
					p++;
					p2++;
					runt(t);
					color(10);
					printf("[%d] NUMEROS AMIGOS [%d] = ",p,p2);
					color(15);
					printf("%d",c);
					color(13);
					printf(" & ");
					color(15);
					printf("%d",n);
				}
			}
		}
	}
	s = time(NULL)-t;
	for(m=0; s>=60; m++) {
		s-=60;
	}
	for(h=0; m>=60; h++) {
		m-=60;
	}
	tab(1);
	color(15);
	if(h<100) {
		printf("0");
		if(h<10) {
			printf("0");
		}
	}
	printf("%d",h);
	color(10);
	printf("\a hrs, ");
	color(15);
	if(m<10) {
		printf("0");
	}
	printf("%d",m);
	color(10);
	printf(" min, ");
	color(15);
	if(s<10) {
		printf("0");
	}
	printf("%d",s);
	color(10);
	if(i==2) {
		i = 0;
	}
	printf(" sec CALCULANDO numeros entre %d e %d",i,f);
	tab(1);
}

void com (int n, char cd[], char sig[]) {
	color(12);
	printf("\n                       ");
	if(n<10) {
		printf("0");
	}
	printf("%d",n);
	color(13);
	printf(" >  ");
	color(15);
	printf("%s",cd);
	color(14);
	printf(" == ");
	color(15);
	printf("%s",sig);
}

int dvCPF (int n, int cpf[]) {
	int c, i=9+n, s = 0;
	for(c=0; c<8+n; c++) {
		s += cpf[c]*i;
		i--;
	}
	s = 11 - (s%11);
	if(s>9) s = 0;
	return s;
}

int dvCNPJ (int n, int cnpj[]) {
	int c, i=4+n, s = 0;
	for(c=0; c<11+n; c++) {
		s += cnpj[c]*i;
		i--;
		if(i<2) i = 9;
	}
	s = 11 - (s%11);
	if(s>9) s = 0;
	return s;
}

void printUF (int n) {
	switch (n) {
		case 0: printf("Rio Grande do Sul (RS)"); break;
		case 1: printf("Distrito Federal (DF), Goias (GO), Mato Grosso (MT), Mato Grosso do Sul (MS) e Tocantins (TO)"); break;
		case 2: printf("Amazonas (AM), Para (PA), Roraima (RR), Amapa (AP), Acre (AC) e Rondonia (RO)"); break;
		case 3: printf("Ceara (CE), Maranhao (MA) e Piaui (PI)"); break;
		case 4: printf("Paraiba (PB), Pernambuco (PE), Alagoas (AL) e Rio Grande do Norte (RN)"); break;
		case 5: printf("Bahia (BA) e Sergipe (SE)"); break;
		case 6: printf("Minas Gerais (MG)"); break;
		case 7: printf("Rio de Janeiro (RJ) e Espirito Santo (ES)"); break;
		case 8: printf("Sao Paulo (SP)"); break;
		case 9: printf("Parana (PR) e Santa Catarina (SC)"); break;
	}
}

void ValidadorCPF () {
	char cpf[] = "xxx.xxx.xxX-yY";
	int c, i, dv1, dv2;
	printf("INSIRA O CPF: ");
	color(11);
	scanf("%s",cpf);
	
	int nCpf[14];
	if(cpf[0]<48 || cpf[0]>57) {
		srand(time(NULL));
		for(c=0; c<9; c++) {
			nCpf[c] = (rand()%10);
			cpf[c] = nCpf[c] + 48;
		}
		if(rand()%2==0) {
			nCpf[9] = dvCPF(1, nCpf);
		} else {
			nCpf[9] = (rand()%10);
		}
		if(rand()%2==0) {
			nCpf[10] = dvCPF(2, nCpf);
		} else {
			nCpf[10] = (rand()%10);
		}
		cpf[9] = nCpf[9] + 48;
		cpf[10] = nCpf[10] + 48;
	}
	tab(1);
	color(15);
	for(c=0, i=0; c<strlen(cpf); c++) {
		if(cpf[c]>=48 && cpf[c]<58) {
			nCpf[i] = cpf[c] - 48;
			printf("%d",nCpf[i]);
			i++;
			if(i==3 || i==6) printf(".");
			if(i==9) printf("-");
		}
	}
	// TRANSFORMA A STRING NUM VETOR INT
	
	tab(1);
	printUF(nCpf[8]);
	// PRINTA O UF
	
	dv1 = dvCPF(1, nCpf);
	dv2 = dvCPF(2, nCpf);
	tab(1);
	printf("DV1 = ");
	color(15);
	printf("%d",dv1);
	color(11);
	printf(" (%d) == ",nCpf[9]);
	color(15);
	if(dv1!=nCpf[9]) printf("IN");
	printf("VALIDO");
	tab(1);
	printf("DV2 = ");
	color(15);
	printf("%d",dv2);
	color(11);
	printf(" (%d) == ",nCpf[10]);
	color(15);
	if(dv2!=nCpf[10]) printf("IN");
	printf("VALIDO");
	// DESCOBRE E PRINTA OS DOIS DÍGITOS VERIFICADORES
}

void ValidadorCNPJ () {
	char cnpj[] = "xx.xxx.xxX/yyyy-zZ";
	int c, i, dv1, dv2;
	printf("INSIRA O CNPJ: ");
	color(11);
	scanf("%s",cnpj);
	
	int nCnpj[18];
	if(cnpj[0]<48 || cnpj[0]>57) {
		srand(time(NULL));
		for(c=0; c<12; c++) {
			nCnpj[c] = (rand()%10);
			cnpj[c] = nCnpj[c] + 48;
		}
		if(rand()%2==0) {
			nCnpj[12] = dvCNPJ(1, nCnpj);
		} else {
			nCnpj[12] = (rand()%10);
		}
		if(rand()%2==0) {
			nCnpj[13] = dvCNPJ(2, nCnpj);
		} else {
			nCnpj[13] = (rand()%10);
		}
		cnpj[12] = nCnpj[12] + 48;
		cnpj[13] = nCnpj[13] + 48;
	}
	tab(1);
	color(15);
	for(c=0, i=0; c<strlen(cnpj); c++) {
		if(cnpj[c]>=48 && cnpj[c]<58) {
			nCnpj[i] = cnpj[c] - 48;
			printf("%d",nCnpj[i]);
			i++;
			if(i==2 || i==5) printf(".");
			if(i==8) printf("/");
			if(i==12) printf("-");
		}
	}
	// TRANSFORMA A STRING NUM VETOR INT
	
	dv1 = dvCNPJ(1, nCnpj);
	dv2 = dvCNPJ(2, nCnpj);
	tab(1);
	printf("DV1 = ");
	color(15);
	printf("%d",dv1);
	color(11);
	printf(" (%d) == ",nCnpj[12]);
	color(15);
	if(dv1!=nCnpj[12]) printf("IN");
	printf("VALIDO");
	tab(1);
	printf("DV2 = ");
	color(15);
	printf("%d",dv2);
	color(11);
	printf(" (%d) == ",nCnpj[13]);
	color(15);
	if(dv2!=nCnpj[13]) printf("IN");
	printf("VALIDO");
	// DESCOBRE E PRINTA OS DOIS DÍGITOS VERIFICADORES
}

int isbnCount (char str[]) {
	int c, n = 0;
	for(c=0; c<strlen(str); c++) {
		if((str[c]>=48 && str[c]<58) || (str[c]==88 || str[c]==120)) n++;
	}
	return n;
}

void ValidadorISBN () {
	char isbn[] = "ab-cdef-ghi-J-..", isbNum[] = "0123456789X";
	int c, i, dvc, dvn, s;
	printf("INSIRA O ISBN: ");
	color(11);
	scanf("%s",isbn);
	
	if(isbn[0]<48 || isbn[0]>57) {
		int dv10=0, dv13=0;
		srand(time(NULL));
		if(rand()%2==0) {
			strcpy(isbn, "  -    -   - ");
		} else {
			strcpy(isbn, "   -  -  -     - ");
		}
		for(c=0, i=10; c<strlen(isbn)-2; c++) {
			if(isbn[c]==' ') {
				isbn[c] = (rand()%10);
				dv13 += isbn[c]*(1+(2*(c%2)));
				dv10 += isbn[c]*i;
				isbn[c] += 48;
				i--;
			}
		}
		dv10 = 11 - (dv10%11);
		dv13 = 10 - (dv13%10);
		i = rand()%11;
		if(rand()%2==0) {
			if(rand()%2==0) {
				i = dv10;
			} else {
				i = dv13;
			}
		}
		isbn[strlen(isbn)-1] = isbNum[i];
	}
	
	int t = isbnCount(isbn), nBook[t];
	for(c=0, i=0; c<strlen(isbn); c++) {
		if((isbn[c]>=48 && isbn[c]<58) || (isbn[c]==88 || isbn[c]==120)) {
			nBook[i] = isbn[c] - 48;
			if(nBook[i]>10) nBook[i] = 10;
			i++;
		}
	}
	// STRING --> VETOR INT
	
	tab(1);
	color(15);
	dvn = nBook[t-1];
	dvc = -1;
	s = 0;
	if(t==10 || t==13) {
		if(t==10) {
			for(c=0, i=t; c<t-1; c++) {
				s += nBook[c]*(i--);
				printf("%c",isbNum[nBook[c]]);
				if(c==2 || c==6 || c==9) printf("-");
			}
			dvc = 11 - (s%11);
		}
		if(t==13) {
			for(c=0; c<t-1; c++) {
				s += nBook[c]*(1+(2*(c%2)));
				printf("%c",isbNum[nBook[c]]);
				if(c==3 || c==5 || c==7 || c==12) printf("-");
			}
			dvc = 10 - (s%10);
		}
		printf("-%c",isbNum[dvn]);
	}
	// CÁLCULO DO DÍGITO VERIFICADOR
	
	tab(1);
	printf("DV = ");
	color(15);
	printf("%d",dvc);
	color(11);
	printf(" (%d) == ",dvn);
	color(15);
	if(dvc!=dvn) printf("IN");
	printf("VALIDO");
	// PRINT
}

void validador () {
	int c = 0;
	do {
		tab(2);
		com(0, "ESC", "SAIR");
		com(1, "CPF", "VALIDADOR");
		com(2, "CNPJ", "VALIDADOR");
		com(3, "ISBN", "VALIDADOR");
		do {
			c = getch();
			if(c>=48 && c<58) c -= 48;
			if(c==27) c = 0;
		} while(c<0 && c>3);
		tab(2);
		switch (c) {
			case 1: ValidadorCPF(); break;
			case 2: ValidadorCNPJ(); break; 
			case 3: ValidadorISBN(); break;
		}
	} while(c>0);
}

int main () {
	char C;
	do {
		C = 48;
		system("cls");
		printf("\a");
		sleep(1);
		color(15);
		printf("\n\n    ? p/ AJUDA \n    0 p/ SAIR \n");
		do {
			do {
				if(C<0) {
					switch (C) {
						case -1:
							color(13);
							printf("\n\n\a    LISTA DE COMANDOS: \n");
							sleep(1);
							com(0, "1","cls()");
							com(0, "2","seqn()");
							com(0, "3","validador()");
							com(1, "+", "ADD(n, a1, a2... an)");
							com(2, "-", "SUB(a, b)");
							com(3, "* . x", "MULT(n, a1, a2... an)");
							com(4, "/ :", "DIV(a, b)");
							com(5, "^", "POW(a, b)");
							com(6, "r", "RAD(a, b)");
							com(7, "L", "LOG(x, y)");
							com(8, "!", "FACT(n)");
							com(9, "a", "TRIG(a)");
							com(10, "e", "EUL(x)");
							com(11, "B", "BHASK(a, b, c)");
							com(12, "P", "PIT(a, b, c)");
							com(13, "H", "HERON(a, b, c)");
							com(14, "N", "NUM(bi, bf, n)");
							com(15, "G", "PAG(r, a1, m, n)");
							com(16, "c", "MMCMDC(n, a1, a2... an)");
							com(17, "t", "TRIA(n)");
							com(18, "f", "PHI(n, a1, a2)");
							com(19, "Q", "LP(z)");
							com(20, "k", "TERMO(t)");
							com(21, "M", "IMC(m, h)");
							com(22, "v", "VOL(r)");
							com(23, "z", "COLLATZ(x)");
							com(24, "s", "COMB(n, p)");
							printf("\n\n\a");
							C = 0;
						break;
						case -2:
							system("cls");
							color(15);
							printf("\n\n    ? p/ AJUDA \n    0 p/ SAIR \n");
							C = 48;
						break;
					}
				}
				tab(1);
				printf(">> ");
				color(11);
				C = ' ';
				scanf("%c",&C);
				switch (C) {
					case '1': C = -2; break; // Clean Screen
					case '?': C = -1; break; // HELP
					case '+': C = 1; break; // add
					case '-': C = 2; break; // sub
					case '*': C = 3; break; // mult
					case '.': C = 3; break; // mult
					case 'x': C = 3; break; // mult
					case 'X': C = 3; break; // mult
					case ':': C = 4; break; // div
					case '/': C = 4; break; // div
					case 'a': C = 5; break; // trig
					case 'A': C = 5; break; // trig
					case '^': C = 6; break; // pow
					case 'R': C = 7; break; // rad
					case 'r': C = 7; break; // rad
					case 'L': C = 8; break; // log
					case 'l': C = 8; break; // log
					case '!': C = 9; break; // fact
					//case '': C = 10 ; break; POR ALGUMA RAZÃO, O PROGRAMA REPETE INFINITAMENTE TAL ALGORITMO.
					case 's': C = 25; break; // comb simp
					case 'S': C = 25; break; // comb simp
					case 'E': C = 11; break; // tot / eul
					case 'e': C = 11; break; // tot / eul
					case 'B': C = 12; break; // bhask
					case 'b': C = 12; break; // bhask
					case 'P': C = 13; break; // pit
					case 'p': C = 13; break; // pit
					case 'H': C = 14; break; // heron
					case 'h': C = 14; break; // heron
					case 'N': C = 15; break; // num
					case 'n': C = 15; break; // num
					case 'M': C = 16; break; // IMC
					case 'm': C = 16; break; // IMC
					case 'G': C = 17; break; // P.A.G.
					case 'g': C = 17; break; // P.A.G.
					case 'C': C = 18; break; // MMC & MDC
					case 'c': C = 18; break; // MMC & MDC
					case 'T': C = 19; break; // tria
					case 't': C = 19; break; // tria
					case 'F': C = 20; break; // phi
					case 'f': C = 20; break; // phi
					case 'Q': C = 21; break; // lp / qui
					case 'q': C = 21; break; // lp / qui
					case 'K': C = 22; break; // termo
					case 'k': C = 22; break; // termo
					case 'V': C = 23; break; // vol
					case 'v': C = 23; break; // vol
					case '2': C = 24; break; // MENU DE SEQUÊNCIAS
					case '3': C = 26; break; // MENU DE VALIDADORES
					case 'z': C = 27; break; // collatz
					case 'Z': C = 27; break; // collatz
					//case '': C = ; break;
				}
			} while(C==0);
			switch (C) {
				case 1: add(); break;
				case 2: sub(); break;
				case 3: mult(); break;
				case 4: divs(); break;
				case 5: trig(); break;
				case 6: pot(); break;
				case 7: rad(); break;
				case 8: lg(); break;
				case 9: fact(); break;
				case 25: comb(); break;
				case 11: tot(); break;
				case 12: bhask(); break;
				case 13: pit(); break;
				case 14: heron(); break;
				case 15: num(); break;
				case 16: imc(); break;
				case 17: pag(); break;
				case 18: mmcmdc(); break;
				case 19: tria(); break;
				case 20: phi(); break;
				case 21: lpqui(); break;
				case 22: termo(); break;
				case 23: vol(); break;
				case 24: seqn(); break;
				case 26: validador(); break;
				case 27: collatz(); break;
				//case : (); break;
			}
		} while(C!='0');
		
		// FIM DA CALCULADORA PROPRIAMENTE DITA
		
		printf("\a\n\n      ");
		color(15);
		printf("1/0");
		color(10);
		printf("? ");
		do {
			C = getch();
			if(C==0 || C==1) {
				C = -1;
			}
			if(C==49 || C==83 || C==115 || C==89 || C==121 || C==84 || C==116 || C==80 || C==112) {
				C = 1;
			}
			if(C==48 || C==78 || C==110 || C==70 || C==102 || C==27) {
				C = 0;
			}
		} while(C!=0 && C!=1);
		if(kbhit()) {
			getch();
			fflush(stdin);
		}
	} while(C>0);
	sleep(1);
	return 0;
}
