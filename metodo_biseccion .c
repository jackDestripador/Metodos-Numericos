/* Metodo de la bisección

Cisneros Cantero jesus 23/03/2019
*/


#include<stdio.h>
#include<math.h>
double F(double);
void INPUT(int *OK, double *A, double *B, double *FA, double *FB, double *TOL, int *NO);

void main(){
	double A,FA,B,FB,C,P,FP,TOL;
	int I,NO,OK;
	INPUT(&OK, &A, &B, &FA, &FB, &TOL, &NO);
	if(OK){
		I=1;
		OK =1;
		while((I<=NO)&& OK){
			C=(B-A)/2.0;
			P=A+C;
			printf("%3d  %15.8e  \n",I,P,FP);
			if(abs(FP)<0 || (C<TOL)){
				printf("\n Solucion aproximada P= %11.8f \n",P);
				OK=0;	
			}	else{
			 		I++;
			 		if((FA*FP)>0.0){
			 		A=P;
			 		FA=FP; 		
				 }else{
				 	B=P;
				 	FB=FP;
				 }
			} 
		}
		if(OK){
			printf("\nLa iteracion %3d",NO);
			printf(" da la aproximacion %12.8f\n",P);
			printf("Fuera de la tolerancia aceptada \n");
		}
	}
getchar();
getchar();
}	


double F(double X){
	double f;
	return 	f = ( X + 4.0 ) * X * X - 10.0;
}
void INPUT(int *OK, double *A, double *B, double *FA, double *FB, double *TOL, int *NO){
	double X;
	*OK =0;
		while (!(*OK)) {
			printf("Dar el valor de A\n");
			scanf("%lf", A);
			printf("Dar el valor de B\n");
			scanf("%lf", B);
			if (*A > *B) {
				X = *A; *A = *B; *B = X;
			}
			if (*A == *B) 
			printf("A debe ser diferente de B\n");
				else {
					*FA = F(*A);
					*FB = F(*B);
					if (*FA*(*FB) > 0.0) 
					printf("F(A) y F(B) tienen el mismo signo\n");
					else *OK = 1;
				}
		}
	*OK = 0;
	while(!(*OK)) {
		printf("Dar la tolerancia\n");
		scanf("%lf", TOL);
	if (*TOL <= 0.0)
	 	printf("La tolerancia debe ser positiva\n");
	else *OK = 1;
	}
	*OK = 0;
	while (!(*OK)) {
	printf("Dar el numero de iteraciones maximo\n");
	scanf("%d", NO);
		if (*NO <= 0){
		
		 printf("Debe ser un numero natural\n");}
		else *OK =1;
	}
}
