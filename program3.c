
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void prime_table(int prime_num){
	int i=2,j,p=0,primeflag;
	
	int primes[prime_num];
	while(p<prime_num)
	{
		primeflag=1;
		for(j=2;j<i;j++){
			if((i%j)==0){
				primeflag=0;
				break;
			}
		}
		if(primeflag){
			primes[p]=i;
			p+=1;
		}
		i+=1;
	}
	for(int y=0;y<prime_num;y++){
				printf("%d\n",primes[y]);
			}
}

void sine_table(int sine_num){
	int i,j;
	double a,pi=3.14159;
	double sines[sine_num];
	for(i=0;i<sine_num;i++){
		sines[i]=sin(i);
	}
	for(int z=0;z<sine_num;z++){
				printf("%lf\n",sines[z]);
			}
}

int main(){
	int size;
	scanf("%d",&size);
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			prime_table(size);
			
		}
		#pragma omp section
		{
			sine_table(size);
		}
	}
	return 0;
}
