#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float fonk_dif(float x_0_d,int us,int A[100],int dx);
float fonk_calc(int us,float x_0,int A[100]);
float newt_rap_eq(float x_bas,int us,int A[100],int dx);
float newton_rap(int Epsilon,float x_1,int us,int A[100],int dx);

int main(int argc, char *argv[]) {
	float result,x_1,Epsilon,dx;
	int n,i;
	printf("Enter the power of polynom: ");
    scanf("%d",&n);
    int A[n+1];
    
    
    for(i=0;i<=n;i++){
        printf("Enter the X^%d. coefficinet: \n",i);
        scanf("%d",&A[i]);
    }
    for(i=0;i<=n;i++){
        printf("X^%d coef.: %d\n",i,A[i]);
    }
    printf("\nX_1: ");
    scanf("%f",&x_1);
	printf("\nEnter an Epsilon value: ");
    scanf("%f",&Epsilon);
    printf("\nEnter an dx value for differantial calculation : ");
    scanf("%f",&dx);
	
	result=newton_rap(Epsilon,x_1,n,A,dx);
	if(result==2){
		printf("Function is growing.");
		
	}
	else{
		printf("Root of function: %f",result);
	}
	
	
	system("PAUSE");
	return 0;
}
float newton_rap(int Epsilon,float x_1,int us,int A[100],int dx){
	float x_new,x_1F,x_newF,control_Fx ,x_control;
	float *x_newp;	
	int n,i,b,counter=0,control_accelerate=0;
 	 x_1F=fonk_calc(x_1,us,A);
  	 x_new = newt_rap_eq(x_1,us,A,dx);	
	 x_newp=&x_new;
	 control_Fx= -100;
 	while(control_Fx <= Epsilon && counter <=150  && control_accelerate<=20){
 		
 		x_control = x_newF;
 		*x_newp = newt_rap_eq(x_1,us,A,dx);		
 		x_newF= fonk_calc(*x_newp,us,A);
 		control_Fx = fabs((x_1F)-(x_newF));
 		++counter;
 		if(x_control>x_newF){
 			++control_accelerate;
		 }
	 }
if(control_accelerate>=20){
 return	2;
	
}
else{
	return *x_newp;
}	
	
}

float fonk_dif(float x_0_d,int us,int A[100],int dx){
	
	float main_dif= (fonk_calc(us,x_0_d+dx,A)-fonk_calc(us,x_0_d-dx,A))/2*dx ;
	return main_dif;
}

float newt_rap_eq(float x_bas,int us,int A[100],int dx){
 		float x_2= x_bas - (fonk_calc(x_bas,us,A)/fonk_dif(x_bas,us,dx,A));
 		return x_2;
	 }	

float fonk_calc(int us,float x_0,int A[100]){
    	float sum = 0;
    	int b;
 	for(b=0;b<=us;b++){
    	sum = sum + A[b]*pow(x_0,b);
 	}
 	return sum;
 }
