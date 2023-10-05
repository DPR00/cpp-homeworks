wc -l < data.dat
grep -c 'dolor\|dalor' data.dat
wc -w < data.dat
grep -cE '\b(mol|mol\w*)\b' data.dat