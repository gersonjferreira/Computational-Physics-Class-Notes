reset

# using x:y (colunas do arquivo)
plot "dados1.dat" u 1:(sin($2)) title "teste" w lp
replot "dados1.dat" u 1:(sin($3)) title "teste 2" w lp


