#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""

command=(
    "./cat"
    )
sys_command=(
    "cat"
    )

tests=(
"FLAGS test_files/test_case_cat.txt"
"FLAGS no_file.txt"
)
flags=(
    "b"
    "e"
    "n"
    "s"
    "t"
    "v"
)
manual=(
"-n -b test_files/test_1_cat.txt"
"-s -n -e test_files/test_4_cat.txt"
"test_files/test_1_cat.txt -n"
"-n test_files/test_1_cat.txt"
"-n test_files/test_1_cat.txt test_files/test_2_cat.txt"
"-v test_files/test_5_cat.txt"
"-- test_files/test_5_cat.txt"
"-s test_files/test_1_cat.txt"
"-b -e -n -s -t -v test_files/test_1_cat.txt"
"-b test_files/test_1_cat.txt nofile.txt"
"-t test_files/test_3_cat.txt"
"-n test_files/test_2_cat.txt"
"no_file.txt"
)

gnu=(
"--squeeze-blank test_files/test_1_cat.txt"
"--number-nonblank test_files/test_4_cat.txt"
"test_files/test_1_cat.txt --number --number"
"-bnvste test_files/test_6_cat.txt"
"-T test_files/test_1_cat.txt"
"-E test_files/test_1_cat.txt"
"-vT test_files/test_3_cat.txt"
"--number test_files/test_2_cat.txt"
)
run_test() {
    param=$(echo $@ | sed "s/FLAGS/$var/")
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -q --log-file="${command[@]}".log ./"${command[@]}" $param > /dev/null
    leak=$(grep -ic -A10000 "LEAK SUMMARY:" "${command[@]}".log || true)
    leak2=$(grep -ic -A10000 "ERROR SUMMARY: [^0]" "${command[@]}".log || true)
    let "COUNTER++"
    if [ "$leak" -eq "0" ] && [ "$leak2" -eq "0" ]
    then
        let "SUCCESS++"
        echo "$COUNTER - Success $param"
    else
        let "FAIL++"
        echo "$COUNTER - Fail $param"
    fi
    rm -f "${command[@]}".log "${sys_command[@]}".log
}

echo "^^^^^^^^^^^^^^^^^^^^^^^"
echo "TESTS WITH NORMAL FLAGS"
echo "^^^^^^^^^^^^^^^^^^^^^^^"
printf "\n"
echo "#######################"
echo "MANUAL TESTS"
echo "#######################"
printf "\n"
for i in "${manual[@]}"
do
    var="-"
    run_test $i
done
printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "1 PARAMETER"
echo "======================="
printf "\n"

for var1 in "${flags[@]}"
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        run_test $i
    done
done
printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"
##############################
echo "^^^^^^^^^^^^^^^^^^^^^^^"
echo "TESTS WITH GNU FLAGS"
echo "^^^^^^^^^^^^^^^^^^^^^^^"
printf "\n"
FAIL=0
SUCCESS=0
COUNTER=0
echo "======================="
echo "MANUAL TESTS"
echo "======================="
printf "\n"

for i in "${gnu[@]}"
do
    var="-"
    run_test $i
done

printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"