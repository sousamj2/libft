#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_itoa.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 13:49:35 by marisous          #+#    #+#              #
#    Updated: 2026/11/01 13:49:35 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

import random
import string
import subprocess

debug = False

Ntests = 1000
if debug:
    Ntests = 10

for i in range(Ntests):
    n = random.randint(-2147483648,2147483647)
    if i == 0 : n = -2147483648
    if i == 1 : n = -2147483647
    if i == 2 : n = 2147483647
    if i == 3 : n = 2147483646
    if i == 4 : n = 42
    if i == 5 : n = 400
    if i == 6 : n = 420
    if i == 7 : n = -5
    if i == 8 : n = -5000
    if i == 9 : n = 0
    expected = "Correct."

    result = subprocess.run(
        ["./run_itoa", str(n)],
        capture_output=True,
        text=True
    )

    actual = result.stdout

    if actual != expected or debug: 
        print(f"\nTest_number: {i}")
        print("./run_itoa" + " " + str(n));
        print(f"Number: {n}")
        print(f"result: [{result.stdout}]")
        print(f"expected: {expected}")
        print(f"received: {actual}")
        if not debug:
            break
else:
    print(f"{Ntests} tests passed")    
