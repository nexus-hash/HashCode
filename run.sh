g++ practiceHashCode.cpp -std=c++17 -o practiceHashCode
for i in c d; do
    echo $i
    ./practiceHashCode <$i.in> $i.out
done
