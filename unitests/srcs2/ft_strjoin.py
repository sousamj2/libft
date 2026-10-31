#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_substr.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/30 13:16:47 by marisous          #+#    #+#              #
#    Updated: 2026/10/31 12:09:57 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

import random
import string
import subprocess

debug = False

for i in range(1000):
    chars = ''.join(chr(i) for i in range(0x21, 0x7f))
    chars = string.ascii_letters + string.digits + string.punctuation.replace('"', '')
    chars += r' \t\n\v\f\r'
    # s = ''.join(random.choices(string.printable, k=random.randint(0, 100)))
    s1 = ''.join(random.choices(chars, k=random.randint(0, 10)))
    s2 = ''.join(random.choices(chars, k=random.randint(0, 10)))
    
    expected = s1+s2

    result = subprocess.run(
        ["./run_strjoin", s1, s2],
        capture_output=True,
        text=True
    )


    actual = result.stdout.rstrip("\n")

    if actual != expected or debug: 
        print("FAIL")
        print("./run_substr"+" "+s1+" "+ s2);
        print(f"string 1: {s1!r}")
        print(f"string 2: {s2!r}")
        print(f"expected: {expected!r}")
        print(f"received: {actual!r}")
        break
else:
    print("1000 tests passed")    
