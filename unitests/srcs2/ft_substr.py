#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_substr.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/30 13:16:47 by marisous          #+#    #+#              #
#    Updated: 2026/10/30 17:40:08 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

import random
import string
import subprocess

debug = False

for i in range(10000):
    chars = ''.join(chr(i) for i in range(0x21, 0x7f))
    chars = string.ascii_letters + string.digits + string.punctuation.replace('"', '')
    chars += ' \t\n\v\f\r'
    # s = ''.join(random.choices(string.printable, k=random.randint(0, 100)))
    s = ''.join(random.choices(chars, k=random.randint(0, 10)))
    start = random.randint(0, 120)
    length = random.randint(0, 120)
    
    expected = s[start:start + length]

    result = subprocess.run(
        ["./run_substr", str(start), str(length), '"',s,'""'],
        capture_output=True,
        text=True
    )


    actual = result.stdout.rstrip("\n")

    if actual != expected or debug: 
        print("FAIL")
        print("./run_substr"+" "+str(start)+" "+str(length)+" "+ s);
        print(f"string: {s!r}")
        print(f"start:  {start}")
        print(f"len:    {length}")
        print(f"expected: {expected!r}")
        print(f"actual:   {actual!r}")
        break
else:
    print("10000 tests passed")    
