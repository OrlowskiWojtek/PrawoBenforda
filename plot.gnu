set terminal png
set output "hist.png"

set ylabel "Częstość występowania"
set xlabel "Cyfra"

set style fill solid 0.5
set style data histogram
set boxwidth 0.5 relative
set style histogram cluster gap 0.2


f(x) = log10(1+1/x)


plot "gnuData.dat" using 1:2 with boxes title "Dane wyników", f(x) lw 2 title "Prawo Benforda"#, "gnuData.dat" using 1:(abs($2-(f($1)))) with boxes title "Różnica"