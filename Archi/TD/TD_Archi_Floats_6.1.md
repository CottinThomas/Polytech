# Division

## Sans déroulage
22 cycles
```
1	loop:	lf F0, 0(R1)		// x[i]
2			lf F1, 400(R1)		// y[i]
3			fdiv F0, F0, F31 	// x*a
4			addi R1, R1, 4		// latence fdiv (add autorisé)
5								// latence fdiv
6								// latence fdiv
7								// latence fdiv
8								// latence fdiv
9								// latence fdiv
10								// latence fdiv
11								// latence fdiv
12								// latence fdiv
13								// latence fdiv
14								// latence fdiv
15								// latence fdiv
16								// latence fdiv
17								// latence fdiv
18			fadd F0, F0, F1
19								// latence fadd
20								// latence fadd
21			sf F0, 796(R1) 		// R1 déja incrémenté
22			bne R1, R3, loop
```

## Déroulage de 2

```
1	loop:	lf F0, 0(R1)		// x[i]
2			lf F1, 400(R1)		// y[i]
3			lf F2, 4(R1)		// x[i+1]
4			lf F3, 404(R1)		// y[i+1]
5			fdiv F0, F0, F31	// 
6			addi R1, R1, 8		// latence fdiv
7								// latence fdiv
8								// latence fdiv
9								// latence fdiv
10								// latence fdiv
11								// latence fdiv
12								// latence fdiv
13								// latence fdiv
14								// latence fdiv
15								// latence fdiv
16								// latence fdiv
17								// latence fdiv
18								// latence fdiv
19								// latence fdiv
20			fdiv F2, F2, F31	// latence fdiv F2
21								// latence fdiv
22								// latence fdiv
23								// latence fdiv
24								// latence fdiv
25								// latence fdiv
26								// latence fdiv
27								// latence fdiv
28								// latence fdiv
29								// latence fdiv
30								// latence fdiv
31								// latence fdiv
32								// latence fdiv
33								// latence fdiv
34								// latence fdiv
35			fadd F0, F0, F1
36			fadd F2, F2, F3
37
38			sf F0, 792(R1)
39			sf F2, 796(R1)
40			bne R1, R3, loop
```

# Multiplication

## Sans déroulage
12 cycles
```
1	loop:	lf F0, 0(R1)		// x[i]
2			lf F1, 400(R1)		// y[i]
3			fmul F0, F0, F31 	// x*1/a
4			addi R1, R1, 4		// latence fmul (add autorisé)
5								// latence fmul
6								// latence fmul
7								// latence fmul
8			fadd F0, F0, F1
9								// latence fadd
10								// latence fadd
11			sf F0, 796(R1) 		// R1 déja incrémenté
12			bne R1, R3, loop
```

## Déroulage de 2
15 cycles
```
1	loop:	lf F0, 0(R1)		// x[i]
2			lf F1, 400(R1)		// y[i]
3			lf F2, 4(R1)		// x[i+1]
4			lf F3, 404(R1)		// y[i+1]
5			fmul F0, F0, F31 	// x*1/a
6			fmul F2, F2, F31	// latence fmul F0 (fmul autorisé car pipelinable (pas les meme données))
7			addi R1, R1, 8		// latence fmul F0 + F2
8								// latence fmul F0 + F2
9								// latence fmul F0 + F2
10			fadd F0, F0, F1 	// latence fmul F2
11			fadd F2, F2, F3		// latence fadd F0
12								// latence fadd F0 + F2
13			sf F0, 792(R1) 		// lattence fadd F2 	R1 déja incrémenté
14			sf F2, 796(R1)
15			bne R1, R3, loop
```