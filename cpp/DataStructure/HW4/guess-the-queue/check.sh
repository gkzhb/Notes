while
	echo "start"
	# ./mk.out
	./guess2.out
	./guess-the-queue.out < input.in
	diff 1.out 2.out
do :; done

