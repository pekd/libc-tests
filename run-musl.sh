#!/bin/sh

total=0
ok=0
failed=0

for i in `seq 0 26`; do
	total=$(($total + 1))
	echo "Running test $i..."
	llin musl-tests.bc $i
	if [ $? != 0 ]; then
		echo "Test $i failed"
		failed=$(($failed + 1))
	else
		ok=$(($ok + 1))
	fi
done

echo "$ok ok, $failed failed, $total total"
