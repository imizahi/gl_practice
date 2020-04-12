#include <stdlib.h>
#include <math.h>
#include <stdio.h>


void sinus ( int sample_rate, int wave_frequency, int amplitude,int sample_lenght){
	const float pi = 3.14;
	float period;
	float n;
	float buffer_s[sample_lenght];
	period =  sample_rate/wave_frequency/2;
        for(int a = 0; a<sample_lenght; a++){
		n = amplitude*sin(a*pi/period); 		
		buffer_s[a] = n;
		printf("%d",a);
		printf(",");
		printf("%f",buffer_s[a]);
		printf("\n");
	}
	//return *buffer_s;
}

void tri(int sample_rate, int wave_frequency, int amplitude,int sample_lenght){ 
	float period = sample_rate/wave_frequency/2; 
	int c = period*2;
	int c2 = -1;
	float sr_2m = period;
	float sr = sample_rate/wave_frequency/4;
	float buffer_t[sample_lenght];

for(int a = 0; a<sample_lenght; a++){
	if(c>sr_2m) c = sr_2m , c2 = -1;
	if(c<0) c = 0 , c2 = 1;
	buffer_t[a] = amplitude*(c/sr)-amplitude;
	c += c2;
	printf("%d",a);
	printf(",");
	printf("%f",buffer_t[a]);
	printf("\n");
	}
	//return *buffer_t;
}

/*void sum(float buffer_t[] , float buffer_s[] , int r1 , int r2){
	float buffer_sum[r2];	
	for(int a = r1; a < r2; a++){
		buffer_sum[a] = *buffer_t[a] + *buffer_s[a];
		printf("%f",buffer_sum[a]);	
	}
}*/
	
int main(){
int sample_rate, wave_frequency, amplitude, sample_lenght;
	printf("sample_rate");
	scanf("%d", &sample_rate);
	printf("wave_frequency");
	scanf("%d", &wave_frequency);
	printf("amplitude");
	scanf("%d", &amplitude);
	printf("sample_lenght");
	scanf("%d", &sample_lenght);
	sinus(sample_rate, wave_frequency, amplitude, sample_lenght);
	tri(sample_rate, wave_frequency, amplitude, sample_lenght);
//sum(a,b,30,200);
}


