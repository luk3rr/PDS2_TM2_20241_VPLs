#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Usage: $0 <start> <end>"
	exit 1
fi

start=$1
end=$2

for ((i = start; i <= end; i++)); do
	echo "Running case ${i}..."
	bin/program <"test_cases/case${i}.in" >"test_cases/case${i}.out"
done
