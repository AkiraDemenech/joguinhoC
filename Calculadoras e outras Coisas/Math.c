#include<stdio.h>
#include<math.h>
	void bhaskara () {
		float a, b, c, d, x1, x2, xv, yv;
		printf("\n f(x) = ax^2 + bx + c \n Insira os Valores dos Coeficientes A, B, e C: ");
		scanf("%f %f %f",&a,&b,&c);
		printf("\n\n Funcao ");
		if(a==0 && b==0) { printf("CONSTANTE (K): ");
			if(c==0) { printf("Zero"); } else { printf("Y = %f",c); }
		}
		if(a==0 && b!=0) {
			x1 = -c/b;
			printf("AFIM (1o Grau) ");
			if(c==0) { printf("IN"); }
			printf("COMPLETA: Y = %fx",b);
			if(c!=0) {
				if(c>0) { printf(" +"); }
				printf(" %f",c);
			}
			printf(" (");
			if(b>0) { printf("Ascerdente/Crescente a>"); } else { printf("Descentente/Decrescente a<"); }
			printf("0)\n\n Intercessao com o Eixo Y = B: %f",c);
			if(c==0) { printf(" (Origem)"); }
			printf("\n Intercecao com o Eixo X = Raiz: %f",x1);
		}
		if(a!=0) {
			d = b*b -4*a*c;
			xv = -b/(2*a);
			yv = -d/(4*a);
			if(d>0) {
				x1 = (-b + (float)sqrt(d))/(2*a);
				x2 = (-b - (float)sqrt(d))/(2*a);
			}
			if(d==0) { x2 = -b/(2*a); }
			printf("QUADRATICA (2o Grau) ");
			if(b==0 || c==0) { printf("IN"); }
			printf("COMPLETA: Y = %fx^2",a);
			if(b!=0) {
				if(b>0) { printf(" +"); }
				printf(" %fx ",b);
			}
			if(c!=0) {
				if(c>0) { printf(" +"); }
				printf(" %f",c);
			}
			printf(" (Concavidade para ");
			if(a>0) { printf("CIMA a>"); } else { printf("BAIXO a<"); }
			printf("0) \n\n Intercessao com o Eixo Y = C: %f",c);
			if(c==0) { printf(" (Origem)"); }
			printf("\n\n Coordenadas do Vertice: (%f;%f)\n Eixo de Simetria = -B/2A: %f \n Dominio de Imagem Unica = -D/4A: %f \n\n Duas Raizes ",xv,yv,xv,yv);
			if(d>0) { printf("DISTINTAS (Duas Intercessoes"); }
			if(d==0) { printf("IGUAIS (Uma Unica Intercessao"); }
			if(d<0) { printf("COMPLEXAS / NAO REAIS (Nenhuma Intercessao"); }
			printf(" com o Eixo X)");
			if(d>=0) {
				printf(": %f ",x1);
				if(d>0) { printf("& %f",x2); } else { printf("(Vertice)"); }
			}
		}
	}
	void collatz () {
		int n = 0, m = 0;
		printf("\n --> Conjectura de Collatz/Ulam/Thwaites \n --> Problema 3x + 1 \n --> Problema de Kakutani/Siracusa \n --> Algoritmo de Hasse \n\n NUMERO = ");
		while((n==0) || (n==1) || (n==2) || (n==4)) { scanf("%d",&n); }
		while(n!=2) {
			if(n%2==0) {
				printf("\n %d - %d : 2 = ",m,n);
				n = n/2;
				m++;
			} else {
				printf("\n %d - %d x 3 + 1 = ",m,n);
				n = 1 + n*3;
				m++;
			}
			printf("%d (",n);
				if(n%2==1) { printf("IM"); }
				printf("PAR)");
		}
		printf("\n\n --> %d",m);
		m++;
		printf(" - 2 : 2 ==> 1 (Impar Final) - %d",m);
	}
	void fibonacci () {
		int a, o = 0, t = 0;
		printf("\n Insira DOIS (2) NUMEROS iniciais: ");
		while(o+t<1) { scanf("%d %d",&o,&t); }
		if(o>t) {
			a = o;
			o = t;
			t = a;
		}
		printf("\n Comecar ??? N=0 S=1 \n R: ");
		do { scanf("%d",&a); } while(a>1 || a<0);
		if(a==1) {
			while(o+t<999999999) {
				printf("\n\n %d >> %d + %d",a,o,t);
				o = o + t;
				a++;
				printf(" = %d \n\n %d >> %d + %d",o,a,t,o);
				t = o + t;
				a++;
				printf(" = %d",t);
				if(o<0) { o = -o; }
				if(t<0) { t = -t; }
			}
		}
	}
	void numerico () {
	int n = 1, m, b, c;
	printf("\n Base Numerica para Leitura (2-10): ");
     do { scanf("%d",&c); } while(c<2 || c>10);
     printf(" Base ");
     if(c==10) { printf("Decimal"); }
     if(c==8) { printf("Octal"); }
     if(c==2) { printf("Binaria"); }
     if(c!=10 && c!=8 && c!=2) { printf("%d",c); }
     printf("\n\n Base Numerica para Traducao (2-36, exceto %d): ",c);
     do { scanf("%d",&b); } while(b<2 || b>36 || b==c);
     printf(" Base ");
     if(b==16) { printf("Hexadecimal"); }
     if(b==10) { printf("Decimal"); }
     if(b==8) { printf("Octal"); }
     if(b==2) { printf("Binaria"); }
     if(b!=16 && b!=10 && b!=8 && b!=2) { printf("%d",b); }
     printf("\n\n Insira o Numero a ser Traduzido (Base: %d): ",c);
     while(n<2) {
        scanf("%d",&n);
        if(n<2) {
           if(n==0) { printf("\n Sem Valor."); }
           if(n==1) { printf("\n Igual em todas as Bases Hindoarabicas."); }
           if(n<0) { printf("\n Sinal ignorado."); }
           printf("\n INSIRA NOVAMENTE: ");
        }
     }
     m = n;
     while(m>0) {
        if(m%10<c) { m = (m-m%10)/10; } else { printf("\n Numero Invalido \n INSIRA NOVAMENTE: ");
           do {
              scanf("%d",&n);
              m = n;
           } while(n<2);
        }
     }
     printf("\n Numero Valido.");
     int k, u, l, h;
     if(c<10) {
        m = n;
        k = 1;
        u = 0;
        while(m>0) {
           u = u + k*(m%10);
           k = k*c;
           m = (m - m%10)/10;
        }
     } else { u = n; }
     printf("\n\n Numero da Base %d para Base %d",c,b);
     if(c!=10 && b!=10) { printf(" (via Decimal)"); }
     printf(": %d (%d)",n,c);
     if(c!=10) { printf(" ==> %d (10)",u); }
	    if(b!=10) {
	    	m = u;
   	  	for(l=0; m>0; l++) { m = (m - m%b)/b; }
   	  	int j[l];
   	  	m = u;
   	  	for(h=l; h>0; h--) {
   	  		j[h] = m%b;
   	    	m = (m - m%b)/b;
   	  	}
   	  	printf(" ==> ");
   	  	for(h=1; h<=l; h++) {
		  char x[36] = "0123456789ABCDEFGHIJKLMNOPKRSTUVWXYZ";
		  printf("%c",x[j[h]]);
  		}
  		printf(" (%d)",b);
  }
}
	void pitagoras () {
		int i, f, a, o, h, b, c=0, d, e=0;
		printf("\n Insira o Intervalo Numerico (i-f): ");
		scanf("%d %d",&i,&f);
		if(i<0) { i = -i; }
		if(f<0) { f = -f; }
		if(i>f) {
			b = i;
			i = f;
			f = b;
		}
		if(i==0) { i = 1; }
		printf("\n %d - %d \n\n I(s) = %d \n F(e) = %d \n\n Iniciar? s1m ou na0 A = ",i,f,i,f);
		do { scanf("%d",&a); } while(a<0 || a>1);
		while(a>0 && a<=f) {
			int pc = 100*a/f;
			printf("\n Calculando (%d o/o)",pc);
			for(o=i; o<=f; o++) {
				if(o>a) { h = o + 1; } else { h = a + 1; }
				while(h<o+a) {
					if(h*h == (a*a) + (o*o) && o>a) {
						c++;
						printf(" ... ");
						h = o+a;
					}
					h++;
				}
			}
			a++;
		}
		int ad[c], op[c];
		printf("\n\n %d - %d \n\n %d casos de Triangulos Naturais / Racionais / Pitagoricos \n\n Mostrar?? s1m ou na0 A = ",i,f,c);
		do { scanf("%d",&a); } while(a<0 || a>1);
		c = 0;
		while(a>0 && a<=f) {
			for(o=i; o<=f; o++) {
				if(o>a) { h = o + 1; } else { h = a + 1; }
				while(h<o+a) {
					if(h*h == (a*a) + (o*o)) {
						for(b=1; b<=c; b++) { if(op[b]==a && ad[b]==o) { b = c+2; } }
						if(c==0 || b==c+1) {
							c++;
							printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",c,a,o,h,a,o,h);
							ad[c] = a;
							op[c] = o;
						}
						h = o + a;
					}
					h++;
				}
			}
			a++;
		}
		do {
			printf("\n\n %d casos de Triangulos Naturais / Racionais / Pitagoricos \n\n Opcoes: \n (0) Sair \n (1) Mostrar todos Novamente \n (2) Mostrar N novamente \n (3) Mostrar o Triangulo N \n (4) Buscar por um Lado \n A = ",c);
			do { scanf("%d",&b); } while(b<0 || b>4);
			if(b==1) {
				for(b=1; b<=c; b++) {
					h = sqrt(op[b]*op[b] + ad[b]*ad[b]);
					printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h);
				}
			}
			if(b==2) {
				printf("\n\n Insira o Intervalo a ser Repetido (max %d): ",c);
				do { scanf("%d %d",&i,&f); } while(i>c || f>c);
				if(i<0) { i = -i; }
				if(f<0) { f = -f; }
				if(i>f) {
					b = i;
					i = f;
					f = b;
				}
				if(i==0) { i = 1; }
				for(b=i; b<=f; b++) {
					h = sqrt(op[b]*op[b] + ad[b]*ad[b]);
					printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h);
				}
			}
			if(b==3) {
				printf("\n Numero do Triangulo: ");
				do { scanf("%d",&b); } while(b>c || b<0);
				printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h);
			}
			if(b==4) {
				printf("\n Valor da Busca: ");
				do { scanf("%d",&d); } while(d<1);
				printf("\n Filtros de Pesquisa: \n (0) Qualquer uma \n (1) Hipotenusa \n (2) Cateto \n (3) Adjacente \n (4) Oposto \n A = ");
				do { scanf("%d",&b); } while(b<0 || b>4);
				if(b==4) { for(b=1; b<=c; b++) { if(op[b]==d) { h = sqrt(op[b]*op[b] + ad[b]*ad[b]); printf("\n %d) adj %d - OPO %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; } } b = 4; }
				if(b==3) { for(b=1; b<=c; b++) { if(ad[b]==d) { h = sqrt(op[b]*op[b] + ad[b]*ad[b]); printf("\n %d) ADJ %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; } } b = 3; }
				if(b==2) { for(b=1; b<=c; b++) { if(op[b]==d || ad[b]==d) { h = sqrt(op[b]*op[b] + ad[b]*ad[b]); printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; } } b = 2; }
				if(b==1) { for(b=1; b<=c; b++) {
						h = sqrt(op[b]*op[b] + ad[b]*ad[b]);
						if(h==d) { printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; }
					}
					b = 1;
				}
				if(b==0) { for(b=1; b<=c; b++) {
						h = sqrt(op[b]*op[b] + ad[b]*ad[b]);
						if(op[b]==d) { printf("\n %d) adj %d - OPO %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; }
						if(ad[b]==d) { printf("\n %d) ADJ %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; }
						if(h==d) { printf("\n %d) adj %d - opo %d -- HIP = %d --> %d %d %d",b,ad[b],op[b],h,ad[b],op[b],h); e++; }
					}
					b = 0;
				}
				printf("\n\n %d triangulos com ",e);
				if(b==0) { printf("lado "); }
				if(b==1) { printf("hipotenusa "); }
				if(b>1) { printf("cateto "); }
				if(b==3) { printf("adjacente "); }
				if(b==4) { printf("oposto "); }
				printf("igual a %d",d);
			}
			do {
				printf("\n\n Rever? s1m ou na0 A = ");
				scanf("%d",&b);
			} while(b<0 || b>1);
		} while(b>0);
	}
	void primo () {
		int n, d = 2, c = 0, p;
			printf("\n (0) Sair \n\n (1) TESTAR NUMERO \n (2) BUSCAR NUMEROS PRIMOS \n\n R: ");
      do { scanf("%d",&n); } while(n>2 || n<0);
      if(n==1) {
         printf("\n\n TESTADOR NUMERICO: \n Insira um Numero para Testar suas propriedades: ");
         while(n<2) {
            scanf("%d",&n);
            if(n==0) { printf("\n Menor que 1: todos sao seus divisores. \n INSIRA OUTRO: "); }
            if(n==1) { printf("\n Igual a 1: e seu unico divisor. \n INSIRA OUTRO: "); }
         }
         printf("\n\n %d",n);
         while(d<=n/2) {
            if(n%d==0) {
               if(c==0) { printf("\n Divisores de %d: \n ",n); }
               printf("\n %d(",d);
               if(d%2!=0) { printf("IM"); }
               printf("PAR)");
               c++;
            }
            d++;
         }
         if(c==0) { printf("\n Sem Nenhum Divisor (se nao 1 e si proprio)--> NUMERO PRIMO"); } else { printf("\n\n TOTAL DE DIVISORES: %d",c); }
      }
      if(n==2) {
         int n, d, c, p, i, f;
         printf("\n\n BUSCADOR PRIMO: \n Insira os Valores Inicial e Final do Intervalo Numerico: ");
         do { scanf("%d %d",&i,&f); } while(i<0 || f<0 || i==f);
         if(i>f) {
            p = f;
            f = i;
            i = p;
         }
         c = f - i + 1;
         printf("\n\n %d numeros \n INICIO: %d \n FIM: %d",c,i,f);
         p = 0;
         n = i;
         while(n<=f) {
            d = 2;
            while(d<=n/2) {
               if(n%d!=0) {
                  d++;
                  if(d%2==0) { d++; }
               } else { d++; }
            }
            if(d<=n) { p++; }
            n++;
         }
         int pr[p];
         p = 0;
         c = 0;
         n = i;
         printf("\n");
         while(n<=f) {
            c++;
            d = 2;
            printf("\n %d - %d",c,n);
            while(d<=n/2) {
               if(n%d!=0) {
                  d++;
                  if(d%2==0) { d++; }
               } else {
                  printf(" : %d",d);
                  if(d==2) { printf(" (PAR);"); }
                  d = n + 1;
               }
            }
            if(d<=n) {
               p++;
               printf(" --> NUMERO PRIMO %d",p);
               pr[p] = n;
            }
            n++;
         }
         printf("\n\n %d NUMEROS PRIMOS de %d a %d (%d numeros): \n",p,i,f,c);
         c = 1;
         n = 0;
         for(c=1; c<=p; c++) {
            printf("\n %d - %d",c,pr[c]);
            if(pr[c] + 2 == pr[c+1]) {
            	n++;
               printf(" --> Gemeo de %d (%d)",pr[c+1],n);
            }
            if(pr[c-1] + 2 == pr[c]) {
               n++;
               printf(" --> Gemeo de %d (%d)",pr[c-1],n);
            }
         }
         printf("\n\n %d numeros primos gemeos.",n);
      }
	}
	void somatoria () {
		int i, f, s, n;
		printf("\n Insira o PRIMEIRO (1o) e o ULTIMO NUMERO da SOMATORIA: ");
		do { scanf("%d %d",&i,&f); } while(f==i);
		if(i>f) {
			n = i;
			i = f;
			f = n;
		}
		printf("\n Inicial = %d \n Final = %d",i,f);
		if(i==0) { i = 1; }
		n = 0;
		while(n<=i+f) {
			printf("\n %d + %d",n,i);
			if(s>0) { printf(" + %d",s); }
			s = s + i + n;
			n++;
			if(s!=i) { printf(" = %d",s); }
		}
		printf("\n\n Soma ( %d - %d ) = %d",i,f,s);
	}
	void temperatura () {
		int a;
			printf("\n (1) Fahrenheit (F) --> Celsius (C) \n (2) Celsius (C) --> Fahrenheit (F) \n\n R: ");
      do { scanf("%d",&a); } while(a>2 || a<1);
      if(a>0) {
         float c = -300, f = -500, k0;
         printf("\n Insira a Temperatura em Graus ");
         if(a==1) {
            printf("Fahrenheit: ");
            while(f<-459.67) {
               scanf("%f",&f);
               if(f<-459.67) { printf("\n Temperatura Invalida \n Abaixo do Zero Termico Absoluto (-459.67 F = 0 K) \n Insira novamente: "); }
            }
            c=((5*f)-160)/9;
         }
      	if(a==2) {
   	     printf("Celsius: ");
            while(c<-273.15) {
               scanf("%f",&c);
               if(f<-459.67) { printf("\n Temperatura Invalida \n Abaixo do Zero Termico Absoluto (-273.15 C = 0 K) \n Insira novamente: "); }
            }
   	    f=((c*9)+160)/5;
         }
		k0 = c + 273.15;
         printf("\n\n Temperatura: \n Fahrenheit: %f F \n Celsius: %f C \n Kelvin: %f K",f,c,k0);
	}
}
void indi () {
	int s;
	do {
		int n, d, i, f, t1, t2, m, r1 = 0, r2 = 0, r, c, b;
		printf("\n Numa FRACAO IRREDUTIVEL n/d, a Soma M entre N (Numerador/Dividendo) e D (Denominador/Divisor) e INDIVISIVEL por AMBOS, exceto 1. \n Insira os Limites \n Lim = ");
		scanf("%d %d",&i,&f);
		if(f<0) { f = -f; }
		if(i<0) { i = -i; }
		if(f<i) {
			m = f;
			f = i;
			i = m;
		}
		if(i==0) { i = 1; }
		printf("\n Inicio = %d \n Fim = %d",i,f);
		for(d=i; d<=f; d++) {
			for(n=1; n<=f; n++) {
				m = n + d;
				printf("\n \n %d / %d --> m = %d",n,d,m);
				if((n%d>0) && (d%n>0) && ((n%2!=0) || (d%2!=0))) {
					c = 3;
					b = 0;
					while((c<=n/2) && (c<=d/2)) {
						if((n%c==0) && (d%c==0)) { b++; }
						c = c + 2;
					}
					if(b==0) {
						if((m%n==0) && (n>1)) {
							r1++;
							printf(" >> :%d (N)",n);
						}
						if((m%d==0) && (d>1)) {
							r2++;
							if((m%n==0) && (n>1)) { printf(" & "); } else { printf(" >> :"); }
							printf("%d (D)",d);
						}
						r = r1 + r2;
						if((m%n==0) || (m%d==0)) {
							printf(" --> (%d);",r);
						}
					}
				}
			}
		}
		if(i==1) { i = 0; }
		t1 = f-i;
		t2 = t1*f;
		printf("\n\n Total de Casos Testados: %d ( %d - %d = %d ) \n Casos da Soma M divisivel pelo Numerador N: %d \n Casos da Soma M divisivel pelo Divisor D: %d \n Total de Casos Excepcionais: %d",t2,f,i,t1,r1,r2,r);
		if(r>0) {
			printf("\n Exibir casos excepcionais? s1m na0: ");
			do { scanf("%d",&s); } while(s>1 || s<0);
			if(s==1) { for(d=i; d<=f; d++) {
			for(n=1; n<=f; n++) {
				m = n + d;
				if((n%d>0) && (d%n>0) && ((n%2!=0) || (d%2!=0))) {
					c = 3;
					b = 0;
					while((c<=n/2) && (c<=d/2)) {
						if((n%c==0) && (d%c==0)) { b++; }
						c = c + 2;
					}
					if(b==0) {
						printf("\n \n %d / %d --> m = %d ",n,d,m);
						if((m%n==0) && (n>1)) {
							r1++;
							printf(">> : %d (N) ",n);
						}
						if((m%d==0) && (d>1)) {
							r2++;
							if((m%n==0) && (n>1)) { printf("& "); } else { printf(">> :"); }
							printf(" %d (D)",d);
						}
						r = r1 + r2;
						if((m%n==0) || (m%d==0)) {
							printf(" --> (%d)",r);
						}
					}
				}
			}
		} } }
		do {
			printf("\n Reiniciar INDIVISIVIBILIDADE ???? ?? s1m ou na0 Ans: ");
			scanf("%d",&s);
		} while(s>1 || s<0);
	} while(s==1);
}
	int k;
void word () {
	do {
	printf("\n Quantas letras? ");
	do { scanf("%d",&k); } while(k<1);
	char w[k];
	printf("\n Escreva-a: ");
	scanf("%s",&w);
	printf("\n Quantas repeticoes? ");
	do { scanf("%d",&k); } while(k<1);
	int c, n, e, p;
	printf("\n Paragrafacao: s1m na0 a");
	do { scanf("%d",&p); } while(p<0 || p>1);
	printf("\n Espacamento: s1m na0 a");
	do { scanf("%d",&e); } while(e<0 || e>1);
	printf("\n Numeracao: s1m na0 a");
	do { scanf("%d",&n); } while(n<0 || n>1);
	printf("\n\n Iniciar? s1m na0 a");
	do { scanf("%d",&c); } while(c<0 || c>1);
	if(c==1) { for(c=1; c<=k; c++) {
		if(p==1) { printf("\n"); }
		if(e==1) { printf(" "); }
		if(n==1) { printf(" %d ",c); }
		printf("%s",w);
	} }
	printf("\n Reinciar Word++ ??? s1m na0 Ans = ");
	do { scanf("%d",&k); } while(k<0 || k>1);
	} while(k==1);
}
void calc() {
	int c, s, m;
	printf("\n (0) SAIR \n\n (1) Soma e Subtracao (+/-) \n (2) Multiplicacao (x / .) \n (3) Divisao ( / : ^-1) \n\n R: ");
	do { scanf("%d",&k); } while(k<0 || k>3);
	while(k==1) {
		printf("\n Quantas Parcelas? ");
		do { scanf("%d",&s); } while(s<2);
		float p[s+1];
		printf("\n Insira as %d parcelas: \n",s);
		for (c=1; c<=s; c++) { scanf("%f",&p[c]); }
		printf("\n ");
		for (c=s; c>0; c--) {
			printf("%f ",p[c]);
			if(c>1) { printf("+ "); }
			p[s+1] = p[s+1] + p[c];
		}
		printf("= %f",p[s+1]);
		do {
			printf("\n Recalcular SOMA&SUBTRACAO ?? N=0 S=1 R: ");
			scanf("%d",&k);
		} while(k<0 || k>1);
	}
	while(k==2) {
		printf("\n Quantos Fatores? ");
		do { scanf("%d",&m); } while(m<2);
		float f[m+1];
		printf("\n Insira os %d fatores: \n",m);
		for (c=1; c<=m; c++) { scanf("%f",&f[c]); }
		printf("\n ");
		for (c=m; c>0; c--) {
			printf("%f ",f[c]);
			if(c>1) { printf("x "); }
			f[m+1] = f[m+1]*f[c];
		}
		printf("= %f",f[m+1]);
		do {
			printf("\n Recalcular MULTIPLICACAO ?? N=0 S=1 R: ");
			scanf("%d",&k);
		} while(k<0 || k>1);
		if(k==1) { k = 2; }
	}
	while(k==3) {
		float d, n, a;
		printf("\n Insira DIVIDENDO (NUMERADOR) e DIVISOR (DENOMINADOR): ");
		do { scanf("%f %f",&n,&d); } while(d==0);
		a = n/d;
		printf("\n %f / %f = %f",n,d,a);
		do {
			printf("\n Recalcular DIVISAO ?? N=0 S=1 R: ");
			scanf("%d",&k);
		} while(k<0 || k>1);
		if(k==1) { k = 3; }
	}
}
int main () {
	do {
		do {
			printf("\n\n Programas Disponiveis: \n\n (0) Sair \n\n (1) BHASKARA \n (2) COLLATZ \n (3) FIBONACCI \n (4) NUMERICO \n (5) PITAGORAS \n (6) PRIMO \n (7) SOMATORIA \n (8) TEMPERATURA \n\n (9) CALCULADORA SIMPLES \n\n (10) Ler Descricoes \n\n CONSIDERACOES GERAIS: \n - Todos os programas contam com a Ferramenta Reiniciar. \n - Acentuacao, Cedilha, e outros caracteres nao sao exibidos nas interfaces. \n - Os programas sao estritamente matematicos, nao sendo capazes de lidar com letras ou expressoes. \n - Qualquer calculo falha apos as 10 casas decimais. \n\n R: ");
			do { scanf("%d",&k); } while((k<0 || k>10) && k!=42 && k!=55);
			printf("\n\n %d",k);
			if(k>0 && k<10) {
				printf(" - ");
				if(k==1) { printf("BHASKARA: \n Opera com Funcoes Constantes (K) e de 1o (primeiro - afim) e 2o (segundo - quadratica) grau, recebendo os dados invariavelmente nessa forma. \n Calcula dados relacionados a Equacao e ao Grafico da Funcao."); }
				if(k==2) { printf("COLLATZ: \n Por repeticao, encontra o numero de operacaes necessarias para retornar ao 1 o numero inserido. \n Basicamente, procura o rastro das potencias de 2 e as segue."); }
				if(k==3) { printf("FIBONACCI: \n Soma os dois valores iniciais em sequencia, somente limitado pelas 10 casas decimais, a partir de quando a execucao falha."); }
				if(k==4) { printf("NUMERICO: \n Traduz numeros de diversas bases numericas, desde o Binario ate os 36 digitos, ou seja, todas as letras do alfabeto mais os algarismos hindoarabicos."); }
				if(k==5) { printf("PITAGORAS: \n Calcula triangulos retangulos inteiros de um determinado intervalo numerico."); }
				if(k==6) { printf("PRIMO: \n Testa se um numero e primo ou procura por numeros primos num determinado intervalo numerico."); }
				if(k==7) { printf("SOMATORIA: \n Soma os valores do Intervalo Numerico desejado."); }
				if(k==8) { printf("TEMPERATURA: \n Traduz temperaturas medidas em graus Fahrenheit (F) para Celsius (C) e Kelvin (K), e vice-versa."); }
				if(k==9) { printf("CALCULADORA SIMPLES: \n Meramente uma calculadora comum, calculando as quatro operacoes basicas (soma e subtracao, multiplicacao e divisao)."); }
				printf("\n\n ");
			}
			if(k==10) {
				printf("\n Descricao dos Programas: \n\n 1 - BHASKARA: \n Opera com Funcoes Constantes (K) e de 1o (primeiro - afim) e 2o (segundo - quadratica) grau, recebendo os dados invariavelmente nessa forma. \n Calcula dados relacionados a Equacao e ao Grafico da Funcao. \n\n 2 - COLLATZ: \n Por repeticao, encontra o numero de operacaes necessarias para retornar ao 1 o numero inserido. \n Basicamente, procura o rastro das potencias de 2 e as segue. \n\n 3 - FIBONACCI: \n Soma os dois valores iniciais em sequencia, somente limitado pelas 10 casas decimais, a partir de quando a execucao falha. \n\n 4 - PITAGORAS: \n Calcula triangulos retangulos inteiros de um determinado intervalo numerico. \n\n 5 - PRIMO: \n Testa se um numero e primo ou procura por numeros primos num determinado intervalo numerico. \n\n 6 - SOMATORIA: \n Soma os valores do Intervalo Numerico desejado. \n\n 7 - TEMPERATURA: \n Traduz temperaturas medidas em graus Fahrenheit (F) para Celsius (C) e Kelvin (K), e vice-versa. \n\n 8 - TRADUTOR: \n Traduz numeros de diversas bases numericas, desde o Binario ate os 36 digitos, ou seja, todas as letras do alfabeto mais os algarismos hindoarabicos. \n\n Retornar?? N=0 S=1 \n R: ");
				while(k>1 || k<0) { scanf("%d",&k); }
				if(k==1) { k = 11; }
			}
		} while((k<0 || k>10) && k!=42 && k!=55);
		while(k==1) {
			bhaskara();
			do {
				printf("\n\n REINICIAR BHASKARA ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
		}
		while(k==2) {
			collatz();
			do {
				printf("\n\n REINICIAR COLLATZ ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 2; }
		}
		while(k==3) {
			fibonacci();
			do {
				printf("\n\n REINICIAR FIBONACCI ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 3; }
		}
		while(k==4) {
			numerico();
			k = 2;
			do {
				printf("\n\n REINICIAR NUMERICO ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 4; }
		}
		while(k==5) {
			pitagoras();
			do {
				printf("\n\n REINICIAR PITAGORAS ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 5; }
		}
		while(k==6) {
			primo();
			do {
				printf("\n\n REINICIAR PRIMO ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 6; }
		}
		while(k==7) {
			somatoria();
			do {
				printf("\n\n REINICIAR SOMATORIA ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 7; }
		}
		while(k==8) {
			temperatura();
			do {
				printf("\n\n REINICIAR TEMPERATURA ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 8; }
		}
		while(k==9) {
			calc();
			do {
				printf("\n\n REINICIAR A CALCULADORA SIMPLES ???? N=0 S=1 R: ");
				scanf("%d",&k);
			} while(k>1 || k<0);
			if(k==1) { k = 9; }
		}
		if(k==42) { indi(); }
		if(k==55) { word(); }
	do {
		printf("\n\n Reiniciar Math ?????? \n\n N = 0 \n S = 1 \n\n R: ");
		scanf("%d",&k);
	} while(k>1 || k<0);
} while(k==1);
return 0;
}
