# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_script.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 09:03:09 by jleblond          #+#    #+#              #
#    Updated: 2019/11/25 09:03:11 by jleblond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

red=$'\e[1;31m'
grn=$'\e[1;32m'
yel=$'\e[1;33m'
blu=$'\e[1;34m'
mag=$'\e[1;35m'
cyn=$'\e[1;36m'
end=$'\e[0m'

printf "Range min ? : "
read rmin
printf "Range max ? : "
read rmax

x=1
total=0
new=0
max=100
checker_good="OK\n"
error_info="All Good\n"

progressbar()
{
	bar="##################################################"
	barlength=${#bar}
	n=$(($1*barlength/100))
	printf "\r[%-${barlength}s (%d%%)] " "${bar:0:n}" "$1"
}

while [ $x -le $max ]
do
	progressbar $x

	new=$(ARG=`ruby -e "puts ($rmin..$rmax).to_a.shuffle.join(' ')"` && ./push_swap $ARG | wc -l )
	checker_good = read $(./push_swap $ARG | ./checker $ARG)
	if [[ $checker_good != "OK\n" ]]; then
		error_info="Certain test failed\n"
	fi
	total=$(( $total + $new ))
	x=$(( $x + 1 ))
	done

clear
printf "On ${cyn}$max${end} tests : \n"
echo "With a range from ${red}$rmin${end} to ${grn}$rmax${end}\n"
echo "Average move =\t ${grn}$(( total / x ))${end}"
echo $error_info
