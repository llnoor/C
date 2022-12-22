LIB="cat"
#TEST="-s txt/text.txt txt/test_1_cat.txt"
TEST="-b test_files/test_1_cat.txt nofile.txt"

echo $TEST

# Основная часть (выполнение функции s21 и системной функции)
cat/s21_$LIB $TEST > test_s21.txt
$LIB $TEST > test_$LIB.txt

# Быстрая проверка
diff -s test_s21.txt test_$LIB.txt

# Сравнение текста в визуальном просмотрщике
#diff test_s21.txt test_$LIB.txt

# Сравнение в 16-ричном виде в визуальном просмотрщике
#hexdump test_s21.txt > test_s21_hex.txt
#hexdump test_$LIB.txt > test_$LIB_hex.txt
#opendiff test_s21_hex.txt test_$LIB_hex.txt
