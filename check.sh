# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chcoutur <chcoutur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:03:28 by chcoutur          #+#    #+#              #
#    Updated: 2019/10/07 12:03:44 by chcoutur         ###   ########.fr        #
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
	total=$(( $total + $new ))
	x=$(( $x + 1 ))
	done

clear
printf "On ${cyn}$max${end} tests : \n"
echo "With a range from ${red}$rmin${end} to ${grn}$rmax${end}\n"
echo "Average move =\t ${grn}$(( total / x ))${end}"

