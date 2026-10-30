#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_substr.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/30 13:16:47 by marisous          #+#    #+#              #
#    Updated: 2026/10/30 14:25:57 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

import subprocess

result = subprocess.run(
    ["./run_substr", "Hello World", "6", "5"],
    capture_output=True,
    text=True
)

c_result = result.stdout.rstrip("\n")
python_result = "Hello World"[6:6 + 5]

if python_result in c_result :
    print("FAIL")
else:
    print("OK")
