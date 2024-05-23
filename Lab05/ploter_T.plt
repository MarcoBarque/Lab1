set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'FigureT.tex'

set border linewidth 6 

set ylabel '\textbf{Velocidad de operacion}'
set xlabel '\textbf{Número de threads} $i$'

set ytics scale 2
set xtics scale 2

f(x) = x

plot 'datosT.dat' u 1:2 w p pt 7 ps 2.5 lc rgb "blue" t 'Escalabilidad \texttt{matmultmkl.cpp}',\
     f(x) w l lw 3 lc rgb "blue" t 'Escalabilidad Lineal'     



set output
system('latex FigureT.tex')
system('dvips FigureT.dvi')
system('ps2pdf FigureT.ps')
system('rm FigureT.tex FigureT.log FigureT.aux FigureT-inc.eps FigureT.dvi FigureT.ps')
