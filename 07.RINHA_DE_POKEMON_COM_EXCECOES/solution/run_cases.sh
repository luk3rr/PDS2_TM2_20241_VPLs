#!/bin/bash

# Script para rodar os testes de um intervalo de casos e gerar
# o arquivo vpl_evaluate.cases para o VPL

if [ "$#" -ne 2 ]; then
	echo "Usage: $0 <start> <end>"
	exit 1
fi

start=$1
end=$2

function run_cases {
	for ((i = start; i <= end; i++)); do
		echo "Running case ${i}..."
		bin/program <"test_cases/case${i}.in" >"test_cases/case${i}.out"
	done
}

function create_evaluate_cases {
	# Clear file
	> "test_cases/vpl_evaluate.cases"

	for ((i = start; i <= end; i++)); do
		echo "case = ${i}" >> "test_cases/vpl_evaluate.cases"
		echo "input =" >> "test_cases/vpl_evaluate.cases"

		cat "test_cases/case${i}.in" >> "test_cases/vpl_evaluate.cases"
		echo "" >> "test_cases/vpl_evaluate.cases"

		echo "output =" >> "test_cases/vpl_evaluate.cases"

		cat "test_cases/case${i}.out" >> "test_cases/vpl_evaluate.cases"
		echo "" >> "test_cases/vpl_evaluate.cases"
	done
}

run_cases
create_evaluate_cases
