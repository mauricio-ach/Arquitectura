# Programa que copia un registro dentro de otro
# sin utilizar la función pre establecida en mars
.data
	dato1 :  .word 10
	dato2:  .word 0		

.text
	lw $t0 , dato1	
	lw $t1 , dato2	
	add $t2 $t0 $t1	
