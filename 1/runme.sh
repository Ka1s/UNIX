./script
./1 fileA fileB
gzip -c fileA > fileA.gz
gzip -c fileB > fileB.gz
gzip -cd fileB.gz | ./1 fileC
./1 fileA fileD 100
stat fileA
stat fileA.gz
stat fileB
stat fileB.gz
stat fileC
stat fileD