clean:
	rm -rf out
	mkdir out

seq:
	gcc -o ./out/out pySeriesSeq.c -fopenmp

naiveA:
	gcc -o ./out/out pySeriesNaiveA.c -fopenmp

naiveD:
	gcc -o ./out/out pySeriesNaiveD.c -fopenmp

naiveF:
	gcc -o ./out/out pySeriesNaiveF.c -fopenmp

naiveG:
	gcc -o ./out/out pySeriesNaiveG.c -fopenmp

naiveH:
	gcc -o ./out/out pySeriesNaiveH.c -fopenmp

alt:
	gcc -o ./out/out pySeriesAlt.c -fopenmp