#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strmapi.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 16:10:37 by marisous          #+#    #+#              #
#    Updated: 2026/11/03 11:12:01 by marisous         ###   ########.fr        #
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

    filename = None

    output = subprocess.run(
        ["./run_charlist"],
        capture_output=True,
        text=True
        ).stdout.splitlines()
    filename = output[0]
    f = open(filename,'r')
    actual = f.read().splitlines()
    
    if actual != output[1:] or debug: 
        print(f"test_number: {i}")
        print("$ ./run_charlist");
        print(f"expected: {output}")
        print(f"received: {actual}")
        if not debug:
            break
        
    f.close()
    os.remove(filename)
else:
    print(f"{Ntests} tests passed")    
