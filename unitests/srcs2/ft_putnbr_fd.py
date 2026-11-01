#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strmapi.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 16:10:37 by marisous          #+#    #+#              #
#    Updated: 2026/11/01 16:10:37 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

import random
import string
import subprocess
import time
import os

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
    expected = str(n)
    o = random.randint(1,6)

    filename = None
    if o == 1 or o == 2:
        command1 = ["./run_putnbr_fd", str(o), str(n)]
        result = subprocess.run(command1,
            capture_output=True,
            text=True
            )
        if o == 1:
            actual = result.stdout
        else:
            actual = result.stderr
    else:
        filename = subprocess.run(
            ["./run_putnbr_fd", str(o), str(n)],
            capture_output=True,
            text=True
            ).stdout
        f = open(filename,'r')
        actual = f.read()
        f.close()
        os.remove(filename)

        

    if actual != expected or debug: 
        print(f"test_number: {i}")
        print("$ ./run_putnbr_fd" + " " + str(o) + " " + str(n));
        print(f"string: {str(n)!r}")
        print(f"option: {str(o)!r}")
        print(f"expected: {expected!r}")
        print(f"received: {actual!r}")
        if actual != expected:
            break
else:
    print(f"{Ntests} tests passed")    
