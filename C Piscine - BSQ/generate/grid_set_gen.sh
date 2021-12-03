#!/bin/bash

rm -rf set
mkdir set

for i in `seq 1 10`;
do
        ./grid_generator.perl 12 9 4 > set/grid_$i
done
