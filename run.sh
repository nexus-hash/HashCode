g++ practiceHashCode.cpp -std=c++17 -o practiceHashCode
for i in d e; do
    echo $i
    ./practiceHashCode <$i.in> $i.out
done
