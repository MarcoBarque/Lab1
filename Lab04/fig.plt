set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'Figure.tex'

set border linewidth 6 

set ylabel '\textbf{Valor calculado de Pi} $S$'
set xlabel '\textbf{Número de hilos} $P$'

set ytics scale 2
set xtics scale 2

plot 'datosT.dat' u 1:2 w p pt 7 ps 2.5 lc rgb "red" t 'Escalabilidad \texttt{pi.py}',\
     
set output
system('latex Figure.tex')
system('dvips Figure.dvi')
system('ps2pdf Figure.ps')
system('rm Figure.tex Figure.log Figure.aux Figure-inc.eps Figure.dvi Figure.ps')
