set terminal png
set output "hist.png"

set ylabel "Częstość występowania"
set xlabel "Cyfra"

set boxwidth 0.9 relative
set style fill solid 1.0

f(x) = log10(1+1/x)

plot "gnuData.dat" using 1:2 with boxes title "Dane wyników", f(x) lw 2 title "Prawo Benforda"