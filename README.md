<p align="center">
  <img src="https://raw.githubusercontent.com/ridaelfagrouch/push_swap_42/main/assets/push_swap.png" alt="Push_swap 42 project badge"/>
</p>

Push_swap is a 42 School algorithm project where we aim to sort a given list of random numbers using a limited set of instructions, striving to achieve the minimum number of actions.

## ✨ Usage

Clone the repository
```Bash
git clone git@github.com:alexhiguera/Push_swap.git
```

Download the dependencies:
```BASH
git submodule init
git submodule update
```
execute Makefile
```BASH
make
```
Then run:
```Bash
./push_swap <numbers>
```
The provided numbers can be positive or negative integers, and duplicates are not allowed. For example:
```Bash
./push_swap 6 0 -8776 2147483647 -2147483648
```
If the arguments are valid, the program will display the most efficient list of actions to sort the list.

The program can be verified using the provided checker in the following manner:
```Bash
ARG="5 7 9 2 -4"; ./push_swap $ARG | ./tests/checker_Mac $ARG
```

## 🔎 Control tests

I have created rules in the Makefile to verify the correct functioning of the program.

🧮 **Interactive test**
```BASH
make test
```
🛹 **Stress test**
```BASH
make exec
```

🎯 **Norminette test**
```BASH
make normi
```

## 📏 Reglas y la calificacón

The program can only work with two stacks, Stack A and Stack B. All numbers are initially added to Stack A, while Stack B is empty.

The possible actions are:

|	Rules			|	Definition																												|
|-------------------|---------------------------------------------------------------------------------------------------------------------------|
|	``pa`` 			| (push A): Take the first element at the top of stack B and place it at the top of stack A. Do nothing if stack B is empty.|
|	``pb``			| (push B): ake the first element at the top of stack A and place it at the top of stack B. Do nothing if stack A is empty.	|
|	``sa``			| (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there's only one or no elements.					|
|	``sb``			| (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there's only one or no elements.					|
|	``ss``			| ``sa`` and ``sb`` at the same time.																						|
|	``ra`` 			| (rotate A): Shift all elements of stack A up by 1. The first element becomes the last.									|
|	``rb``			| rotate B): Shift all elements of stack B up by 1. The first element becomes the last."									|
|	``rr``			| ra y rb at the same time.																									|
|	``rra``			| (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first.							|
|	``rrb``			| (reverse rotate B): Shift all elements of stack B down by 1. The last element becomes the first.							|
|	``rrr``			| ``rra`` and ``rrb`` at the same time.																						|

## 📝 Evaluation grade
The grading depends on how efficient the sorting process of the program is.

	
	Sorting 3 values: no more than 3 actions
	Sorting 5 values: no more than 12 actions


Sorting 100 values: rating from 1 to 5 points based on the number of actions:

	50 points for fewer than 700 actions
	40 points for fewer than 900 actions
	30 points for fewer than 1100 actions
	20 points for fewer than 1300 actions
	10 point for fewer than 1500 actions

Sorting 500 values: rating from 1 to 5 points based on the number of actions:

	50 points for fewer than 5500 actions
	40 points for fewer than 7000 actions
	30 points for fewer than 8500 actions
	20 points for fewer than 10000 actions
	10 point for fewer than 11500 actions
## 👓 VIsualizer
❕ You can visualize this push_swap algorithm in action with the [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).

## 📎 Dependencies

Libft: my own library with basic functions [libft_2.0](https://github.com/alexhiguera/Libft_2.0).