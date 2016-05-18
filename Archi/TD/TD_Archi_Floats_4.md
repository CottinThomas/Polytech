## 4.1

1		loop	lf F0, 0(R1)
2				lf R1, 400(R1)
3				addi R1, R1, 4
4				fmul F0, F0, F1
5									//1er cycle fmul
6									//2nd cycle fmul
7								//3rd cycle fmul
8				sf F0, 756(R1)
9				bne R1, R3, loop


## 4.4


1		loop 	lf F0, 0(R1)
2				lf F1, 400(R1)
3				lf F2, 4(R1)
4				lf F3, 404(R1)
5				fmul F0, F0, F1 
6				fmul F2, F2, F3
7				add R1, R1, 8
8
9				sf F0, 792(R1)
10				sf F2, 796(R1)
11				bne R1, R3, loop



## 4.8


// si i n'est pas paire, il reste potentiellement des itérations à faire...
int i;
for (i = 0; i < N-1; i+=2){
	S(i);
	S(i+1);
}
for( i ; i < N; i++)
	S(i);