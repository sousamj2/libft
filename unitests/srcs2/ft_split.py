#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_split.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/31 23:56:49 by marisous          #+#    #+#              #
#    Updated: 2026/11/08 15:50:28 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

import random
import string
import subprocess

debug = False

Ntests = 1000
if debug:
    Ntests = 1

for i in range(Ntests):
    # chars = ''.join(chr(i) for i in range(0x21, 0x7f))
    chars = r''.join(chr(i) for i in range(0x30, 0x7a))
    chars = string.ascii_letters + string.digits # + string.punctuation.replace('"', '')
    # print(chars)
    # chars += r' \t\n\v\f\r'
    s = ''.join(random.choices(chars, k=random.randint(0, 100)))
    c = random.choice(chars)

    s = "aaa"
    c = 'a'
    
    expected = [x for x in s.split(c) if x]

    result = subprocess.run(
        ["./run_split", s, c],
        capture_output=True,
        text=True
    )

    actual = result.stdout.splitlines()

    if actual != expected or debug: 
        print(f"FAIL: {i}")
        print("./run_split" + " " + s + " " + c);
        print(f"string: {s!r}")
        print(f"separator: {c!r}")
        print(f"result: [{result.stdout}]")
        print(f"expected: {expected!r}")
        print(f"received: {actual!r}")
        # if not debug:
        exit(1)
else:
    print(f"{Ntests} tests passed")    
