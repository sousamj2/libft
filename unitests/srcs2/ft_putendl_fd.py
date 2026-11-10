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
    chars = r''.join(chr(i) for i in range(0x30, 0x7a))
    chars = string.ascii_letters + string.digits + string.punctuation.replace('"', '')
    # print(chars)
    # chars += r' \t\n\v\f\r'
    s = ''.join(random.choices(chars, k=random.randint(0, 1000)))
    o = random.randint(1,6)
    expected = s + '\n'

    filename = None
    if o == 1 or o == 2:
        command1 = ["./run_putendl_fd", str(o), s]
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
            ["./run_putendl_fd", str(o), s],
            capture_output=True,
            text=True
            ).stdout
        f = open(filename,'r')
        actual = f.read()
        f.close()
        os.remove(filename)

        

    if actual != expected or debug: 
        print(f"test_number: {i}")
        print("$ ./run_putendl_fd" + " " + str(o) + " " + s);
        print(f"string: {s!r}")
        print(f"option: {str(o)!r}")
        print(f"expected: {expected!r}")
        print(f"received: {actual!r}")
        if not debug:
            break
else:
    print(f"{Ntests} tests passed")    
