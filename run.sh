g++ practiceHashCode.cpp -o practiceHashCode
for i in c d; do
    echo $i
    "/Users/soumyaranjantripathy/All CC Code/"practiceHashCode <$i.in> $i.out
done