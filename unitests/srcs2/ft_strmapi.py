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
    o = random.randint(0,6)
    
    if o == 1: 
        expected = ''.join (c.lower() for c in s)
    elif o == 2:
        expected = ''.join (c.upper() for c in s)
    elif o == 3:
        expected = ''.join(
            c.upper() if i % 2 == 1
            else c.lower()
            for i, c in enumerate(s)
            )
    elif o == 4:
        expected = ''.join(
            c.upper() if i % 3 == 1
            else c.lower() if i % 3 == 2
            else c
            for i, c in enumerate(s)
            )
    else :
        expected = s
        
    result = subprocess.run(
        ["./run_strmapi", str(o), s],
        capture_output=True,
        text=True
    )
    actual = result.stdout # .splitlines()

    if actual != expected or debug: 
        print(f"test_number: {i}")
        print("$ ./run_strmapi" + " " + str(o) + " " + s);
        print(f"string: {s!r}")
        print(f"option: {str(o)!r}")
        print(f"result: [{result.stdout}]")
        print(f"expected: {expected!r}")
        print(f"received: {actual!r}")
        if not debug:
            break
else:
    print(f"{Ntests} tests passed")    
