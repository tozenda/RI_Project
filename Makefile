index : rdjpeg.o prod_index.o
	gcc prod_index.o -o prod_index


prod_index.o :
	gcc -c prod_index.c 

rdjpeg.o :
	gcc -c rdjpeg.c 
